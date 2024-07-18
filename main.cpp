#include <iostream>
#include "Manager.hpp"


int main()
{
    // 获得Manager对象
    Manager manager;

    while (true)
    {
        manager.showMenu();
        manager.run(manager.select());
    }
    return 0;
}