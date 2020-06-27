#include <iostream>

using namespace std;

class Father {
public:
	Father() { cout << "Init Father" << endl; }
	
	virtual void foo() { cout << "foo Father " << endl; }
	
	// 父类的析构函数，如果不加virtual，那么delete父类的指针的时候
	// 就只会调用父类的析构函数，子类的析构函数是不会被调用的
	virtual ~Father() { cout << "Deconstruct Father" << endl; }
};

class Son1 : public Father {
public:
	Son1() { cout << "Init Son1" << endl; }
	
	virtual void foo() { cout << "foo Son1" << endl; }

	~Son1() { cout << "Deconstruct Son1" << endl; }
};

class Son2 : public Father {
public:
	Son2() { cout << "Init Son2" << endl; }

	virtual void foo() { cout << "foo Son2" << endl; }

	~Son2() { cout << "Deconstruct Son2" << endl; }
};

int main() {
	Father* father = new Son1;
	father->foo();

	father = new Son2;
	father->foo();

	delete father;
	return 0;
}
