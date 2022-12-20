//
// Created by 王海龙 on 2022/8/28.
//
/**
 * 文件读写
 *
 * 1.打开文件
 * 两个参数 1_文件路径 2_读取模式  FILE *fopen( const char *filename, const char *mode );//例: FILE *fp = fopen(path,"r");
 * mode
 * 1.r ,以只读方式打开已有文件
 * 2.w , 打开文件并允许写入，若文件不存在则创建;若文件存在则清空原文件内容重新写入
 * 3.A , 打开文件追回内容，若文件不存在则创建;若文件存在则在原文件追回内容，不会破坏原文件
 * 4.r+ , 打开文件，允许读写，
 * 5.w+ , 打开文件允许读写，若文件不存在则创建;若文件存在则清空原文件内容重新写入
 * 6.A+ , 打开文件允许读写，若文件不存在则创建;若文件存在，从头读，从原文件末尾写入
 * 7.b , 上面的读取模式与b一起用意为以二进制方式操作文件
 * 8.+ , 若读写同时操作，在读写之间添加 rewind(fp) 将文件指针重置到开头 或使用 fseek(fp, 0, SEEK_SET);
 *
 * 2. 关闭文件
 *   int fclose( FILE *fp ); 成功返回 0 失败返回 EOF. 此函数会清空缓冲区数据，释放用于该文件的内存
 *
 * 3.写入文件
 *   1.写入字符 int fputc( int c, FILE *fp );把 字符 c 写入流中;执行结果 成功_返回写入的字符 失败_EOF
 *   2.写入字符串 int fputs( const char *s, FILE *fp );把字符串 s 写入 fp 指向的流中; 成功_返回非负数 失败_EOF
 *   3.写入字符串 int fprintf(FILE *fp,const char *format, ...);发送格式化输出到流 成功_正数 失败_负数
 *     例: fprintf(fp, "%s %s %s %d", "We", "are", "in", 2014);输出: We are in 2014
 *   4.以块的方式把数组写到流中 size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);返回写入个数，若返回值与 nmemb 不一致则报错
 *      int buff[50]; //缓冲区域
        int len = 0; //每次读到的数据长度
 *      fwrite(buff,sizeof(int),len,write_fp);
 *
 * 4.读文件
 *   1.读取单个字符 int fgetc( FILE * fp );成功_返回读取到的字符 失败_EOF
 *   2.读取字符串 char *fgets( char *buf, int n, FILE *fp ); 读取字符串放到 buff 缓冲区里,并在最后追回一个 null 字符来终止字符串。
 *      如果在读取到最后一个字符前就读取到了换行符 "\n" 或 EOF 则终止读取然后返回之前读取到的内容。
 *   3.读取字符串 int fscanf(FILE *fp, const char *format, ...);遇到第一个空格或换行符时，它会停止读取
 *   4.以块的方式读取到数组中(用于二进制文件读) size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);返回读取个数
 *      int buff[50]; //缓冲区域
 *      int len = 0; //每次读到的数据长度
 *      len = fread(buff, sizeof(int), 50, read_fp)) != 0
 *
 *
 * 文件路径 项目目录下 hello.txt
 */
#include <dirent.h>//文件目录
#include <stdio.h>
#include <stdlib.h>
#include <string.h>//函数strlen等
#include <sys/stat.h>


#define BUFFER_SIZE 64
#define R "r"
#define RB "rb"
#define W "w"
#define WB "wb"
#define APPEND "A"


/**
 * 获取文件夹内文件名字并转换为完整路径
 * @param dir
 */
void getDirFile(const char *dir) {
    printf("\nrun %s/%s\n", __FILE_NAME__, __FUNCTION__);
    if (dir == NULL) {
        printf("can't open dir\n");
        return;
    }
    DIR *dp;
    struct dirent *dirp;
    if ((dp = opendir(dir)) == NULL) {
        printf("Can't open %s\n", dir);
        closedir(dp);
        return;
    }
    char *tempfiledir = NULL;
    while ((dirp = readdir(dp)) != NULL) {
        if (strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0) { ///current dir OR parrent dir
            continue;
        }
        tempfiledir = (char *) malloc(sizeof(char) * (strlen(dir) + strlen(dirp->d_name)));
        strcpy(tempfiledir, dir);
        strcat(tempfiledir, dirp->d_name);
        printf("%s\n", tempfiledir);
        free(tempfiledir);
    }
    closedir(dp);
}

/**
 * 删除文件
 * @param filePath
 */
void removeFile(const char *filePath) {
    printf("\nrun %s/%s\n", __FILE_NAME__, __FUNCTION__);
    FILE *fp = NULL;
    if ((fp = fopen(filePath, R)) != NULL) {//文件存在
        remove(filePath);
    }
}

/**
 * 删除文件
 * 需要 #include <sys/stat.h>
 * @param filePath
 */
void removeFile2(const char *filePath) {
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
 * 获取文件扩展名
 * @param fileName
 * @return .txt
 */
char *getFileEXT(char *fileName) {
    printf("\nrun %s/%s\n", __FILE_NAME__, __FUNCTION__);
    char *p = NULL;
    p = strrchr(fileName, '.');//从后前查找第一个"."出现的位置并返回找到的字符串 找不到返回 NULL strchr是从前向后查看第一个出现的"."
    return p ? p : "";
}

//取得一个int的位数
int getLength(int num) {
    printf("\nrun %s/%s\n", __FILE_NAME__, __FUNCTION__);
    int n = num, count = 0;
    while (n) {
        count++;
        n /= 10;
    }
    return count;
}

/*******使用读取字符方式读文件 fgetc******/
void readFileChar(const char *filePath) {
    printf("\nrun %s/%s \n", __FILE_NAME__, __FUNCTION__);
    FILE *fp = NULL;
    if ((fp = fopen(filePath, R)) == NULL) {
        fclose(fp);
        printf("Could not open  file %s\n", filePath);
        return;
    }
    fseek(fp, 0, SEEK_SET);
    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
    //判断是什么原因结束的
    if (ferror(fp))
        puts("I/O error when reading");
    else if (feof(fp))
        puts("End of file reached successfully");

    fclose(fp);
}

/*******使用读取字符串方式读文件 fgets******/
void readFileStr(const char *filePath) {
    printf("\nrun %s/%s\n", __FILE_NAME__, __FUNCTION__);

    FILE *fp = NULL;
    if ((fp = fopen(filePath, R)) == NULL) {
        fclose(fp);
        printf("Couldn't open file %s\n", filePath);
        return;
    }
    //将文件指针指向文件头
//    rewind(fp);//将文件指针定位到文件头
    if (feof(fp)) {
        fseek(fp, 0, SEEK_SET);
    }
    char line[BUFFER_SIZE];//缓冲区大小
    while (fgets(line, BUFFER_SIZE, fp)) {
        printf("%s", line);
    }
    fclose(fp);
}

/*********以块的方式从流中将数据读取到数组中********/
void readFileBuffer(const char *filePath) {
    printf("\nrun %s/%s\n", __FILE_NAME__, __FUNCTION__);
    FILE *fp = NULL;
    if ((fp = fopen(filePath, R)) == NULL) {
        printf("Couldn't open file %s\n", filePath);
        fclose(fp);
        return;
    }
    char buffer[BUFFER_SIZE];
    int len = 0;
    while ((len = fread(buffer, sizeof(char), BUFFER_SIZE, fp))) {//!=0
        printf("%s", buffer);
    }
    if (feof(fp)) {
        printf("Error reading file %s unexpected end of file\n", filePath);
    } else if (ferror(fp)) {//测试给定流 stream 的错误标识符
        //把一个描述性错误消息输出到标准错误 stderr
        perror("Error reading file");
    }
    fclose(fp);
}

/*******使用写字符方式写文件 fgets******/
void writeFileChar(const char *filePath, char *content) {
    printf("\nrun %s/%s\n", __FILE_NAME__, __FUNCTION__);

    FILE *fp = NULL;
    if ((fp = fopen(filePath, W)) == NULL) {
        printf("Couldn't open file %s\n", filePath);
        fclose(fp);
        return;
    }
    /******这种方式也可以******/
//    int len = strlen(content);
//    int i = 0;
//    for (; i < len; ++i){
//        fputc(content[i], fp);
//    }
    while (*content) {
        fputc(*content, fp);
        content++;
    }
    fclose(fp);
}

/**********通过字符串方式写文件*********/
void writeFileStr(const char *filePath, char *content) {
    printf("\nrun %s/%s\n", __FILE_NAME__, __FUNCTION__);
    FILE *fp = NULL;
    if ((fp = fopen(filePath, W)) == NULL) {
        printf("Couldn't open file %s\n", filePath);
        fclose(fp);
        return;
    }
    fputs(content, fp);
    fclose(fp);
}

/*********以块的方式把数组写到流中********/
void writeFileBuffer(const char *filePath, char *content) {
    printf("\nrun %s/%s\n", __FILE_NAME__, __FUNCTION__);
    FILE *fp = NULL;
    if ((fp = fopen(filePath, W)) == NULL) {
        printf("Couldn't open file %s\n", filePath);
        fclose(fp);
        return;
    }
    fwrite(content, sizeof(char), strlen(content), fp);
    fclose(fp);
}

/*********以块的方式复制文件********/
void copyFile(const char *srcFilePath, const char *destFilePath) {
    printf("\nrun %s/%s\n", __FILE_NAME__, __FUNCTION__);
    FILE *rfp = NULL;//读文件
    FILE *wfp = NULL;//写文件
    if ((rfp = fopen(srcFilePath, RB)) == NULL) {
        printf("Couldn't open file %s\n", srcFilePath);
        fclose(rfp);
        return;
    }
    if ((wfp = fopen(destFilePath, WB)) == NULL) {
        printf("Couldn't open file %s\n", destFilePath);
        fclose(wfp);
        return;
    }
    char buffer[BUFFER_SIZE];//缓冲区
    int len = 0;//每次读到的数据长度
    while ((len = fread(buffer, sizeof(char), BUFFER_SIZE, rfp)) != 0) {
        fwrite(buffer, sizeof(char), len, wfp);
    }
    fclose(rfp);
    fclose(wfp);
}

//通过移动文件指针获取文件大小效率低下
long getFileSize(const char *filePath) {
    printf("\nrun %s/%s\n", __FILE_NAME__, __FUNCTION__);
    FILE *fp = NULL;
    if ((fp = fopen(filePath, R)) == NULL) {
        printf("Couldn't open file %s\n", filePath);
        fclose(fp);
        return -1;
    }
    fseek(fp, 0, SEEK_END);//文件指针移动到文件尾
    long size = ftell(fp);
    fclose(fp);
    return size;//字节
}

//#include <sys/stat.h> 效率高
size_t getFileSize2(const char *filePath) {
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
 * 文件加密
 * 使用异或的方式 1^1=0   1^0=1 相同为0，不同为1
 * @param srcFilePath 明文文件
 * @param destFilePath 加密后的文件
 * @param password
 */
void encryptFile(const char *srcFilePath, const char *destFilePath, const char *password) {
    printf("\nrun %s/%s\n", __FILE_NAME__, __FUNCTION__);
    FILE *rfp = NULL;//读文件
    FILE *wfp = NULL;//写文件
    if ((rfp = fopen(srcFilePath, R)) == NULL) {
        printf("Couldn't open file %s\n", srcFilePath);
        fclose(rfp);
        return;
    }
    if ((wfp = fopen(destFilePath, W)) == NULL) {
        printf("Couldn't open file %s\n", destFilePath);
        fclose(wfp);
        return;
    }
    int ch = 0;//一次读取一个字符
    int i = 0;//循环使用密码中的数据进行异或运算(加密)
    int pwdLen = strlen(password);
    while ((ch = fgetc(rfp)) != EOF) {//读
        fputc(ch ^ password[i % pwdLen], wfp);//加密写
        ++i;
    }
    fclose(rfp);
    fclose(wfp);
}

/**
 * 解密文件
 * @param srcFilePath 加密过的文件
 * @param destFilePath 解密后的文件
 * @param password
 */
void decryptFile(const char *srcFilePath, const char *destFilePath, const char *password) {
    printf("\nrun %s/%s\n", __FILE_NAME__, __FUNCTION__);
    FILE *rfp = NULL;//读文件
    FILE *wfp = NULL;//写文件
    if ((rfp = fopen(srcFilePath, R)) == NULL) {
        printf("Couldn't open file %s\n", srcFilePath);
        fclose(rfp);
        return;
    }
    if ((wfp = fopen(destFilePath, W)) == NULL) {
        printf("Couldn't open file %s\n", destFilePath);
        fclose(wfp);
        return;
    }
    int ch = 0;//一次读取一个字符
    int i = 0;//循环使用密码中的数据进行异或运算(加密)
    int pwdLen = strlen(password);
    while ((ch = fgetc(rfp)) != EOF) {//读
        fputc(ch ^ password[i % pwdLen], wfp);//解密写
        ++i;
    }
    fclose(rfp);
    fclose(wfp);
}

/**
 * 拆分文件
 * @param srcFilePath
 * @param splitFileNumber 拆分文件个数
 * @param parentPath 拆分文件路径
 */
void splitFile(char *srcFilePath, size_t splitFileNumber, char *parentPath) {
    printf("\nrun %s/%s\n", __FILE_NAME__, __FUNCTION__);
    if (srcFilePath == NULL) {
        printf("srcFilePath is NULL\n");
        return;
    }
    if (parentPath == NULL) {
        printf("parentPath is NULL\n");
        return;
    }
    size_t size = getFileSize2(srcFilePath);//原文件大小
    if (size / splitFileNumber <= 0) {
        printf("file size=%ld,can not split %ld files\n", size, splitFileNumber);
        return;
    }
    FILE *rfp = NULL;//读文件
    if ((rfp = fopen(srcFilePath, RB)) == NULL) {
        printf("Couldn't open file %s\n", srcFilePath);
        fclose(rfp);
        return;
    }
    size_t singleFileSize = size / splitFileNumber;//单个文件size
    size_t reminder = size % splitFileNumber;//拆分成filenumber个文件后还剩下多少内容
    size_t buffSize = sizeof(char) * singleFileSize;//malloc(buffSize)
    int tempFileLength = 0;//文件长度
    char *names = NULL;
    char *filePath = NULL;
    int len = 0;
    char *buffer = NULL;
    for (int i = 0; i < splitFileNumber; ++i) {
        //生成文件路径 ../temp/hello_1.txt
        tempFileLength = i + 1;
        names = (char *) malloc(sizeof(char) * getLength(tempFileLength));
        sprintf(names, "%d%s", tempFileLength, getFileEXT(srcFilePath));//1.txt
        printf("names=%s\n", names);
        filePath = (char *) malloc(sizeof(char) * (strlen(parentPath) + strlen(names)));
        strcat(filePath, parentPath);
        strcat(filePath, names);
        printf("filePath=%s\n", filePath);
        removeFile2(filePath);//若文件存在则删除

        FILE *wfp = NULL;//写文件
        if ((wfp = fopen(filePath, WB)) == NULL) {
            printf("Couldn't open file %s\n", filePath);
            fclose(wfp);
            break;
        }
        //最后一次循环
        if (i == splitFileNumber - 1) {//多余的内容放到最后一个文件
            buffSize += reminder;
            singleFileSize += reminder;
        }
        buffer = (char *) malloc(buffSize);
        len = fread(buffer, 1, singleFileSize, rfp);
        fflush(rfp);
        fwrite(buffer, 1, len, wfp);
        fflush(wfp);

        fclose(wfp);
        free(buffer);
        free(names);
        free(filePath);
    }
    fclose(rfp);
}

/**
 * 合并文件
 * @param mergeFilePath 要合并的文件的路径
 * @param filenumber 文件数量
 * @param destFilePath 合并后的文件路径
 */
void mergeFile(const char *mergeFilePath, size_t fileNumber, char *destFilePath) {
    printf("\nrun %s/%s\n", __FILE_NAME__, __FUNCTION__);
    if (mergeFilePath == NULL) {
        printf("mergeFilePath is NULL\n");
        return;
    }
    if (destFilePath == NULL) {
        printf("destFilePath is NULL\n");
        return;
    }
    FILE *wfp = NULL;//写文件
    if ((wfp = fopen(destFilePath, WB)) == NULL) {
        printf("Couldn't open file %s\n", destFilePath);
        fclose(wfp);
        return;
    }
    size_t singleFileSize = 0;//单个文件size
    size_t buffSize = 0;//malloc(buffSize)
    int tempFileLength = 0;//文件长度
    char *names = NULL;
    char *filePath = NULL;
    int len = 0;
    char *buffer = NULL;
    int i = 0;
    for (; i < fileNumber; ++i) {
        //生成文件路径 ../temp/hello_1.txt
        tempFileLength = i + 1;
        names = (char *) malloc(sizeof(char) * getLength(tempFileLength));
        sprintf(names, "%d%s", tempFileLength, getFileEXT(destFilePath));//1.txt
        printf("names=%s\n", names);
        filePath = (char *) malloc(sizeof(char) * (strlen(mergeFilePath) + strlen(names)));
        strcat(filePath, mergeFilePath);
        strcat(filePath, names);
        printf("filePath=%s\n", filePath);

        FILE *rfp = NULL;//写文件
        if ((rfp = fopen(filePath, RB)) == NULL) {
            printf("Couldn't open file %s\n", filePath);
            fclose(rfp);
            break;
        }
        singleFileSize = getFileSize2(filePath);
        buffSize = sizeof(char) * singleFileSize;
        buffer = (char *) malloc(buffSize);
        len = fread(buffer, 1, singleFileSize, rfp);
        fflush(rfp);
        fwrite(buffer, 1, len, wfp);
        fflush(wfp);

        fclose(rfp);
        free(buffer);
        free(names);
        free(filePath);
    }
    fclose(wfp);
}

int main() {
    char *str = "我是王海龙!";
    char *dirPath = "../temp/";
    char *path = "../temp/hello.txt";

//    printf("size_t:%ld \n", sizeof(size_t));
//    printf("ssize_t:%ld \n", sizeof(ssize_t));

    /*********写文件********/
    writeFileChar(path, str);//写文件
//    writeFileStr(path, str);
//    writeFileBuffer(path, str);

    /*********读文件********/
//    readFileChar(path);
//    readFileStr(path);
//    readFileBuffer(path);

    /*********文件复制********/
//    char *srcPath = path;
//    char *destPath = "../temp/hello_new.txt";
//    copyFile(srcPath, destPath);
//    readFileBuffer(destPath);

    /*********文件大小********/
//    printf("原文件大小为:%ld\n", getFileSize(srcPath));
//    printf("复制文件大小为:%ld\n", getFileSize(destPath));
//    printf("复制文件大小为:%ld\n", getFileSizef(path));

    /*********文件加密、解密 使用二进制方式按字符一个一个读取********/
//    char *normalPath = path;//明文原文件
//    char *encPath = "../temp/hello_enc.txt";//加密后的文件
//    char *decPath = "../temp/hello_dec.txt";//解密后的文件
//    char *key = "password";
//    encryptFile(normalPath, encPath, key);//明文文件加密
//    decryptFile(encPath, decPath, key);//解密
//    encryptFile(encPath, decPath, key);//解密


    /*********文件拆分与合并********/
//    char *parentPath = "../temp/hello_";
//    char *destFilePath = "../temp/hello_merge.txt";
//    splitFile(path, 2, parentPath);
//    mergeFile(parentPath, 2, destFilePath);
//    printf("原文件大小为%ld\n", getFileSizef(path));
//    printf("合并后文件大小为%ld\n", getFileSizef(destFilePath));
//    printf("文件扩展名为:%s\n", getFileEXT(destFilePath));
//    getDirFile(dirPath);
}








