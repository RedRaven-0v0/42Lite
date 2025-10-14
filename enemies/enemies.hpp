#ifndef ENEMY_H
#define ENEMY_H

#include "../includes/character.hpp"

class Enemy : public Character
{
public:
    Enemy(std::string name, int level, int pv, int speed, int defense, int shield,
          int atk_damage, int crit_rate, int crit_damage, int dodge_rate, int gold_reward);

	void	display_info() const;

	void	change_level(int new_level) { _level = new_level; }
	int		get_gold_reward() const { return _gold_reward; }
	int		get_level() const { return _level; }

private:
	int	_level;
    int _gold_reward;
};

# endif
