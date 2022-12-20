//
// Created by 王海龙 on 2022/9/13.
//
/**
 * 模板类
 *
 */
template<class T>
class Err {
protected:
    T a;
public:
    Err(T a) {
        this->a = a;
    }
};

class FileNotFound : public Err<char *> {
private:
    int b;
public:
    //调用父类构造方法
    FileNotFound(char *a, int b) : Err<char *>(a) {
        this->b = b;
    }
};

int main() {

}

