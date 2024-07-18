// The Conversation class

#ifndef CONVERSATION_HPP
#define CONVERSATION_HPP

#include "User.hpp"
#include "Robot.hpp"

class User;

class Conversation
{
public:
    // 构造
    Conversation(User* user, Robot* robot, std::string& communityName) : _user(user), _robot(robot), _communityName(communityName) {}

    // 析构
    ~Conversation() {}

    // 对话
    void chat();


private:
    User *_user;
    Robot *_robot;
    std::string _name;
    std::string _communityName;
    std::vector<std::string> _messages;
};


#endif