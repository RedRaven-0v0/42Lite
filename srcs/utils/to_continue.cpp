#include "game.hpp"

void to_continue(void)
{
	std::string input;

	while (true)
	{
		slow_print("\n[1] Continuer : ", 30, TextColor::YELLOW);
		enableInput();
		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof())
			{
				std::cin.clear();
				std::cout << get_color_code(TextColor::RED)
						  << "\nFin de l'entree detectee (Ctrl+D). Fin du programme.\n"
						  << get_color_code(TextColor::DEFAULT);
				exit(0);
			}
			else
			{
				std::cin.clear();
				std::cout   << get_color_code(TextColor::RED)
							<< "\nErreur de lecture.\n"
							<< get_color_code(TextColor::DEFAULT);
				continue ;
			}
		}
		disableInput();
		input.erase(0, input.find_first_not_of(" \t\r\n"));
		input.erase(input.find_last_not_of(" \t\r\n") + 1);
		bool is_number = !input.empty() &&
						std::all_of(input.begin(), input.end(), ::isdigit);
		if (is_number && std::stoi(input) == 1)
			break ;
		std::cout << get_color_code(TextColor::RED)
				  << "Choix invalide. Reessayez.\n"
				  << get_color_code(TextColor::DEFAULT);
	}
	std::cout << "\n";
}
