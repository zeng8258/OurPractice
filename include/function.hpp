// some functions used frequently

#ifndef FUNCTION_HPP
#define FUNCTION_HPP

class function
{
public:
    // 暂停
    inline static void pause()
    {
        std::cout << "按回车键继续..." << std::endl;
        std::cin.ignore();
    }

    // 清屏
    inline static void clear()
    {
        system("clear");
    }
};

#endif