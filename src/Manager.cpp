#include "Manager.hpp"
#include <iostream>
#include "Menu.hpp"
#include <fstream>

static Manager *instance = nullptr;
Manager::Manager() : isLogin(false) {}
Manager::~Manager() {}

Manager *Manager::getInstance()
{
    if (instance == nullptr)
        _instance = new Manager();

    return instance;
}

void Manager::showMenu() const
{   
    if (this->isLogin) Menu().showMenu(this->_curUser->getUserStatus());
    else Menu().showMenu(0);
}

int Manager::select() const
{
    int select;
    std::cin >> select;
    return select;
}

void Manager::run(int select)
{
    if (!this->isLogin)
    {
        switch (select)
        {
        case 1: this->registerUser();
            break;
        case 2: this->login();
            break;
        case 3: exit(0);
            break;
        default: std::cout << "输入错误，请重新输入" << std::endl;
            break;
        }
    }
    else
    {
        switch (this->_curUser->getUserStatus())
        {
            case 1:
            {
                switch (select)
                {
                    case 1: this->selectCommunity();
                        break;
                    case 2: this->showCommunity();
                        break;
                    case 3: this->showUser();
                        break;
                    case 4: this->logout();
                        break;
                    default: std::cout << "输入错误，请重新输入" << std::endl;
                }
            }
            break;
            case 2:
            {

            }
            break;
            case 3:
            {

            }
            break;
            case 4:
            {

            }
            break;
        }
    }
}

void Manager::registerUser()
{
    // 创建一个User
    User user;

    // 加入列表
    this->_userList.push_back(user);

    // 保存
    this->saveUserList();
}

void Manager::login()
{
    std::string name, password;
    std::cout << "请输入用户名：";
    std::cin >> name;
    std::cout << "请输入密码：";
    std::cin >> password;

    // 遍历列表

    // 如果没有这个用户

    // 如果用户存在

}

void Manager::logout()
{

}

void Manager::addCommunity()
{
    // 创建一个Community
    Community community;

    // 加入列表
    this->_communityList.push_back(community);

    // 保存
    this->saveCommunityList();
}




