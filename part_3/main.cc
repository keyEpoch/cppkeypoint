#include <iostream>

using std::cout;
using std::endl;

class Father {
public:    // 注意，class默认缺省是private，所以要声明一下public
	virtual void prt(int num = 1) {
		cout << "Father: " << num << endl;
	}
};

class Son : public Father {
public:  
	virtual void prt(int num = 2) {
		cout << "Son: " << num << endl;
	}
};

int main() {
	Father father;
	Son son;

	Father* p;

	p = &father;
	p->prt();
	p->prt(3);

	p = &son;
	// 虚函数的缺省值，是静态绑定的，也就是编译时就确定好了
	// 但是函数还是执行的Son类的函数，不过函数的默认缺省值是父类的
	// 这样的设计，真奇怪
	p->prt();
	p->prt(3);
	return 0;
}
