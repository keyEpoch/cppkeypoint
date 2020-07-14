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
    
    cout << "pA的引用计数: " << pA.use_count() << endl; 
    cout << "pB的引用计数: " << pB.use_count() << endl;

    pA->spa = pB;
    // pB->spb = pA;
    
    // 因为shared_ptr中的 引用计数 是 size_t* m_refcnt;
    // pB的*m_refcnt本来就是1，现在pA来插一杠，pB的 *m_refcnt就是2了
    cout << "pA的引用计数: " << pA.use_count() << endl; 
    cout << "pB的引用计数: " << pB.use_count() << endl;
    cout << pA->spa.use_count() << endl;
    return 0;
}