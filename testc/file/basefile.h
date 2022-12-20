//
// Created by 王海龙 on 2022/9/1.
//
/**
* 通过 mmap 读写文件
 *   粗看起来mmap少了一次拷贝，理论上比read要快。
 * 但是，调用mmap后并不会真实将文件加载到内存，
 * 因此在读写过程中（特别是大文件）会触发大量中断，导致性能降低，
 * 就算使用madvise调用加速参数都没有用。
 * 这里提供一个小方法，对文件每一页读取一下首字节
 *
* void *mmap(void *start, size_t length, int prot, int flags, int fd, off_t offsize);
* 1.start 指向欲对应的内存起始地址，通常设为NULL，代表让系统自动选定地址，对应成功后该地址会返回。
* 2.length 代表将文件中多大的部分对应到内存。
* 3.prot  代表映射区域的保护方式
        *  PROT_EXEC 映射区域可被执行
        *  PROT_READ 映射区域可被读取
        *  PROT_WRITE 映射区域可被写入
        *  PROT_NONE 映射区域不能存取
* 4.flags 会影响映射区域的各种特性
        *  MAP_FIXED  如果参数 start 所指的地址无法成功建立映射时，则放弃映射，不对地址做修正。通常不鼓励用此参数
        *  MAP_SHARED  对应射区域的写入数据会复制回文件内，而且允许其他映射该文件的进程共享
        *  MAP_PRIVATE  对应射区域的写入操作会产生一个映射文件的复制，即私人的"写入时复制" (copy on write)对此区域作的任何修改都不会写回原来的文件内容
        *  MAP_ANONYMOUS  建立匿名映射，此时会忽略参数fd，不涉及文件，而且映射区域无法和其他进程共享
        *  MAP_DENYWRITE  只允许对应射区域的写入操作，其他对文件直接写入的操作将会被拒绝
        *  MAP_LOCKED  将映射区域锁定住，这表示该区域不会被置换(swap)
* 5.fd open()返回的文件描述符，代表欲映射到内存的文件
* 6.offsize 文件映射的偏移量，通常设置为0，代表从文件最前方开始对应，offset必须是分页大小的整数倍。
* 若映射成功则返回映射区的内存起始地址，否则返回MAP_FAILED(-1)，错误原因存于errno 中。
*  错误代码：
*  EBADF  参数fd 不是有效的文件描述词。
*  EACCES  存取权限有误。如果是MAP_PRIVATE 情况下文件必须可读，使用MAP_SHARED 则要有PROT_WRITE 以及该文件要能写入。
*  EINVAL  参数start、length 或offset 有一个不合法。
*  EAGAIN  文件被锁住，或是有太多内存被锁住。
*  ENOMEM  内存不足
*
* open
* int open(const char * pathname, int flags);
* int open(const char * pathname, int flags, mode_t mode);
* 参数 pathname 指向欲打开的文件路径字符串
        * flags 所能使用的旗标:
*  O_RDONLY 以只读方式打开文件
*  O_WRONLY 以只写方式打开文件
*  O_RDWR 以可读写方式打开文件. 上述三种旗标是互斥的, 也就是不可同时使用, 但可与下列的旗标利用OR(|)运算符组合.
*  O_CREAT 若欲打开的文件不存在则自动建立该文件.
*  O_EXCL 如果O_CREAT 也被设置, 此指令会去检查文件是否存在. 文件若不存在则建立该文件, 否则将导致打开文件错误. 此外, 若O_CREAT 与O_EXCL 同时设置, 并且欲打开的文件为符号连接, 则会打开文件失败.
*  O_NOCTTY 如果欲打开的文件为终端机设备时, 则不会将该终端机当成进程控制终端机.
*  O_TRUNC 若文件存在并且以可写的方式打开时, 此旗标会令文件长度清为0, 而原来存于该文件的资料也会消失.
*  O_APPEND 当读写文件时会从文件尾开始移动, 也就是所写入的数据会以附加的方式加入到文件后面.
*  O_NONBLOCK 以不可阻断的方式打开文件, 也就是无论有无数据读取或等待, 都会立即返回进程之中.
*  O_NDELAY 同O_NONBLOCK.
*  O_SYNC 以同步的方式打开文件.
*  O_NOFOLLOW 如果参数pathname 所指的文件为一符号连接, 则会令打开文件失败.
*  O_DIRECTORY 如果参数pathname 所指的文件并非为一目录, 则会令打开文件失败。
*
*  注：此为Linux2. 2 以后特有的旗标, 以避免一些系统安全问题.
*
*  mode 则有下列数种组合, 只有在建立新文件时才会生效, 此外真正建文件时的权限会受到umask 值所影响, 因此该文件权限应该为 (mode-umaks).
*  S_IRWXU 00700 权限, 代表该文件所有者具有可读、可写及可执行的权限.
*  S_IRUSR 或S_IREAD, 00400 权限, 代表该文件所有者具有可读取的权限.
*  S_IWUSR 或S_IWRITE, 00200 权限, 代表该文件所有者具有可写入的权限.
*  S_IXUSR 或S_IEXEC, 00100 权限, 代表该文件所有者具有可执行的权限.
*  S_IRWXG 00070 权限, 代表该文件用户组具有可读、可写及可执行的权限.
*  S_IRGRP 00040 权限, 代表该文件用户组具有可读的权限.
*  S_IWGRP 00020 权限, 代表该文件用户组具有可写入的权限.
*  S_IXGRP 00010 权限, 代表该文件用户组具有可执行的权限.
*  S_IRWXO 00007 权限, 代表其他用户具有可读、可写及可执行的权限.
*  S_IROTH 00004 权限, 代表其他用户具有可读的权限
        *  S_IWOTH 00002 权限, 代表其他用户具有可写入的权限.
*  S_IXOTH 00001 权限, 代表其他用户具有可执行的权限.
*
*  返回值：若所有欲核查的权限都通过了检查则返回0 值, 表示成功, 只要有一个权限被禁止则返回-1.
*
*  错误代码：
*  EEXIST 参数pathname 所指的文件已存在, 却使用了O_CREAT 和O_EXCL 旗标.
*  EACCESS 参数pathname 所指的文件不符合所要求测试的权限.
*  EROFS 欲测试写入权限的文件存在于只读文件系统内.
*  EFAULT 参数pathname 指针超出可存取内存空间.
*  EINVAL 参数mode 不正确.
*  ENAMETOOLONG 参数 pathname 太长.
*  ENOTDIR 参数pathname 不是目录.
*  ENOMEM 核心内存不足.
*  ELOOP 参数pathname 有过多符号连接问题.
*  EIO I/O 存取错误.
*/

#ifndef TESTC_C_BASEFILE_H
#define TESTC_C_BASEFILE_H

#include <dirent.h>//文件目录
//open函数用到下面5个头文件
#include <sys/mman.h>//mmap操作
#include <sys/stat.h>//文件操作
#include <sys/types.h>
#include <sys/fcntl.h>
#include <unistd.h>

#include <string.h>//memcpy void *memcpy(void *dest, const void *src, size_t n);

#include <stdio.h>
#include <stdlib.h>//malloc

#define R "r"
#define RB "rb"
#define W "w"
#define WB "wb"
#define APPEND "A"

#define MALLOC(n, type) ((type*)malloc((n)*sizeof(type))) //使用此函数为任意类型分配指定大小空间兼容 C/C++
#define MMAPREAD(size, fd, offset) mmap(NULL,size,PROT_READ,MAP_PRIVATE,fd,offset) //mmap 读取文件
//mmap(0, m_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
#define MMAPWRITE(size, fd, offset) mmap(NULL,size,PROT_READ | PROT_WRITE,MAP_SHARED,fd,offset) //mmap 写文件

/**
 * 删除文件
 * 需要 #include <sys/stat.h>
 * @param filePath
 */
void removeFile(const char *filePath) {
    printf("\nrun %s/%s\n", __FILE_NAME__, __FUNCTION__);
    if (filePath == NULL) {
        return;
    }
    struct stat buff;
    if (stat(filePath, &buff) == 0) {//文件存在则删除
        remove(filePath);
    }
}

/**
 * 获取文件大小
 * @param filePath
 * @return
 */
size_t getFileSize(const char *filePath) {
    printf("\nrun %s/%s\n", __FILE_NAME__, __FUNCTION__);
    if (filePath == NULL) {
        return 0;
    }
    struct stat statbuf;//存储了文件(夹)信息的结构体，其中有文件大小，创建时间，访问时间，修改时候等
    stat(filePath, &statbuf);//通过文件(路径)获取文件属性结构体
    size_t size = statbuf.st_size;//获取文件大小
    return size;
}

/**
 * 获取文件大小
 * @param fileDes 文件描述符
 * @return
 */
size_t getFileSizef(const int fileDes) {
    printf("\nrun %s/%s\n", __FILE_NAME__, __FUNCTION__);
    struct stat statbuf;//存储了文件(夹)信息的结构体，其中有文件大小，创建时间，访问时间，修改时候等
    fstat(fileDes, &statbuf);//通过文件(路径)获取文件属性结构体
    size_t size = statbuf.st_size;//获取文件大小
    return size;
}


#endif //TESTC_C_BASEFILE_H
