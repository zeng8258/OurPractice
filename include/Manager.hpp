// The Manager class

#ifndef MANAGER_HPP
#define MANAGER_HPP

#pragma once

#include "Community.hpp"
#include "User.hpp"
#include "Robot.hpp"
#include <vector>

class Manager
{
private:
    // 单件类
    Manager();

public:
    // 析构
    ~Manager();
    //获取实例对象
    static Manager* getInstance();

    // 功能
    void showMenu(); // 显示菜单
    void registerUser(); // 注册账号
    void login(); // 登录
    void logout(); // 退出
    void selectCommunity(); // 选择社区
    void showCommunity(); // 显示社区
    void showUser(); // 显示用户

private:
    static Manager* _instance;

    std::vector<Community> _communityList; // 社区列表
    std::vector<Community>::iterator _curCommunity; // 当前社区
    std::vector<User> _userList; // 用户列表
    std::vector<User>::iterator _curUser; // 当前用户

    bool isLogin; // 是否登录

};

#endif