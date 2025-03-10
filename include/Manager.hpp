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
    // private:
    //  单件类
    // Manager();

public:
    // 构造
    Manager();
    // 析构
    ~Manager();
    // 获取实例对象
    // static Manager &getInstance();

    // 功能
    void showMenu() const;   // 显示菜单
    int select() const;      // 选择功能
    void run(int selection); // 运行

private:
    // 运行
    void runOrigin(int selection); // 运行初始界面
    void runMain(int selection);   // 运行主界面

    // 初始化Manager
    void loadUserList();      // 加载用户列表
    void loadCommunityList(); // 加载社区列表

    // 初始界面
    void registerUser(); // 注册账号
    void login();        // 登录
    void exitManager();  // 退出

    // 主界面
    void addCommunity();            // 创建社区
    void enterCommunity();          // 进入社区
    void showCommunityInfo();       // 显示社区信息
    void showCommunityList() const; // 显示社区列表
    void changeUser();              // 切换用户
    void logout();                  // 退出登录

    // void selectCommunity() const; // 选择社区
    void showUserList() const; // 显示用户列表
    // void saveUserList(); // 保存用户列表
    // void saveCommunityList(); // 保存社区列表

    // 社区界面
    // void showCommunityInfo() const;  显示社区信息
    // void enterConversation(); // 进入对话
    // void addRobot(); // 添加机器人
    // void showRobotList() const; // 显示机器人列表
    // void delRobot(); // 删除机器人
    // void addConversation(); // 添加对话
    // void showConversationList() const; // 显示对话列表
    // void delConversation(); // 删除对话
    // void outCommunity(); // 退出社区

private:
    // static Manager *_instance;

    std::vector<std::string> _communityList; // 社区列表
    Community _curCommunity;                 // 当前社区
    std::vector<std::string> _userList;      // 用户列表
    User _curUser;                           // 当前用户

    bool isLogin; // 是否登录
};

#endif