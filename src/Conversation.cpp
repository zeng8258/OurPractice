#include "Conversation.hpp"
#include "Robot.hpp"
#include "User.hpp"
#include <iostream>
#include <fstream>
#include "function.hpp"

void Conversation::chat()
{
    std::cout << "正在加载......" << std::endl;
    // 从文件中读取机器人的提示词
    std::ifstream file("../files/community/communityInfo/community" + this->_communityName + "/robotInfo/robot" + this->_robot->getName() + ".txt");
    std::string description;
    std::getline(file, description);
    file.close();
    // 将提示词发给robot
    description = "你是一个这样的智能体：" + description + "\n";
    this->_robot->ueserInput(description);
    this->_robot->response();

    // 将对话的历史记录发给robot


    // 清除“正在加载......”
    function::clear();
    std::cout << "提示：输入“exit”退出对话，输入“clear”清除上下文" << std::endl;
    // 对话
    while (true)
    {
        std::string userMessage = this->_user->userTalk();

        if (userMessage == "exit") //退出
        {
            std::cout << "Conversation ended." << std::endl;
            return;
        }

        if (userMessage == "clear") // 清除上下文
        {
            this->_robot->clearContext();
            function::clear();
            std::cout << "提示：输入“exit”退出对话，输入“clear”清除上下文" << std::endl;
            continue;
        }

        this->_robot->ueserInput(userMessage);
        std::string robotMessage = this->_robot->response();
        std::cout << this->_robot->getName() << ":" << robotMessage << std::endl;

        // 将对话以追加写入文件
        std::ofstream file("../files/community/communityInfo/community" + this->_communityName + "/conversationHistory/conversation" + this->_name + ".txt", std::ios::app);
        if (file.is_open())
        {
            file << "User: " << userMessage << std::endl;
            file << "Robot: " << robotMessage << std::endl;
            file.close();
        }
    }
}
