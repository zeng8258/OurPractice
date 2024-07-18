#include "Robot.hpp"

Robot::Robot() : _name("Robot"), _key(KEY)
{
  _response = R"(
      {
        "model": "gpt-3.5-turbo",
        "messages": [{"role": "user", "content": ""}],
        "max_tokens": 4096,
        "temperature": 0
      }
      )"_json;
}

Robot::Robot(std::string name) : _name(name), _key(KEY)
{
  _response = R"(
      {
        "model": "gpt-3.5-turbo",
        "messages": [{"role": "user", "content": ""}],
        "max_tokens": 4096,
        "temperature": 0
      }
      )"_json;
}

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

void Robot::ueserInput(const std::string &input)
{
  this->_input = input;
  this->_response["messages"][0]["content"] = input;
}

std::string &Robot::response()
{
  auto completion = openai::chat().create(_response);
  this->_res = completion.dump(2);
  //std::cout << _name << ':' << this->_res << std::endl;
  return this->_res;
}

void Robot::setTemperature(double temperature)
{
  _response["temperature"] = temperature;
}