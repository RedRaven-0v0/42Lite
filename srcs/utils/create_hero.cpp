#include "game.hpp"

Hero create_hero_from_file(const std::string &filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Erreur : impossible d'ouvrir " << filename << std::endl;
		exit(1);
	}
	std::vector<HeroClass> classes;
	std::string line;
	while (std::getline(file, line))
	{
		if (line.empty() || line[0] == '#')
			continue;
		std::istringstream iss(line);
		HeroClass hc;
		iss >> hc.name >> hc.hp >> hc.speed >> hc.defense >> hc.shield
			>> hc.atk_damage >> hc.crit_rate >> hc.crit_damage >> hc.dodge_rate;
		classes.push_back(hc);
	}
	file.close();

	if (classes.empty())
	{
		std::cerr << "Erreur : aucune classe trouvee dans " << filename << std::endl;
		exit(1);
	}

	auto unlocks = ExpManager::load_unlocks("datas/class_unlocks.txt");
	int total_exp = ExpManager::get_total_exp();
	std::vector<HeroClass> available_classes;

	for (const auto &c : classes)
	{
		auto it = unlocks.find(c.name);
		if (it != unlocks.end() && total_exp >= it->second)
			available_classes.push_back(c);
	}

	if (available_classes.empty())
	{
		std::cerr << "Aucune classe debloquee. Jouez pour gagner de l'experience !\n";
		exit(0);
	}

	std::string player_name;
	std::cout << "\033[2J\033[1;1H";
	slow_print("==== Creation de l'Etudiant ====\n", 30, TextColor::BLUE);
	slow_print("Entrez le nom de votre Etudiant : ", 30, TextColor::YELLOW);
	std::cout << get_color_code(TextColor::CYAN);
	enableInput();
	if (!std::getline(std::cin, player_name))
	{
		if (std::cin.eof())
		{
			std::cin.clear();
			std::cout	<< get_color_code(TextColor::RED)
						<< "\nFin de l'entree detectee (Ctrl+D). Fin du programme.\n"
						<< get_color_code(TextColor::DEFAULT);
			exit(0);
		}
		else
		{
			std::cin.clear();
			std::cout   << get_color_code(TextColor::RED)
						<< "\nErreur de lecture. Nom par defaut.\n"
						<< get_color_code(TextColor::DEFAULT);
			player_name = "Noob";
		}
	}
	disableInput();
	player_name.erase(0, player_name.find_first_not_of(" \t\r\n"));
	player_name.erase(player_name.find_last_not_of(" \t\r\n") + 1);
	std::cout << get_color_code(TextColor::DEFAULT);

	slow_print("\nClasses disponibles :\n", 30, TextColor::YELLOW);
	for (size_t i = 0; i < available_classes.size(); ++i)
	{
		std::cout << get_color_code(TextColor::YELLOW);
		std::cout << "  [" << i + 1 << "] " << available_classes[i].name << std::endl;
		std::cout << get_color_code(TextColor::DEFAULT);
	}

	int choice = 0;
	while (true)
	{
		slow_print("\nVotre choix (1-" + std::to_string(available_classes.size()) + ") : ", 30, TextColor::YELLOW);
		std::string input;
		enableInput();
		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof())
			{
				std::cin.clear();
				std::cout	<< get_color_code(TextColor::RED)
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
		input.erase(0, input.find_first_not_of(" \t\r\n"));
		input.erase(input.find_last_not_of(" \t\r\n") + 1);
		disableInput();

		bool is_number = !input.empty() && std::all_of(input.begin(), input.end(), ::isdigit);
		if (is_number)
		{
			choice = std::stoi(input);
			if (choice >= 1 && (size_t)choice <= available_classes.size())
				break;
		}
		std::cout << get_color_code(TextColor::RED);
		std::cout << "Choix invalide. Reessayez.\n";
		std::cout << get_color_code(TextColor::DEFAULT);
	}

	HeroClass selected = available_classes[choice - 1];
	Hero hero(player_name, selected.hp, selected.speed, selected.defense, selected.shield,
			  selected.atk_damage, selected.crit_rate, selected.crit_damage, selected.dodge_rate);
	slow_print("\n>>> Etudiant cree avec succes ! <<<\n\n", 30, TextColor::MAGENTA);
	hero.set_class_name(selected.name);
	hero.display_info();
	return (hero);
}
