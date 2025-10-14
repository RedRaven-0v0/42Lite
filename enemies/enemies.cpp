#include "enemies.hpp"

Enemy::Enemy(std::string name, int level, int pv, int speed, int defense, int shield,
          int atk_damage, int crit_rate, int crit_damage, int dodge_rate, int gold_reward)
    : Character(name, pv, speed, defense, shield, atk_damage, crit_rate, crit_damage, dodge_rate)
{
	_level = level;
	_gold_reward = gold_reward;
}
void Enemy::display_info() const
{
    std::cout << "=== ENNEMI ===" << std::endl;
    std::cout << "Nom : " << _name << std::endl;
    std::cout << "Level : " << _level << std::endl;
    std::cout << "PV : " << _hp << std::endl;
    std::cout << "Attaque : " << _atk_damage << std::endl;
    std::cout << "Recompense : " << _gold_reward << " or" << std::endl;
}