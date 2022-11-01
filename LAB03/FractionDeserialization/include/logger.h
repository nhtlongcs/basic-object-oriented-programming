// logger class for logging colorized messages to the console

#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <string>
#include <variant>
#include <vector>

enum class Color
{
    Black,
    Red,
    Green,
    Yellow,
    Blue,
    Magenta,
    Cyan,
    White
};

class Logger
{
public:
    static Logger &getInstance()
    {
        static Logger instance;
        return instance;
    }
    void log(std::string message, Color color = Color::White)
    {
        std::cout << "\033[1;" << static_cast<int>(color) + 30 << "m" << message << "\033[0m" << std::endl;
    }
    void log(std::vector<std::string> messages, Color color = Color::White)
    {
        for (auto message : messages)
        {
            log(message, color);
        }
    }
    void error(std::string message)
    {
        log(message, Color::Red);
    }
    void warning(std::string message)
    {
        log(message, Color::Yellow);
    }
};
#endif