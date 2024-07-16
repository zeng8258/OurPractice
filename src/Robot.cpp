#include "Robot.hpp"

Robot::Robot()_name("Robot"), _key(KEY) 
    {_response=R"(
      {
        "model": "gpt-3.5-turbo",
        "messages": [{"role": "user", "content": ""}],
        "max_tokens": 4096,
        "temperature": 0
      }
      )"_json;
    }

Robot::Robot(std::string name, std::string key) : _name(name), _key(key)
    {_response=R"(
      {
        "model": "gpt-3.5-turbo",
        "messages": [{"role": "user", "content": ""}],
        "max_tokens": 4096,
        "temperature": 0
      }
      )"_json;
    }

Robot::Robot(const Robot&){}
Robot::~Robot(){}

void Robot::setName(const std::string &name)
{
    this->_name = name;
}

const std::string &Robot::getName()
{
    return this->_name;
}

const std::string &Robot::getInput()
{
    return this->_input;
}

void Robot::ueserInput(const std::string& input)
{
    this->_input = input;
    this->_response["messages"][0]["content"] = input;
}

void Robot::response()
{
    auto completion = openai::chat().create(_response);
    std::cout<<_name<<':'<< completion.dump(2) <<std::endl;
}

void Robot::setTemperature(double temperature) 
{
    _response["temperature"] = temperature;
}