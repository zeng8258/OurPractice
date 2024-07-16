#include "Menu.hpp"
#include <fstream>
#include <iostream>

Menu::Menu() {}

Menu::~Menu() {}

void Menu::showMenu(int userStatus) const
{
    // 读取文件
    std::ifstream ifs;
    std::string menuFileName = "menu" + std::to_string(userStatus) + ".txt";
    ifs.open(menuFileName, std::ios::in);

    if (!ifs.is_open())
    {
        std::cout << "文件打开失败" << std::endl;
        return;
    }

    // 读取文件内容
    std::string line;
    while (getline(ifs, line))
    {
        std::cout << line << std::endl;
    }

    ifs.close();
}
