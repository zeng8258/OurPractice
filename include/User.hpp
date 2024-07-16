// The User class

#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include "Community.hpp"
#include "def.hpp"

enum UserStatus{};
class User
{
private:
    std::string _name;
    std::string _password;
    std::vector<std::string>_accessibleCommunities;
    UserStatus _status;


public:
    User();
    User(const std::string&name,const std::string& pwd);
    ~User();
    std::string getName();
    void changePassword(const std::string& originalPassword);
    void setNameAndPassword(const std::string& uname,const std::string&pwd);
    std::string userTalk();
    void addCommunity(const std::string&community);
    void listAccessibleCommunities();
    void setUserStatus(const UserStatus ustatus);
    int getUserStatus();

};

#endif