#include <iostream>

using std::cout;
using std::endl;

template <typename T>
void foo(T& val) {
	cout << "val是左值" << endl;
}

template <typename T>
void foo(T&& val) {
	cout << "val是右值" << endl;
}

template <typename T>
void wrapper(T&& val) {
	//foo(val);
	
	// 完美转发，val还是右值不变
	// 通过完美转发，右值还是右值，不会变成左值
	// 这样在后续的过程中仍可以避免copy
	foo(std::forward<T>(val));
}


int main() {
	int a = 2200;
	wrapper(a);
	wrapper(200);
	return 0;
}
