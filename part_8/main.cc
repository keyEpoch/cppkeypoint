#include <iostream>

using namespace std;

template<typename T>
class S_ptr {
public:

    // 构造函数
    S_ptr(T* ptr = nullptr) {
        m_ptr = ptr;
        if (m_ptr) m_refcnt = new int(1);
        else m_refcnt = new int(0);
    }

    // 拷贝构造函数
    S_ptr(const S_ptr& s_ptr) {
        if (this != &s_ptr) {
            m_ptr = s_ptr.m_ptr;
            m_refcnt = s_ptr.m_refcnt;
            (*m_refcnt)++;
        }
    }

    // 重载op=
    S_ptr operator=(const S_ptr& s_ptr) {
        if (s_ptr.m_ptr == this->m_ptr) return *this;
        
        if (m_ptr) {
            (*m_refcnt)--;
            if ((*m_refcnt) == 0) {
                delete m_refcnt;
                delete m_ptr;
            }
            m_ptr = s_ptr.m_ptr;
            m_refcnt = s_ptr.m_refcnt;
            (*m_refcnt)++;
        }
        return *this;
    }

    // 重载op*
    T& operator*() {
        // 因为引用不能为空，所以要做一下判断
        if (m_ptr) return *m_ptr;    
    }

    T* operator->() {
        return m_ptr;
    }

    // 析构函数
    ~S_ptr() {
        (*m_refcnt)--;
        if ((*m_refcnt) == 0) {
            delete m_refcnt;
            delete m_ptr; 
        }
    }

    int use_cnt() {
        return *m_refcnt;
    }

    // TODO: reset 还没实现，源码里好像要用到swap
    
private:
    T* m_ptr;
    int* m_refcnt;
};


int main() {
    
    S_ptr<int> sp1(new int(1));
    S_ptr<int> sp2(new int(2));
    S_ptr<int> sp3(new int(3));
    cout << sp1.use_cnt() << " " << sp2.use_cnt() << " " << sp3.use_cnt() << endl;
    sp1 = sp3;
    cout << sp1.use_cnt() << " " << sp2.use_cnt() << " " << sp3.use_cnt() << endl;
    S_ptr<int> sp4(sp1);
    cout << sp1.use_cnt() << " " << sp2.use_cnt() << " " << sp3.use_cnt() \
    << " " << sp4.use_cnt() << endl;
    return 0;
}