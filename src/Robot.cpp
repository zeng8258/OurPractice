#include "Robot.hpp"

Robot::Robot() : _name("Robot"), _key(KEY)
{
  openai::start("sk-0DITh75zrxk-8tM6mhckTA", "", true, "https://agino.me/");

  _response = R"(
      {
        "model": "gpt-4o",
        "messages": [{"role": "user", "content": ""}],
        "max_tokens": 4096,
        "temperature": 0
      }
      )"_json;
}

Robot::Robot(std::string name) : _name(name), _key(KEY)
{
  openai::start("sk-0DITh75zrxk-8tM6mhckTA", "", true, "https://agino.me/");

  _response = R"(
      {
        "model": "gpt-4o",
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
  this->_res = this->_res.substr(this->_res.find("content") + 10, this->_res.find("role") - this->_res.find("content") - 12);
  return this->_res;
}

void Robot::setTemperature(double temperature)
{
  _response["temperature"] = temperature;
}