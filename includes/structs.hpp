#ifndef STRUCTS_H
#define STRUCTS_H

#include "includes.hpp"
#include <string>

struct HeroClass {
    std::string name;
    int hp, speed, defense, shield, atk_damage, crit_rate, crit_damage, dodge_rate;
};

enum class TextColor {
    DEFAULT,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE
};

# endif