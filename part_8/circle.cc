#include <iostream>
using namespace std;

class B;

class A {
public:
    shared_ptr<B> spa;
};

class B {
public:
    shared_ptr<A> spb;
};

int main() {
    shared_ptr<A> pA = make_shared<A>();
    shared_ptr<B> pB = make_shared<B>();
    
    pA->spa = pB;
    pB->spb = pA;
    
    cout << pA.use_count() << " " << pB.use_count() << endl;
    return 0;
}