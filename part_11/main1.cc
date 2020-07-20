/*
 * C++ 左值与右值，万能引用
 * 万能引用是搭配模版来使用，并且大概率是为完美转发服务的
 * 万能引用：使用模版T&&类型的形参，既能绑定右值，又能绑定左值
 * */

#include <iostream>

using namespace std;

template <typename T>
void foo(T& val) {
	cout << "val是左值" << endl;
}

// T&& 是万能引用，要搭配模版template来使用
// void foo(int&& val) 这个时候没有模版，只能传入右值，传左值就会报错
template <typename T>
void foo(T&& val) {
	cout << "val是右值" << endl;
}

int main() {
	int num = 2020;
	foo(num);
	foo(2020);
	return 0;
}
