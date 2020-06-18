#include <iostream>
#include "test.h"
using namespace std;

int main() {
	// prt();    这个会报错，因为静态函数只能在他所在的文件中使用
	
    prt_1();	
	cout << a << endl;
	return 0;
}
