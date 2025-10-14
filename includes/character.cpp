#include "character.hpp"
#include "game.hpp"

Character::Character(std::string name)
    : _name(name), _hp(100), _speed(10), _defense(5), _shield(0),
      _atk_damage(10), _crit_rate(10), _crit_damage(20), _dodge_rate(5)
{}

Character::Character(std::string name, int hp, int speed, int defense, int shield,
                     int atk_damage, int crit_rate, int crit_damage, int dodge_rate)
{
    _name = name;
    _hp = hp;
    _speed = speed;
    _defense = defense;
    _shield = shield;
    _atk_damage = atk_damage;
    _crit_rate = crit_rate;
    _crit_damage = crit_damage;
    _dodge_rate = dodge_rate;
}

int	Character::attack() const
{
	int	damage;

	if (Character::is_crit())
	{
		damage = _crit_damage;
		slow_print(get_name() + " fais un ", 10, TextColor::YELLOW);
		slow_print("coup critique", 10, TextColor::RED);
		slow_print(" avec ", 10, TextColor::YELLOW);
		slow_print(std::to_string(damage), 10, TextColor::RED);
		slow_print(" points de degats.\n", 10, TextColor::YELLOW);
	}
	else
	{
		damage = _atk_damage;
		slow_print(get_name() + " attaque avec ", 10, TextColor::YELLOW);
		slow_print(std::to_string(damage), 10, TextColor::RED);
		slow_print(" points de degats.\n", 10, TextColor::YELLOW);
	}
	return (damage);
}

bool	Character::is_crit() const
{
	int roll;

	roll = rand() % 100;
    return (roll < _crit_rate);
}

bool	Character::is_dodge() const
{
	int roll;

	roll = rand() % 100;
	if (roll < _dodge_rate)
	{
		slow_print(get_name() + " ESQUIVE !\n", 10, TextColor::GREEN);
		return (true);
	}
	return (false);
}

void Character::take_damage(int amount)
{
	int defense = std::clamp(_defense, 0, 100);
	int degats = amount * (100 - defense) / 100;

	if (_shield > 0)
	{
		int absorbed = std::min(_shield, degats);
		_shield -= absorbed;
		degats -= absorbed;
		slow_print(get_name() + " encaisse " + std::to_string(absorbed) + " degats avec son bouclier (" + std::to_string(_shield) + " restants)!\n", 10, TextColor::YELLOW);
	}
	if (degats > 0)
	{
		_hp -= degats;
		if (_hp < 0)
			_hp = 0;
		slow_print(get_name() + " perd " + std::to_string(degats) + " PV (", 10, TextColor::YELLOW);
		if (_hp > 0)
			slow_print(std::to_string(_hp), 10, TextColor::GREEN);
		else
			slow_print(std::to_string(_hp), 10, TextColor::RED);
		slow_print(" restants)\n", 10, TextColor::YELLOW);
	}
	else if (amount > 0 && _shield > 0)
		slow_print(get_name() + " ne subit aucun degat grace a son bouclier !\n", 10, TextColor::CYAN);
}

bool	Character::is_alive() const
{
	return (_hp > 0);
}
