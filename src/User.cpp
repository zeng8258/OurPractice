#include "User.hpp"
#include<string>
#include<vector>
#include<iostream>

User::User():_name("user"),_password("111111"){}
std::string User::_getName(){return this->_name;}

void User::_changePassword(const std::string& originalPassword)
{
    if(originalPassword!=this->_password)
    {
        std::cout<<"password wrong,please try again"<<std::endl;
        return ;
    }
    std::string newpwd1,newpwd2;
    std::cout<<"input your new password:";
    std::cin>>newpwd1;
    std::cout<<"input your new password again:";
    std::cin>>newpwd2;
    if(newpwd1!=newpwd2)
    {
        std::cout<<"the passwords entered twice do not match,please try again"<<std::endl;
        return ;
    }
    this->_password=newpwd2;
    return ;

}

void User::_userTalk()
{
    std::cout<<_name<<":";
    std::string message;
    std::cin>>message;
}

void User::_setNameAndPassword(const std::string& uname,const std::string&pwd)
{
    this->_name=uname;
    this->_password=pwd;
}

void User::_addCommunity(const Community&community)
{
    User::_accessibleCommunities.push_back(community);
}

void User::_listAccessibleCommunities()
{
    std::cout<<"communities accessible by "<<User::_name<<":"<<std::endl;
    for(const auto&community:_accessibleCommunities)
    {
        std::cout<<"-"<<community._getName();
    }
}

