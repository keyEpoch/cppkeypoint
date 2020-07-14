// Singleton 单例模式
// 作用：保证一个类只有一个实例，并提供一个访问它的全局访问点，使得系统中只有唯一的一个对象实例。

// 应用：常用于管理资源，如日志、线程池

// 实现要点：

// 在类中，要构造一个实例，就必须调用类的构造函数，并且为了保证全局只有一个实例，

// 需防止在外部调用类的构造函数而构造实例，需要将构造函数的访问权限标记为private，

// 同时阻止拷贝创建对象时赋值时拷贝对象，因此也将它们声明并权限标记为private；

// 另外，需要提供一个全局访问点，就需要在类中定义一个static函数，返回在类内部唯一构造的实例。



#include <iostream>

using namespace std;

class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

    // 禁止用户调用拷贝构造函数和赋值运算符=
    // 也可以把这俩写在private中
    Singleton(const Singleton& sin) = delete;
    Singleton& operator=(const Singleton& sin) = delete;

    void print() { cout << "Singleton" << endl; }

private:
    Singleton() {}    // 阻止外部调用构造函数创建对象
    // 私有即禁止对象创建，即拷贝构造函数和=运算符都禁止使用
    // Singleton(const Singleton& sin);             // 阻止拷贝构造
    // Singleton& operator=(const Singleton& sin);  // 阻止赋值对象 
};

int main() {
    Singleton& sin = Singleton::getInstance();
    sin.print();
    return 0;
}