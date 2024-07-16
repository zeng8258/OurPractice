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
    Robot()_name("Robot"), _key(KEY){}
    Robot(std::string name, std::string key);
    Robot(const Robot&);
    ~Robot();

    // 功能
    //给AI命名
    void setName(const std::string& name);
    //返回AI的名字   
    const std::string& getName();
    //返回用户的输入
    const std::string& getInput();
    //用户输入
    void ueserInput(const std::string& input);
    //AI回复
    void response();
    //更改对话温度
    void setTemperature(double  temperature);
  private:
    std::string _name;//AI的名字
    char *_key;//密钥
    std::string _input;//用户输入的内容
    json _response;//AI的回复
};

#endif