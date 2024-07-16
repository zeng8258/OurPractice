#include "Manager.hpp"
#include <iostream>

static Manager* instance = nullptr;
Manager::Manager() : isLogin(false) {}
Manager::~Manager() {}

Manager* Manager::getInstance()
{
    if (instance == nullptr)
        _instance = new Manager();
    
    return instance;
}

void Manager::showMenu()
{
    std::cout << "***************************" << std::endl;
    std::cout << "********** 1. 登录 **********" << std::endl;
    std::cout << "********** 2. 注册 **********" << std::endl;
    std::cout << "********** 3. 退出 **********" << std::endl;
    std::cout << "***************************" << std::endl;
}
