#ifndef UPGRADES_H
#define UPGRADES_H

#include <string>
#include <iostream>
#include <cstdlib>

#include "../includes/character.hpp"

class Upgrades : public Character
{
public:
    Upgrades(std::string name, int hp, int speed, int defense, int shield,
         int atk_damage, int crit_rate, int crit_damage, int dodge_rate,
		 int cost, int reward);

    void	display_info() const;

    int		get_cost() const { return _cost; }
    int		get_reward() const { return _reward; }

protected:
    int	_cost;
    int	_reward;
};

# endif
