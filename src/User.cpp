#include "User.hpp"
#include <string>
#include <vector>
#include <iostream>

User::User() : _name(""), _password(""), _status(USER_STATUS_UNLOGIN) {}

User::User(const std::string &name, const std::string &pwd) : _name(name), _password(pwd), _status(USER_STATUS_UNLOGIN) {}

std::string User::getName() const { return this->_name; }

void User::changePassword(const std::string &originalPassword)
{
    if (originalPassword != this->_password)
    {
        std::cout << "password wrong,please try again" << std::endl;
        return;
    }
    std::string newpwd1, newpwd2;
    std::cout << "input your new password:";
    std::cin >> newpwd1;
    std::cout << "input your new password again:";
    std::cin >> newpwd2;
    if (newpwd1 != newpwd2)
    {
        std::cout << "the passwords entered twice do not match,please try again" << std::endl;
        return;
    }
    this->_password = newpwd2;
    return;
}

const std::string &User::userTalk()
{
    std::cout << _name << ":";
    std::string message;
    std::cin >> message;
    return message;
}

void User::setNameAndPassword(const std::string &uname, const std::string &pwd)
{
    this->_name = uname;
    this->_password = pwd;
}

void User::setUserStatus(const UserStatus ustatus)
{
    this->_status = ustatus;
}

UserStatus User::getUserStatus() const
{
    return this->_status;
}
