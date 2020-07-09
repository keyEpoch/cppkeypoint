#include <iostream>

using namespace std;

// struct 中的各个成员都拥有自己独享的内存，遵循内存对齐的原则
// union 中的各个成员都是公用一块内存的，并且
// 同一时刻只有一个成员能够得到这块内存的使用权（即对该内存的读写）
// 一个union变量的总长度至少能容纳最大的成员变量，且要满足所有成员变量类型大小的整数倍（如U2和U3所示）

struct S1 {
	char ch;
	short st;    // short的长度是2字节
	int num;
};

struct S2 {
	char ch;
	int num;
	short st;
};

union U1 {
	char ch;
	short st;
	int num;
};

union U2 {
	int nums[5];
	double dbl;
};

union U3 {
	int nums[3];
	double dbl;
};

int main() {
	cout << sizeof(S1) << endl;
	cout << sizeof(S2) << endl;
	
	cout << sizeof(U1) << endl;
	cout << sizeof(U2) << endl;
	cout << sizeof(U3) << endl;
	return 0;
}
