#include "game.hpp"

void	mid_fight_script(Hero heros)
{
	std::cout << "\033[2J\033[1;1H";
	slow_print("Preparez-vous bien jeune etudiant " + heros.get_name() + " , voici venir le terrible : ", 50, TextColor::CYAN);
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	slow_print("MINISHELL !\n\n", 100, TextColor::RED);
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	slow_print("Les legendes racontent que la suite est plus tranquille une fois ce monstre passe...\n", 50, TextColor::CYAN);
	to_continue();
}