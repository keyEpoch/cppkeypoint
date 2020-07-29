#include <iostream>
#include "factory.h"

using std::cout;
using std::endl;

void Init() {    // 初始化角色到工厂
    static bool initialized = false;
    if (!initialized) {
        // 注册root
        RoleFactory::Instance().RegisterRole(
            "boss", 
            new RootAdminRole("ROOT")
        );
        // 注册worker
        RoleFactory::Instance().RegisterRole(
            "worker", 
            new WorkerRole("WORKER")
        );
        // 注册Consumer
        RoleFactory::Instance().RegisterRole(
            "consumer",
            new ConsumerRole("CONSUMER")
        );
        initialized = true;
    }
}

int main() {
    Init();    // 注册角色

    JudgeRole judge;
    
    cout << judge.Judge("boss") << endl;
    cout << judge.Judge("worker") << endl;
    cout << judge.Judge("consumer") << endl;

    return 0;
}

