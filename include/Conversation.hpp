// The Conversation class

#ifndef CONVERSATION_HPP
#define CONVERSATION_HPP

#include "User.hpp"
#include "Robot.hpp"

class Conversation
{
public:
    // 构造
    Conversation(const User* user, const Robot* robot) : _user(user), _robot(robot) {}

    // 析构
    ~Conversation() {}

    // 对话
    void chat();


private:
    const User* _user;
    const Robot* _robot;
    std::vector<std::string> _messages;
};


#endif