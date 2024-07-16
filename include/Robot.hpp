// The Robot class

#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <string>
#include "Keys.hpp"
#include "openai.hpp"
#include "nlohmann/json.hpp"
#include <iostream>
using json = nlohmann::json;

class Robot
{
public:
    // 构造和析构
    Robot(): _name("Robot"), _key(KEY) 
    {_response=R"(
      {
        "model": "gpt-3.5-turbo",
        "messages": [{"role": "user", "content": ""}],
        "max_tokens": 4096,
        "temperature": 1
      }
      )"_json;
    }
    Robot(const Robot&);
    ~Robot();

    // 功能
    //给AI命名
    void setName(const std::string& name) { this->_name = name; }
        /**
     * 获取名称
     * 这个成员函数允许获取当前对象的名称。它返回一个 const std::string& 类型的引用，
     * 指向对象内部存储的名称字符串。获得的引用可以用来访问，但不能修改字符串内容，
     * 确保了对象状态的一致性。
     *
     * 返回值：
     * const std::string& - 当前对象的名称的常量引用。
     */
    const std::string& getName() const { return this->_name; }
     /**
     * 处理用户输入的函数
     * 这个函数用于接收用户的输入，并将其存储到对象的_response成员变量中。具体来说，它将用户输入的字符串赋值给_response对象中的一个特定键值对：["messages"][0]["content"]。这个键值对通常用于表示一个消息列表中的第一条消息的内容。通过这种方式，对象可以记录下用户的输入，以便后续处理或分析。
     * @param input 用户输入的字符串。这个字符串将被存储在_response成员变量中的["messages"][0]["content"]键对应的值中。
     */   
    void ueserInput(const std::string& input)
    {
        this->_response["messages"][0]["content"] = input;
        auto completion = openai::chat().create(_response);
        std::cout<<_name<<':'<< completion.dump(2) <<std::endl;
    }

private:
    std::string _name;//AI的名字
    char *_key;//密钥
    json _response;//AI的回复
};

#endif