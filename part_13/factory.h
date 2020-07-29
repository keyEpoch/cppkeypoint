#pragma once
#include <string>
#include <map>
#include <iostream>

class RoleOperation {
public:
    virtual std::string Op() = 0;
    virtual ~RoleOperation() {}
};

// 系统管理员，最高权限
class RootAdminRole : public RoleOperation {
public:
    RootAdminRole(const std::string& rolename) 
    : m_rolename(rolename) {}

    std::string Op() override {
        return m_rolename + " has A permission!"; 
    } 
private:
    std::string m_rolename;
};

// 员工，次高权限
class WorkerRole : public RoleOperation {
public: 
    WorkerRole(const std::string& rolename) 
    : m_rolename(rolename) {}

    std::string Op() override {
        return m_rolename + " has B permission!";
    }

private:
    std::string m_rolename;
};

// 顾客，普通权限
class ConsumerRole : public RoleOperation {
public:
    ConsumerRole(const std::string& rolename)
    : m_rolename(rolename) {}

    std::string Op() override {
        return m_rolename + " has C permission!";
    }
private:
    std::string m_rolename;
};
    
/* *************************************** */

// 角色工厂
class RoleFactory {
public:
    // 获取工厂单例，工厂单例是唯一的
    static RoleFactory& Instance() {
        static RoleFactory instance;    // C++11 以上线程安全，最优雅的写法
        return instance;
    }

    // 把指针对象注册到工厂
    void RegisterRole(const std::string& rolename, RoleOperation* roleop) {
        m_RoleRegistry[rolename] = roleop;
    }

    // 根据name，来获取指针对象
    RoleOperation* GetRole(const std::string& name) {
        if (m_RoleRegistry.find(name) != m_RoleRegistry.end()) 
            return m_RoleRegistry[name];
        return nullptr;
    }

private:
    RoleFactory() {}
    ~RoleFactory() {}

    // 禁止拷贝和赋值
    RoleFactory(const RoleFactory&);
    RoleFactory& operator=(const RoleFactory&);

    std::map<std::string, RoleOperation*> m_RoleRegistry;
};

class JudgeRole {
public:
    std::string Judge(const std::string& rolename) {
        return RoleFactory::Instance().GetRole(rolename)->Op();
    }
};
