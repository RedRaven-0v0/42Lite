#ifndef HERO_H
#define HERO_H

#include "../includes/character.hpp"

enum Classes
{
	CHOMEUR,
	LYCEEN,
	SPORTIF,
	CUISTOT,
	GRAPHISTE,
	HISTORIEN,
	ELECTRONICIEN,
	SURFEUR,
	SUDISTE,
	UNKNOWN
};

class Hero : public Character
{
public:
	Hero(std::string name);

	Hero(std::string name, int hp, int speed, int defense, int shield,
		int atk_damage, int crit_rate, int crit_damage, int dodge_rate,
		int amount_golds = 100);

	void			display_info() const;
	
	void			heal(int amount);
	void			change_max_hp(int amount) { _max_hp += amount; }
	void			change_golds(int amount) { _amount_golds += amount; }
	void			set_class_name(const std::string &class_name) { _class_name = class_name; }
	int				get_amount_golds() const { return _amount_golds; }
	int				get_max_hp() const { return _max_hp; }
	std::string		get_class_name() const { return _class_name; }
	void			ability();

private:
	int			_max_hp;
	int			_amount_golds;
	std::string	_class_name;
};

# endif
