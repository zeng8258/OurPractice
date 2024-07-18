#include "Community.hpp"
#include "Robot.hpp"
#include "User.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include "def.hpp"

// 构造函数
Community::Community(const std::string &name, User* curUser) : _name(name), _curUser(curUser)
{
    // 初始化机器人列表和会话列表
    this->_robotList.clear();
    this->_conversationList.clear();

    // 从文件中读取robot列表和会话列表，如果文件不存在则创建对应的文件
    std::ifstream file("../files/community/communityInfo/community" + this->_name + "/robotList.txt");
    if (!file)
    {
        std::ofstream file("../files/community/communityInfo/community" + this->_name + "/robotList.txt");
        file.close();
    }
    else
    {
        std::string line;
        while (std::getline(file, line))
        {
            this->_robotList.push_back(line);
        }
        file.close();
    }

    std::ifstream file2("../files/community/communityInfo/community" + this->_name + "/conversationList.txt");
    if (!file2)
    {
        std::ofstream file2("../files/community/communityInfo/community" + this->_name + "/conversationList.txt");
        file2.close();
    }
    else
    {
        std::string line;
        while (std::getline(file2, line))
        {
            this->_conversationList.push_back(line);
        }
        file2.close();
    }
}

void Community::showCommunityInfo() const
{
    std::cout << "社区名称：" << this->_name << std::endl;
    std::cout << "当前用户：" << this->_curUser->getName() << std::endl;
    std::cout << "机器人列表：" << std::endl;
    this->showRobotList();
    std::cout << "会话列表：" << std::endl;
    this->showConversationList();
}

void Community::addRobot()
{
    std::cout << "请输入名字：";
    std::string name;
    std::cin >> name;
    std::cout << "请输入描述：";
    std::string description;
    std::cin >> description;

    this->_robotList.push_back(name);

    // 将机器人的信息存入文件
    std::ofstream file("../files/community/communityInfo/community" + this->_name + "/robotList.txt", std::ios::app);
    file << name << std::endl;
    file.close();

    // 将机器人的提示词存入文件
    std::ofstream file2("../files/community/communityInfo/community" + this->_name + "/robotInfo/robot" + name + ".txt", std::ios::app);
    file2 << description << std::endl;
    file2.close();

    std::cout << "机器人添加成功！" << std::endl;
}

// 显示机器人列表的函数
void Community::showRobotList() const
{
    // 检查有无机器人
    if (_robotList.empty())
    {
        std::cout << "没有机器人！" << std::endl;
        return;
    }
    // 显示机器人列表，带序号
    std::cout << "机器人列表：" << std::endl;
    for (size_t i = 0; i < _robotList.size(); ++i)
    {
        std::cout << i + 1 << ". " << _robotList[i] << std::endl;
    }
}

// 删除机器人的函数
void Community::delRobot()
{
    // 检查有无机器人
    if (_robotList.empty())
    {
        std::cout << "没有机器人！" << std::endl;
        return;
    }

    // 显示机器人列表
    this->showRobotList();

    std::cout << "请输入要删除的机器人的名字：";
    std::string name;
    std::cin >> name;

    // 查找并删除机器人
    auto it = std::find(_robotList.begin(), _robotList.end(), name);
    if (it != _robotList.end())
    {
        _robotList.erase(it);

        // 删除机器人信息文件
        std::remove(("../files/community/communityInfo/community" + this->_name + "/robotInfo/robot" + name).c_str());

        // 更新机器人列表文件
        std::ofstream file("../files/community/communityInfo/community" + this->_name + "/robotList.txt");
        for (const auto &robot : _robotList)
        {
            file << robot << std::endl;
        }

        std::cout << "机器人删除成功！" << std::endl;
    }
    else
    {
        std::cout << "机器人不存在！" << std::endl;
    }
}

// 添加会话的函数
void Community::addConversation()
{
    std::cout << "请输入会话的名字：";
    std::string name;
    std::cin >> name;

    // 检查会话是否已经存在于std::vector<std::string> _conversationList中
    if (std::find(_conversationList.begin(), _conversationList.end(), name) != _conversationList.end())
    {
        std::cout << "会话已经存在！" << std::endl;
        return;
    }

    // 如果会话不存在
    // 选择对话的机器人
    std::cout << "请选择会话的机器人：" << std::endl;
    this->showRobotList();
    std::string robotName;
    std::cin >> robotName;

    // 检查机器人是否存在于std::vector<std::string> _robotList中
    if (std::find(this->_robotList.begin(), this->_robotList.end(), robotName) == _robotList.end())
    {
        std::cout << "机器人不存在！" << std::endl;
        return;
    }

    // 机器人存在
    // 保存会话信息this->function[selection]();
    // 将会话信息存入文件
    std::ofstream file("../files/community/communityInfo/community" + this->_name + "/conversationList.txt");
    file << name << std::endl;
    file.close();
    std::ofstream file2("../files/community/communityInfo/community" + this->_name + "/conversationInfo/conversation" + name + ".txt");
    file2 << this->_curUser->getName() << std::endl;
    file2 << robotName << std::endl;
    file2.close();

    std::cout << "会话添加成功！" << std::endl;
}

// 显示会话列表的函数
void Community::showConversationList() const
{
    // 检查是否有会话
    if (this->_conversationList.empty())
    {
        std::cout << "No conversation to display." << std::endl;
        return;
    }

    // 显示会话列表，带序号
    std::cout << "会话列表：" << std::endl;
    for (size_t i = 0; i < _conversationList.size(); ++i)
    {
        std::cout << i + 1 << ". " << _conversationList[i] << std::endl;
    }
}

// 删除会话的函数
void Community::delConversation()
{
    // 检查是否有会话
    if (this->_conversationList.empty())
    {
        std::cout << "No conversation to delete." << std::endl;
        return;
    }

    // 显示会话列表
    std::cout << "会话列表：" << std::endl;
    for (size_t i = 0; i < this->_conversationList.size(); ++i)
    {
        std::cout << i + 1 << ". " << this->_conversationList[i] << std::endl;
    }

    // 选择要删除的会话
    std::cout << "请选择要删除的会话：";
    size_t choice;
    std::cin >> choice;
    if (choice < 1 || choice > this->_conversationList.size())
    {
        std::cout << "无效选择" << std::endl;
        return;
    }

    // 删除会话
    this->_conversationList.erase(this->_conversationList.begin() + choice - 1);

    // 更新会话列表文件
    std::ofstream file("../files/community/communityInfo/community" + this->_name + "/conversationList.txt");
    for (const auto &conversation : this->_conversationList)
    {
        file << conversation << std::endl;
    }
    file.close();

    // 删除会话文件和会话历史记录
    std::remove(("../files/community/communityInfo/community" + this->_name + "/conversationInfo/conversation" + this->_conversationList[choice - 1] + ".txt").c_str());
    std::remove(("../files/community/communityInfo/community" + this->_name + "/conversationHistory/conversation" + this->_conversationList[choice - 1] + ".txt").c_str());

    std::cout << "会话删除成功！" << std::endl;
}

// 退出社区
void Community::exitCommunity()
{
    this->_curUser->setUserStatus(USER_STATUS_MAINMENU);
    std::cout << "退出社区成功！" << std::endl;
}

// 进入会话
void Community::enterConversation()
{
    // 检查是否有会话
    if (this->_conversationList.empty())
    {
        std::cout << "No conversation to enter." << std::endl;
        return;
    }

    // 显示会话列表
    std::cout << "会话列表：" << std::endl;
    for (size_t i = 0; i < this->_conversationList.size(); ++i)
    {
        std::cout << i + 1 << ". " << this->_conversationList[i] << std::endl;
    }

    // 选择要进入的会话
    std::cout << "请选择要进入的会话：";
    size_t choice;
    std::cin >> choice;
    if (choice < 1 || choice > this->_conversationList.size())
    {
        std::cout << "无效选择" << std::endl;
        return;
    }

    // 从文件中读取会话，如果这个会话不由这个用户创建，不允许其进入
    std::ifstream file("../files/community/communityInfo/community" + this->_name + "/conversationInfo/conversation" + this->_conversationList[choice - 1] + ".txt");
    std::string creatorName;
    file >> creatorName;
    if (creatorName != this->_curUser->getName())
    {
        std::cout << "您没有权限进入这个会话！" << std::endl;
        return;
    }

    // 从文件中读取机器人信息
    std::string robotName;
    file >> robotName;
    file.close();

    // 进入会话
    this->_currentConversation = this->_conversationList.begin() + choice - 1;
    this->_curUser->setUserStatus(USER_STATUS_CONVERSATION);

    // 创建一个Conversation类对象，调用chat()功能
    // 需要先创建一个Robot
    Robot robot(robotName);
    Conversation conversation(this->_curUser, &robot, this->_name);
    conversation.chat();

    // 更新用户状态
    this->_curUser->setUserStatus(USER_STATUS_COMMUNITY);
}

// 返回名字
const std::string &Community::getName() const
{
    return this->_name;
}

void Community::run(const int selection)
{
    switch (selection)
    {
    case 1: // 查看社区信息
        this->showCommunityInfo();
        break;
    case 2: // 进入会话
        this->enterConversation();
        break;
    case 3: // 创建会话机器人
        this->addRobot();
        break;
    case 4: // 查看机器人列表
        this->showRobotList();
        break;
    case 5: // 删除机器人
        this->delRobot();
        break;
    case 6: // 创建会话
        this->addConversation();
        break;
    case 7: // 查看会话列表
        this->showConversationList();
        break;
    case 8: // 删除会话
        this->delConversation();
        break;
    case 9: // 退出社区
        this->exitCommunity();
        break;
    }
}