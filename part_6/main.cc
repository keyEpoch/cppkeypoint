#include <iostream>
using namespace std;

class Father {
public:
    virtual void foo1() {
        cout << "Father foo1" << endl;
    }
    virtual void foo2() {
        cout << "Father foo2" << endl;
    }
    virtual void foo3() {
        cout << "Father foo3" << endl;
    }
};

class Son : public Father {
public:
    void foo1() override {
        cout << "Son foo1" << endl;
    }
};

int main() {
    Father father;
    Son son;

    // 父类和子类的虚表地址
    // 可以看到虚表首地址是不一样的，也就是说，每个类都有自己独享的虚表
    // 虚表中的内容就是函数的地址，内容可能一样，也可能不一样
    cout << "Father类的虚表地址：" << &father << endl;
    cout << "Son类的虚表地址：" << &son << endl;

    typedef void(*MyFunc)(void);

    // 取基类虚表中的函数地址
    MyFunc myfunc1 = (MyFunc)*( long long * )(* ( long long * )(&father));
    MyFunc myfunc2 = (MyFunc)*( long long * )((* ( long long * )(&father)) + sizeof(void*));

    myfunc1();
    myfunc2();

    // 取子类虚表中的函数地址
    // 因为我的电脑是64位的，任何类型的指针大小都是8字节，即 sizeof(void*) = 8
    // 所以要显式指定指针
    MyFunc myfunc3 = (MyFunc)*( long long * )(* ( long long * )(&son));
    myfunc3();
    MyFunc myfunc4 = (MyFunc)*( long long * )((* ( long long * )(&son)) + sizeof(void*));
    myfunc4();
    MyFunc myfunc5 = (MyFunc)*( long long * )((* ( long long * )(&son)) + 2 * sizeof(void*));
    myfunc5();
    return 0;
}