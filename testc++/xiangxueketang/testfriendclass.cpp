//
// Created by 王海龙 on 2021/4/5.
//测试友元类
#include <iostream>

using namespace std;

class ImageView {
private:
    int size = 20;

    friend class Class;
};

class Class {
public:
    ImageView imageView;

    void changeViewSize(int size = 20) {
        imageView.size = size;
    }

    int getViewSize() {
        return imageView.size;
    }
};

int main(int argc, const char *argv[]) {
    Class imageViewClass;
    cout << "size :" << imageViewClass.getViewSize() << endl;

    imageViewClass.changeViewSize(30);
    cout << "size :" << imageViewClass.getViewSize() << endl;

}
