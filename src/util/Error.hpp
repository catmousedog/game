#pragma once

#include <iostream>
#include <format>

#include "Basic.hpp"

#define PRINT_ERROR(fmt, ...) print_error(fmt, __LINE__, __FILE__, __func__, __VA_ARGS__)

#define PRINT_DEBUG(fmt, ...) print_debug(fmt, __VA_ARGS__)

template<typename... Args>
inline void print_error(string fmt, int line, const char* file, const char* func, Args... args) {
    
    const string red_color = "\033[31m";
    const string reset_color = "\033[0m";

    string formatted_message = std::vformat(fmt, std::make_format_args(args...));
    
    std::cerr << red_color
              << "Error:\t" << formatted_message << "\n"
              << "\tin " << file << "\n"
              << "\tat " << func << ":" << line << "\n"
              << reset_color;
}


template<typename... Args>
inline void print_debug(string fmt, Args... args) {
    
    const string blue_color = "\033[34m";
    const string reset_color = "\033[0m";

    string formatted_message = std::vformat(fmt, std::make_format_args(args...));
    
    std::cout << blue_color
              << formatted_message << "\n"
              << reset_color;
}