#include <iostream>

using std::cout;
using std::endl;

extern int a;

// static函数只能在该文件中使用，不能在别的文件中使用
static void prt();

void prt_1();
