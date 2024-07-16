// The User class

#ifndef USER_HPP
#define USER_HPP

#include<string>
#include<vector>
#include"Community.hpp"

enum UserStatus{};
class User
{
private:
    std::string _name;
    std::string _password;
    std::vector<std::string>_accessibleCommunities;
    int _status;


public:
    User();
    ~User();
    std::string getName();
    void changePassword(const std::string& originalPassword);
    void setNameAndPassword(const std::string& uname,const std::string&pwd);
    std::string userTalk();
    void addCommunity(const std::string&community);
    void listAccessibleCommunities();
    void setUserStatus(const int ustatus);
    int getUserStatus();

};

#endif