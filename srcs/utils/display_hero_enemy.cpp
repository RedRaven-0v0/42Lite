#include "game.hpp"

void display_side_by_side(const Hero &hero, const Enemy &enemy)
{
	std::cout << "\n";
	slow_print("-------------------------------------------------------------------------------------\n", 0, TextColor::BLUE);
	std::cout << std::setw(37) << ("Etudiant : " + hero.get_name() + " 👤")
			  << std::setw(35) << ("Ennemi : " + enemy.get_name() + " 👹") << "\n";
	std::cout << std::setw(35) << ("Classe : " + hero.get_class_name())
			  << std::setw(35) << ("Level : " + std::to_string(enemy.get_level())) << "\n";
	std::cout << std::setw(35) << ("PV : " + std::to_string(hero.get_hp()))
			  << std::setw(35) << ("PV : " + std::to_string(enemy.get_hp())) << "\n";
	std::cout << std::setw(35) << ("ATK : " + std::to_string(hero.get_atk_damage()))
			  << std::setw(35) << ("ATK : " + std::to_string(enemy.get_atk_damage())) << "\n";
	std::cout << std::setw(35) << ("DEF : " + std::to_string(hero.get_defense()) + "%")
			  << std::setw(35) << ("DEF : " + std::to_string(enemy.get_defense()) + "%") << "\n";
	slow_print("-------------------------------------------------------------------------------------\n", 0, TextColor::BLUE);
}
