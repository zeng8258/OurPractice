#include "Manager.hpp"
#include <iostream>
#include "Menu.hpp"
#include <fstream>
#include <string>
#include "def.hpp"
#include <filesystem>
#include "function.hpp"

// static Manager *instance = nullptr;
Manager::Manager() : isLogin(false), _curUser(User())
{
    // 清屏
    function::clear();

    // 从文件中读取社区列表
    this->loadCommunityList();
    this->loadUserList();
}
Manager::~Manager() {}

/* Manager& Manager::instance()
{
    if (_instance == nullptr)
        _instance = new Manager();

    return *_instance;
}*/

void Manager::showMenu() const
{
    if (this->isLogin)
        Menu().showMenu(this->_curUser.getUserStatus());
    else
        Menu().showMenu(USER_STATUS_UNLOGIN);
}

int Manager::select() const
{
    int select;
    std::cin >> select;
    getchar();
    return select;
}

void Manager::loadUserList()
{
    // 从files/user/userList.txt中获取所有的userName
    std::ifstream infile("../files/user/userList.txt");
    if (!infile)
    {
        std::cout << "文件打开失败" << std::endl;
        // 暂停和清屏
        function::pause();
        function::clear();
        return;
    }
    std::string userName;
    while (infile >> userName)
    {
        this->_userList.push_back(userName);
    }
}

void Manager::loadCommunityList()
{
    // 从files/community/communityList.txt中获取所有的communityName
    std::ifstream infile("../files/community/communityList.txt");
    if (!infile)
    {
        std::cout << "文件打开失败" << std::endl;
        // 暂停和清屏
        function::pause();
        function::clear();
        return;
    }
    std::string communityName;
    while (infile >> communityName)
    {
        this->_communityList.push_back(communityName);
    }

    // 关闭文件
    infile.close();
}

void Manager::registerUser()
{
    // 输入用户名
    std::string name, password;
    std::cout << "请输入用户名：";
    std::cin >> name;
    getchar();

    // 遍历列表
    for (auto userName : this->_userList)
    {
        if (userName == name)
        {
            std::cout << "用户名已存在" << std::endl;
            // 暂停和清屏
            function::pause();
            function::clear();
            return;
        }
    }

    // 输入密码
    std::cout << "请输入密码：";
    std::cin >> password;
    getchar();

    // 加入_userList
    this->_userList.push_back(name);

    // 写入files/userList.txt
    std::ofstream outfile("../files/user/userList.txt", std::ios::app);
    outfile << name << std::endl;
    outfile.close();

    // 写入files/userInfo/user
    std::ofstream outfile2("../files/user/userInfo/user" + name + ".txt");
    outfile2 << name << "\n"
             << password << std::endl;
    outfile2.close();

    std::cout << "注册成功" << std::endl;
    // 暂停和清屏
    function::pause();
    function::clear();
}

void Manager::login()
{
    std::string name, password;
    std::cout << "请输入用户名：";
    std::cin >> name;
    std::cout << "请输入密码：";
    std::cin >> password;
    getchar();

    // 遍历列表
    for (auto userName : this->_userList)
    {
        if (userName == name) // 找到用户名
        {
            // 读取文件
            std::ifstream infile("../files/user/userInfo/user" + name + ".txt");
            if (!infile)
            {
                std::cout << "文件打开失败" << std::endl;
                // 暂停和清屏
                function::pause();
                function::clear();
                return;
            }
            std::string userName, userPassword;
            infile >> userName >> userPassword;
            infile.close();
            if (userPassword == password) // 密码正确
            {
                this->isLogin = true;
                this->_curUser = User(name, password);
                this->_curUser.setUserStatus(USER_STATUS_MAINMENU);
                std::cout << "登录成功" << std::endl;
                // 暂停和清屏
                function::pause();
                function::clear();
                return;
            }
            else // 密码错误
            {
                std::cout << "密码错误" << std::endl;
                // 暂停和清屏
                function::pause();
                function::clear();
                return;
            }
        }
    }
    // 未找到用户名
    std::cout << "用户名不存在" << std::endl;
    // 暂停和清屏
    function::pause();
    function::clear();
}
void Manager::exitManager()
{
    std::cout << "退出程序" << std::endl;
    // 清屏
    function::clear();
    exit(0);
}

void Manager::logout()
{
    this->isLogin = false;
    this->_curUser.setUserStatus(USER_STATUS_UNLOGIN);
    std::cout << "退出登录" << std::endl;
    // 暂停和清屏
    function::pause();
    function::clear();
}

void Manager::addCommunity()
{
    // 输入社区名称
    std::string communityName;
    std::cout << "请输入社区名称：";
    std::cin >> communityName;
    getchar();

    // 遍历列表，检查是否已经存在
    for (auto CommunityName : this->_communityList)
    {
        if (communityName == CommunityName)
        {
            std::cout << "社区名称已存在" << std::endl;
            // 暂停和清屏
            function::pause();
            function::clear();
            return;
        }
    }

    // 加入_communityList
    this->_communityList.push_back(communityName);

    // 写入files/communityList.txt
    std::ofstream outfile("../files/community/communityList.txt", std::ios::app);
    outfile << communityName << std::endl;
    outfile.close();

    // 创建files/community/communityInfo/community" + communityName 文件夹
    std::string path = "../files/community/communityInfo/community" + communityName;
    std::filesystem::create_directory(path);

    // 创建files/community/communityInfo/community" + communityName/robotInfo 和 conversationInfo 和 conversationHistory 文件夹
    std::string robotInfoPath = path + "/robotInfo";
    std::string conversationPath = path + "/conversationInfo";
    std::string conversationHistoryPath = path + "/conversationHistory";
    std::filesystem::create_directory(robotInfoPath);
    std::filesystem::create_directory(conversationPath);
    std::filesystem::create_directory(conversationHistoryPath);

    // 创建 files/community/communityInfo/community" + communityName/robotList.txt 和 conversastion.txt 文件
    std::string robotListPath = path + "/robotList.txt";
    std::string conversationListPath = path + "/conversation.txt";
    std::ofstream outfile2(robotListPath);
    std::ofstream outfile3(conversationListPath);
    outfile2.close();
    outfile3.close();

    // 创建成功
    std::cout << "创建成功" << std::endl;

    // 暂停和清屏
    function::pause();
    function::clear();
}

void Manager::enterCommunity()
{
    // 显示社区列表
    this->showCommunityList();

    // 输入社区序号
    int communityIndex;
    std::cout << "请输入社区序号：";
    std::cin >> communityIndex;
    getchar();

    // 检查
    if (communityIndex < 1 || communityIndex > this->_communityList.size())
    {
        std::cout << "社区序号错误" << std::endl;
        // 暂停和清屏
        function::pause();
        function::clear();
        return;
    }

    // 进入社区
    this->_curCommunity = Community(this->_communityList[communityIndex - 1], &(this->_curUser));

    // 进入社区
    this->_curUser.setUserStatus(USER_STATUS_COMMUNITY);
    std::cout << "进入社区成功" << std::endl;

    // 暂停和清屏
    function::pause();
    function::clear();
}

void Manager::showCommunityInfo()
{
    // 显示社区列表
    this->showCommunityList();

    // 输入社区序号
    int communityIndex;
    std::cout << "请输入社区序号：";
    std::cin >> communityIndex;
    getchar();

    // 检查
    if (communityIndex < 1 || communityIndex > this->_communityList.size())
    {
        std::cout << "社区序号错误" << std::endl;
        // 暂停和清屏
        function::pause();
        function::clear();
        return;
    }

    Community community = Community(this->_communityList[communityIndex - 1], &(this->_curUser));

    // 显示社区名字
    std::cout << "社区名称：" << community.getName() << std::endl;

    // 显示robot列表
    community.showRobotList();

    // 显示会话列表
    community.showConversationList();

    // 暂停和清屏
    function::pause();
    function::clear();
}

void Manager::showCommunityList() const
{
    // 显示社区列表，要有序号
    std::cout << "社区列表：" << std::endl;
    for (int i = 0; i < this->_communityList.size(); i++)
    {
        std::cout << i + 1 << ". " << this->_communityList[i] << std::endl;
    }
}

void Manager::changeUser()
{
    // 显示当前用户
    std::cout << "当前用户：" << this->_curUser.getName() << std::endl;

    // 显示用户列表
    this->showUserList();

    // 输入用户序号
    int userIndex;
    std::cout << "请输入用户序号：";
    std::cin >> userIndex;
    getchar();

    // 检查
    if (userIndex < 1 || userIndex > this->_userList.size())
    {
        std::cout << "用户序号错误" << std::endl;
        // 暂停和清屏
        function::pause();
        function::clear();
        return;
    }

    // 输入密码
    std::string password;
    std::cout << "请输入密码：";
    std::cin >> password;
    getchar();

    // 检查密码，密码在文件中
    std::ifstream infile("../files/user/userInfo/user" + this->_userList[userIndex - 1] + ".txt");
    if (!infile)
    {
        std::cout << "文件打开失败" << std::endl;
        // 暂停和清屏
        function::pause();
        function::clear();
        return;
    }

    std::string userName, userPassword;
    infile >> userName >> userPassword;
    infile.close();

    if (userPassword != password)
    {
        std::cout << "密码错误" << std::endl;
        // 暂停和清屏
        function::pause();
        function::clear();
        return;
    }
    else
    {
        this->_curUser.setNameAndPassword(this->_userList[userIndex - 1], password);
        std::cout << "修改成功" << std::endl;
        // 暂停和清屏
        function::pause();
        function::clear();
    }
}

void Manager::showUserList() const
{
    // 显示用户列表
    std::cout << "用户列表：" << std::endl;
    for (int i = 0; i < this->_userList.size(); i++)
    {
        std::cout << i + 1 << ". " << this->_userList[i] << std::endl;
    }
}

void Manager::run(int selection)
{
    switch (this->_curUser.getUserStatus())
    {
    case USER_STATUS_UNLOGIN:
        this->runOrigin(selection);
        break;
    case USER_STATUS_MAINMENU:
        this->runMain(selection);
        break;
    case USER_STATUS_COMMUNITY:
        this->_curCommunity.run(selection);
        break;
    }
}

void Manager::runOrigin(int selection)
{
    switch (selection)
    {
    case 1: // 注册
        this->registerUser();
        break;
    case 2: // 登录
        this->login();
        break;
    case 3: // 退出
        this->exitManager();
        break;
    default:
    {
        std::cout << "输入错误" << std::endl;
        // 暂停和清屏
        function::pause();
        function::clear();
        break;
    }
    }
}

void Manager::runMain(int selection)
{
    switch (selection)
    {
    case 1: // 创建社区
        this->addCommunity();
        break;
    case 2: // 进入社区
        this->enterCommunity();
        break;
    case 3: // 显示社区信息
        this->showCommunityInfo();
        break;
    case 4: // 显示社区列表
    {
        this->showCommunityList();
        // 暂停和清屏
        function::pause();
        function::clear();
        break;
    }
    case 5: // 修改用户
        this->changeUser();
        break;
    case 6: // 退出
        this->logout();
        break;
    default:
        std::cout << "输入错误" << std::endl;
        // 暂停和清屏
        function::pause();
        function::clear();
        break;
    }
}
