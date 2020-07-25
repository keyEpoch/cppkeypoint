#include <iostream>
#include <thread>


using namespace std;

int main() {
	string s("zhang");
	int num1 = 1, num2 = 2;

	// thread t = thread([&](int a, int b) {     // 这样也可以
	thread t = thread([num1, num2, s](int a, int b) {
		cout << num1 + num2 + a + b << endl;
		cout << s << endl;
	}, 3, 4);
	t.join();

	return 0;
}
