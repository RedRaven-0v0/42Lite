#include "game.hpp"

std::string get_color_code(TextColor color)
{
    switch (color)
    {
        case TextColor::RED:     return "\033[31m";
        case TextColor::GREEN:   return "\033[32m";
        case TextColor::YELLOW:  return "\033[33m";
        case TextColor::BLUE:    return "\033[34m";
        case TextColor::MAGENTA: return "\033[35m";
        case TextColor::CYAN:    return "\033[36m";
        case TextColor::WHITE:   return "\033[37m";
        default:                 return "\033[0m";
    }
}

void slow_print(const std::string &text, int delay_ms, TextColor color)
{
	
    std::cout << get_color_code(color);
    for (char c : text)
    {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
    }
	std::cout << "\033[0m";
}