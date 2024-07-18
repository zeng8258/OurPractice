// The User class

#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include "def.hpp"

class User
{
public:
    User();
    User(const std::string &name, const std::string &pwd);
    std::string getName() const;
    void changePassword(const std::string &originalPassword);
    void setNameAndPassword(const std::string &uname, const std::string &pwd);
    const std::string &userTalk();
    void addCommunity(const std::string &community);
    void listAccessibleCommunities();
    void setUserStatus(const UserStatus ustatus);
    UserStatus getUserStatus() const;

private:
    std::string _name;
    std::string _password;
    UserStatus _status;
};

#endif