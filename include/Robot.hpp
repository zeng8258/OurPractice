// The Robot class

#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <string>
#include "Keys.hpp"

class Robot
{
public:
    // 构造和析构
    Robot(): _name("Robot"), _key(KEY) {}
    Robot(const Robot&);
    ~Robot();

    // 功能
    void setName(const std::string& name) { this->_name = name; }
    const std::string& getName() const { return this->_name; }

private:
    std::string _name;
    char *_key;

};

#endif