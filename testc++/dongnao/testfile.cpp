//
// Created by 王海龙 on 2022/9/14.
//
/**
 * 文件读写
 * 1.读写文本文件
 *      1.写文件  ofstream fout(filePath,ios_base::out); fout << content << endl; 写入数据
 *      2.读文件  ifstream fin(filePath, ios_base::in);  while(fin.get(char)){}循环读
 *
 * 2.读写二进制文件
 *      1.写文件  ofstream fout(filePath, ios::binary); fout.write(content,strlen(content));
 *      2.读文件  ifstream fin(filePath, ios::binary); while(!fin.eof()){fin.read(char buff[buffer_size],buffer_size)} 内容譸到了 buff 里
 *
 * 3.对象持久化
 *      1.写对象到磁盘
 *      2.读磁盘对象
 */
#include <iostream>
#include <fstream>

#define BUFFER_SIZE 1024

using namespace std;

class Human {
public:
    char *name;
    int age;
public:
    Human() {}

    Human(char *name, int age) {
        this->age = age;
        this->name = name;
    }

    Human(Human &human) {
        this->age = human.age;
        strcpy(this->name, human.name);
    }

    void print() {
        cout << "我是人类 name = " << name << " age = " << age << endl;
    }
};

template<class T>
bool wirteObject(const char *filePath, T &obj) {
    if (!filePath) {
        cout << "filePath is nuLL!" << endl;
        return false;
    }
    ofstream fout(filePath, ios_base::binary);
    if (fout.bad()) {
        cout << "can't open file  " << filePath << endl;
        return false;
    }
//    fout.write(reinterpret_cast<char *> (&obj), sizeof(obj));
    fout.write((char *) (&obj), sizeof(obj));
    fout.flush();
    fout.close();
    return true;
}

template<typename T>
void readObject(const char *filePath, T &obj) {
    if (!filePath) {
        cout << "filePath is nuLL!" << endl;
        return;
    }
    ifstream fin(filePath, ios_base::binary);
    if (fin.bad()) {
        cout << "can't open file  " << filePath << endl;
        return;
    }
//    fin.read(reinterpret_cast<char *>(&obj), sizeof(obj));//也可以
    fin.read((char *) (&obj), sizeof(obj));
    fin.close();
}

bool writeFile(const char *filePath, const char *content) {
    if (!filePath) {
        cout << "filePath is nuLL!" << endl;
        return false;
    }
    if (!content) {
        cout << "file content is nuLL!" << endl;
        return false;
    }
    ofstream fout(filePath, ios_base::out);
    if (fout.bad()) {
        cout << "can't open file  " << filePath << endl;
        return false;
    }
    fout << content << endl;
    fout.flush();
    fout.close();
    return true;
}

bool readFile(const char *filePath) {
    if (!filePath) {
        cout << "filePath is nuLL!" << endl;
        return false;
    }
    ifstream fin(filePath, ios_base::in);
    if (fin.bad()) {
        cout << "can't open file  " << filePath << endl;
        return false;
    }
    char c;
    while (fin.get(c)) {
        cout << c;
    }
    cout << endl;
    fin.close();
    return true;
}

bool writeFileBinary(const char *filePath, const char *content) {
    if (!filePath) {
        cout << "filePath is nuLL!" << endl;
        return false;
    }
    if (!content) {
        cout << "file content is nuLL!" << endl;
        return false;
    }
    ofstream fout(filePath, ios::binary);
    if (fout.bad()) {
        cout << "can't open file  " << filePath << endl;
        return false;
    }
    fout.write(content, strlen(content));
    fout.flush();
    fout.close();
    return true;
}

bool readFileBinary(const char *filePath, bool print) {
    if (!filePath) {
        cout << "filePath is nuLL!" << endl;
        return false;
    }
    ifstream fin(filePath, ios::binary);
    if (fin.bad()) {
        cout << "can't open file  " << filePath << endl;
        return false;
    }
    while (!fin.eof()) {
        char buff[BUFFER_SIZE] = {0};
        fin.read(buff, BUFFER_SIZE);
        if (print) {
            cout << buff;
        }
    }
    if (print) {
        cout << endl;
    }
    fin.close();
    return true;
}

int main(int argc, char **argv) {
    const char *filePathobj = "/Users/wanghailong/Downloads/obj";//文件路径
    const char *filePath = "/Users/wanghailong/Downloads/textcppfile.txt";//文件路径
    const char *content = "我是中国人！我家自己的祖国！每个人都应该热爱自己的国家！";
    //读写文本文件
//    writeFile(filePath, content);//写文件
//    readFile(filePath);//读文件

    //读写二进制文件
//    writeFileBinary(filePath, content);
//    readFileBinary(filePath, true);

    /******读写对象****/
    Human human;
    human.age = 10;
    char name[] = {'w', 'h', 'l', '\0'};
    human.name = name;
    cout << "human 的地址为: " << &human << endl;
    wirteObject(filePathobj, human);
    Human human1;
    char name1[] = {'h', 'h', 'h', '\0'};
    human1.age = 20;
    human.name = name1;
    readObject(filePathobj, human1);
    cout << "human1 的地址为: " << &human1 << endl;
    human1.print();
    /******读写对象****/
}
