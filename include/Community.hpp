// The Community class

#ifndef COMMUNITY_HPP
#define COMMUNITY_HPP

#include "Conversation.hpp"
#include "Robot.hpp"
#include "User.hpp"
#include <vector>
#include <string>

class User;

class Community
{
public:
    // 构造函数
    Community() {}
    Community(const std::string &name, User* curUser);

    // 功能
    void showCommunityInfo() const;    // 显示社区信息
    void enterConversation();          // 进入会话
    void addRobot();                   // 添加机器人
    void showRobotList() const;        // 显示机器人列表
    void delRobot();                   // 删除机器人
    void addConversation();            // 添加会话
    void showConversationList() const; // 显示会话列表
    void delConversation();            // 删除会话
    void exitCommunity();              // 退出社区

    void run(const int selection); // 运行社区

    // 其他
    const std::string &getName() const;

private:
    std::string _name;
    std::vector<std::string> _robotList;                     // 机器人列表
    std::vector<std::string> _conversationList;              // 会话列表
    std::vector<std::string>::iterator _currentConversation; // 当前会话的迭代器
    User* _curUser;                                          // 当前用户
};

#endif