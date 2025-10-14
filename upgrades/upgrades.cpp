#include "upgrades.hpp"
#include "game.hpp"

Upgrades::Upgrades(std::string name, int hp, int speed, int defense, int shield,
           int atk_damage, int crit_rate, int crit_damage, int dodge_rate,
           int cost, int reward)
    : Character(name, hp, speed, defense, shield, atk_damage, crit_rate, crit_damage, dodge_rate)
{
    _cost = cost;
    _reward = reward;
}

void	Upgrades::display_info() const
{
    slow_print(_name + ", cout : " + std::to_string(_cost) + "\n", 20, TextColor::YELLOW);
}

