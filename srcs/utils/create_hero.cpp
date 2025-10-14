#include "game.hpp"

Hero create_hero_from_file(const std::string &filename)
{
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Erreur : impossible d'ouvrir " << filename << std::endl;
		exit(1);
	}
	std::vector<HeroClass> classes;
	std::string line;
	while (std::getline(file, line)) {
		if (line.empty() || line[0] == '#')
			continue;
		std::istringstream iss(line);
		HeroClass hc;
		iss >> hc.name >> hc.hp >> hc.speed >> hc.defense >> hc.shield
			>> hc.atk_damage >> hc.crit_rate >> hc.crit_damage >> hc.dodge_rate;
		classes.push_back(hc);
	}
	file.close();
	if (classes.empty()) {
		std::cerr << "Erreur : aucune classe trouvee dans " << filename << std::endl;
		exit(1);
	}
	std::string player_name;
	slow_print("==== Creation de l'Etudiant ====\n", 30, TextColor::BLUE);
	slow_print("Entrez le nom de votre Etudiant : ", 30, TextColor::YELLOW);
	std::cout << get_color_code(TextColor::CYAN);
	enableInput();
	std::getline(std::cin, player_name);
	disableInput();
	player_name.erase(0, player_name.find_first_not_of(" \t\r\n"));
	player_name.erase(player_name.find_last_not_of(" \t\r\n") + 1);
	std::cout << get_color_code(TextColor::DEFAULT);
	slow_print("\nChoisissez une classe :\n", 30, TextColor::YELLOW);
	for (size_t i = 0; i < classes.size(); ++i)
	{
		std::cout << get_color_code(TextColor::YELLOW);
		std::cout << "  [" << i + 1 << "] " << classes[i].name << std::endl;
		std::cout << get_color_code(TextColor::DEFAULT);
	}
	int choice = 0;
	while (true)
	{
		slow_print("\nVotre choix (1-" + std::to_string(classes.size()) + ") : ", 30, TextColor::YELLOW);
		std::string input;
		enableInput();
		std::getline(std::cin, input);
		disableInput();
		input.erase(0, input.find_first_not_of(" \t\r\n"));
		input.erase(input.find_last_not_of(" \t\r\n") + 1);
		bool is_number = !input.empty() && std::all_of(input.begin(), input.end(), ::isdigit);
		if (is_number)
		{
			choice = std::stoi(input);
			if (choice >= 1 && (size_t)choice <= classes.size())
				break;
		}
		std::cout << get_color_code(TextColor::RED);
		std::cout << "Choix invalide. Reessayez.\n";
		std::cout << get_color_code(TextColor::DEFAULT);
	}
	HeroClass selected = classes[choice - 1];
	Hero hero(player_name, selected.hp, selected.speed, selected.defense, selected.shield,
			  selected.atk_damage, selected.crit_rate, selected.crit_damage, selected.dodge_rate);
	slow_print("\n>>> Etudiant cree avec succes ! <<<\n\n", 30, TextColor::MAGENTA);
	hero.set_class_name(selected.name);
	hero.display_info();
	return (hero);
}
