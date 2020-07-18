#include <iostream>
#include <mutex>
#include <thread>

#define T_NUM 10    // 线程数

using std::cout;
using std::endl;

int m = 0;
std::mutex _mutex;

void foo(std::string idx) {
	std::lock_guard<std::mutex> lock(_mutex);    // 加锁后会自动解锁
	++m;
	cout << "thread:" << idx.c_str() << ",  m:" << m  << endl;
}

int main() {
	std::thread tarray[20];
	for (int i = 0; i < T_NUM; ++i) {
		tarray[i] = std::thread(foo, std::to_string(i));
	}
	for (int i = 0; i < T_NUM; ++i) {
		tarray[i].join();
	}

	return 0;
}
