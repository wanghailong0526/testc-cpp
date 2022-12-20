//
// Created by 王海龙 on 2022/9/1.
//
/**
 * mmap 读写文件
 * android8.0上mmap出现错误，要使用mmap64()
 * 传统 I/O 方式 写文件 1.用户空间拷贝到内核空间 2.内核空间拷贝到磁盘
 * 粗看起来mmap少了一次拷贝，理论上比read要快。
 * 但是，调用mmap后并不会真实将文件加载到内存，
 * 因此在读写过程中（特别是大文件）会触发大量中断，导致性能降低，
 * 就算使用madvise调用加速参数都没有用。
 * 这里提供一个小方法，对文件每一页读取一下首字节
 */
#include "basefile.h"

void readFileMmapBuffer(const char *srcFilePath) {

}

/**
 * mmap读文件
 * @param srcFilePath
 */
void readFileMmap(const char *srcFilePath) {
    printf("\nrun %s/%s\n", __FILE_NAME__, __FUNCTION__);
    if (srcFilePath == NULL) {
        printf("srcFilePath is NULL\n");
        return;
    }
    //int open(const char * pathname, int flags);
    //int open(const char * pathname, int flags, mode_t mode);
    int fd = open(srcFilePath, O_RDONLY);//成功 fd从3开始，失败返回-1
    printf("fd=%d", fd);
    if (fd == -1) {
        printf("can't open file %s\n", srcFilePath);
        close(fd);
        return;
    }
    size_t size = getFileSizef(fd);
    //void *mmap(void *start, size_t length, int prot, int flags, int fd, off_t offsize);
//    void *addr = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd, 0);
    void *addr = MMAPREAD(size, fd, 0);
    close(fd);
    if (MAP_FAILED == addr) {//失败
        printf("mmap failed!");
        munmap(addr, size);
        return;
    }
    char *dest = MALLOC(size, char);
    // void *memcpy(void *dest, const void *src, size_t n);
    memcpy(dest, addr, size);//文件内容复制到 dest
    printf("%s\n", dest);
    free(dest);

    munmap(addr, size);
}

/**
 * mmap 写文件
 * @param destFilePath
 * @param content
 */
void writeFileMmap(const char *destFilePath, char *content) {
    printf("\nrun %s/%s\n", __FILE_NAME__, __FUNCTION__);
    if (destFilePath == NULL) {
        printf("FilePath is NULL\n");
        return;
    }
    int fd = open(destFilePath, O_RDWR | O_CREAT, S_IRWXU);
    if (-1 == fd) {
        printf("can't open file %s\n", destFilePath);
    }
    size_t size = strlen(content);
    ftruncate(fd, size);//mmap 不支持自动扩充文件，要先设置文件大小
    void *addr = MMAPWRITE(size, fd, 0);
    close(fd);
    if (MAP_FAILED == addr) {
        printf("mmap field!");
        munmap(addr, size);
        return;
    }
    memcpy(addr, content, size);

    munmap(addr, size);
}

int main(int argc, const char **argv) {
    char *path = "/Users/wanghailong/CLionProjects/testcpp/temp/hello.txt";
    char *destPath = "/Users/wanghailong/CLionProjects/testcpp/temp/write.txt";
    char *content = "来和我玩呀！918-485-483-2984359";
    writeFileMmap(destPath, content);
    readFileMmap(destPath);
}

