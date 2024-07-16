// The User class

#ifndef USER_HPP
#define USER_HPP

#include<string>
#include<vector>
#include"Community.hpp"

class User
{
private:
    std::string _name;
    std::string _password;
    std::vector<Community>_accessibleCommunities;


public:
    User();
    ~User();
    std::string _getName();
    void _changePassword(const std::string& originalPassword);
    void _setNameAndPassword(const std::string& uname,const std::string&pwd);
    void _userTalk();
    void _addCommunity(const Community&community);
    void _listAccessibleCommunities();

};

#endif