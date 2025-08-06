#pragma once

#include <iostream>
#include <format>

#include "Basic.hpp"

#define PRINT_ERROR(fmt, ...) print_error(fmt, __LINE__, __FILE__, __func__, ##__VA_ARGS__)

#define PRINT_DEBUG(...) print_debug(__VA_ARGS__)

template <typename... Args>
inline void print_error(std::string fmt, int line, const char *file, const char *func, Args... args)
{

    const std::string red_color = "\033[31m";
    const std::string reset_color = "\033[0m";

    std::string formatted_message = std::vformat(fmt, std::make_format_args(args...));

    std::cerr << red_color
              << "Error:\t" << formatted_message << "\n"
              << "\tin " << file << "\n"
              << "\tat " << func << ":" << line << "\n"
              << reset_color;
}

template <typename... Args>
inline void print_debug(Args &&...args)
{
    const std::string blue_color = "\033[34m";
    const std::string reset_color = "\033[0m";

    std::cout << blue_color;
    ((std::cout << args << "\t"), ...);
    std::cout << "\n";
    std::cout << reset_color;
}