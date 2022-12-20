//
// Created by 王海龙 on 2021/4/5.
//运算符重载
#include <iostream>

using namespace std;

class Teacher {

private:
    int x;
    int y;

public:

//    Teacher(int x, int y) : x(x), y(y) {}

    Teacher(int x, int y) {
        this->x = x;
        this->y = y;
    }

    void setX(int x) {
        this->x = x;
    }

    void setY(int y) {
        this->y = y;
    }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    Teacher operator+(const Teacher &w1) {
        int x = this->x + w1.x;
        int y = this->y + w1.y;
        Teacher res(x, y);
        return res;
    }

    Teacher operator-(const Teacher &w) {
        this->x - w.x;
        this->y = w.y;
        return Teacher(x, y);
    }

    void operator++() {//++x
        this->x++;
        this->y++;
    }

    void operator++(int) {// x++
        this->x++;
        this->y++;
    }
};

int main() {
    Teacher whl1 = Teacher(1, 2);
    Teacher whl2{2, 3};
    Teacher whl3(3, 4);
    Teacher w1 = whl1 + whl2;
    cout << "whl1 + whl2=" << "x:" << w1.getX() << " y:" << w1.getY() << endl;

    const Teacher w2 = whl2 + whl3;
    cout << "whl2 + whl3=" << "x:" << w2.getX() << " y:" << w2.getY() << endl;

    whl1++;
    cout << "whl1++ =" << "x:" << whl1.getX() << " y:" << whl1.getY() << endl;
    ++whl1;
    cout << "++whl1 =" << "x:" << whl1.getX() << " y:" << whl1.getY() << endl;


    return 0;
}
