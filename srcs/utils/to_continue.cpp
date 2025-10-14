#include "game.hpp"

// void	to_continue(void)
// {
// 	int choice = 0;
// 	while (true)
// 	{
// 		slow_print("\n[1] Continuer : ", 30, TextColor::YELLOW);
// 		std::string input;
// 		enableInput();
// 		std::cin >> input;
// 		disableInput();
// 		bool is_number = !input.empty() && std::all_of(input.begin(), input.end(), ::isdigit) && std::none_of(input.begin(), input.end(), ::isspace);
// 		if (is_number)
// 		{
// 			choice = std::stoi(input);
// 			if (choice == 1)
// 				break;
// 		}
// 		std::cout << get_color_code(TextColor::RED);
// 		std::cout << "Choix invalide. Reessayez.\n";
// 		std::cout << get_color_code(TextColor::DEFAULT);
// 	}
// 	std::cout << "\n";
// }

void to_continue(void)
{
    std::string input;

    while (true)
    {
        slow_print("\n[1] Continuer : ", 30, TextColor::YELLOW);
        enableInput();
        std::getline(std::cin, input);
        disableInput();
        input.erase(0, input.find_first_not_of(" \t\r\n"));
        input.erase(input.find_last_not_of(" \t\r\n") + 1);
        bool is_number = !input.empty() &&
                         std::all_of(input.begin(), input.end(), ::isdigit);
        if (is_number && std::stoi(input) == 1)
            break;
        std::cout << get_color_code(TextColor::RED)
                  << "Choix invalide. Reessayez.\n"
                  << get_color_code(TextColor::DEFAULT);
    }

    std::cout << "\n";
}
