#include "game.hpp"

void	final_fight_script(Hero heros)
{
	std::cout << "\033[2J\033[1;1H";
	slow_print("Il est l'heure de montrer ce que vous avez appris " + heros.get_name() + " !\nVoici venir le boss final, celui qui apporte gloire et honneur, et bien sur la divine recompense : le ", 50, TextColor::CYAN);
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	slow_print("TRONC COMMUN !\n\n", 100, TextColor::GREEN);
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	slow_print("Allez, ramenez-vous, c'est l'heure du bain de sang !\n", 50, TextColor::RED);
	to_continue();
}