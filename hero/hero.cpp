#include "hero.hpp"
#include "game.hpp"

Hero::Hero(std::string name)
	: Character(name)
{
	_max_hp = _hp;
	_amount_golds = 100;
}

Hero::Hero(std::string name, int hp, int speed, int defense, int shield,
		   int atk_damage, int crit_rate, int crit_damage, int dodge_rate,
		   int amount_golds)
	: Character(name, hp, speed, defense, shield, atk_damage, crit_rate, crit_damage, dodge_rate)
{
	_max_hp = hp;
	_amount_golds = amount_golds;
}

void Hero::display_info() const
{
	slow_print("=== ETUDIANT ===\n", 0, TextColor::CYAN);
	slow_print("Nom : " + _name + "\n", 0, TextColor::YELLOW);
	slow_print("Classe : " + _class_name + "\n", 0, TextColor::YELLOW);
	slow_print("PV : " + std::to_string(_hp) + "/" + std::to_string(_max_hp) + "\n", 0, TextColor::YELLOW);
	slow_print("Bouclier : " + std::to_string(_shield) + "\n", 0, TextColor::YELLOW);
	slow_print("Attaque : " + std::to_string(_atk_damage) + "\n", 0, TextColor::YELLOW);
	slow_print("Defense : " + std::to_string(_defense) + "%\n", 0, TextColor::YELLOW);
	slow_print("Vitesse : " + std::to_string(_speed) + "\n", 0, TextColor::YELLOW);
	slow_print("Taux critique : " + std::to_string(_crit_rate) + "%\n", 0, TextColor::YELLOW);
	slow_print("Degats critiques : " + std::to_string(_crit_damage) + "\n", 0, TextColor::YELLOW);
	slow_print("Taux d'esquive : " + std::to_string(_dodge_rate) + "%\n", 0, TextColor::YELLOW);
	slow_print("Or : " + std::to_string(_amount_golds) + "\n\n", 0, TextColor::YELLOW);
}

void	Hero::heal(int amount)
{
	int old_hp;
	
	old_hp = _hp;
	_hp += amount;
	if (_hp > _max_hp)
	{
		_hp = _max_hp;
	}
	std::cout << get_color_code(TextColor::GREEN);
	std::cout << _name << " recupere " << (_hp - old_hp)
			  << " PV (" << _hp << "/" << _max_hp << " PV)" << std::endl;
	std::cout << get_color_code(TextColor::DEFAULT);
}
