#include "game.hpp"

void	shop(Hero *heros, std::vector<Upgrades> &all_upgrades)
{
	if (!heros)
		return;
	int reroll_cost = 10;
	bool shopping = true;
	std::vector<Upgrades> current_shop;
	auto generate_shop = [&]() {
		current_shop.clear();
		std::unordered_set<int> used_indices;
		int available = std::min(3, (int)all_upgrades.size());
		while ((int)current_shop.size() < available)
		{
			int rand_index = rand() % all_upgrades.size();
			if (used_indices.insert(rand_index).second)
				current_shop.push_back(all_upgrades[rand_index]);
		}
	};
	generate_shop();
	while (shopping)
	{
		std::cout << "\033[2J\033[1;1H";
		heros->display_info();
		std::cout << get_color_code(TextColor::MAGENTA)
				  << "Or actuel : " << heros->get_amount_golds() << " 💰\n\n";
		std::cout << get_color_code(TextColor::CYAN)
				  << "=== 🏪 Boutique d'ameliorations ===\n"
				  << get_color_code(TextColor::DEFAULT);
		for (int i = 0; i < (int)current_shop.size(); ++i)
		{
			std::cout << get_color_code(TextColor::YELLOW)
					  << i + 1 << ". "
					  << get_color_code(TextColor::WHITE);
			current_shop[i].display_info();
		}
		std::cout << "\n"
				  << get_color_code(TextColor::CYAN)
				  << "[1-" << current_shop.size() << "] Acheter  | "
				  << "[R] Rafraichir (-" << reroll_cost << " or) | "
				  << "[Q] Quitter\n"
				  << get_color_code(TextColor::DEFAULT);
		std::string input;
		std::cout << "\nVotre choix : ";
		enableInput();
		std::getline(std::cin, input);
		disableInput();
		input.erase(0, input.find_first_not_of(" \t\r\n"));
		input.erase(input.find_last_not_of(" \t\r\n") + 1);
		for (auto &c : input) c = std::tolower(c);
		if (input == "q")
		{
			slow_print("\nVous quittez la boutique...\n", 30, TextColor::RED);
			break;
		}
		else if (input == "r")
		{
			if (heros->get_amount_golds() >= reroll_cost)
			{
				heros->change_golds(-reroll_cost);
				slow_print("💸 Rafraichissement de la boutique...\n", 25, TextColor::CYAN);
				std::this_thread::sleep_for(std::chrono::milliseconds(600));
				generate_shop();
				continue;
			}
			else
			{
				slow_print("Pas assez d'or pour rafraichir la boutique !\n", 25, TextColor::RED);
				continue;
			}
		}
		else if (!input.empty() && std::all_of(input.begin(), input.end(), ::isdigit))
		{
			int choice = std::stoi(input);
			if (choice >= 1 && choice <= (int)current_shop.size())
			{
				Upgrades selected = current_shop[choice - 1];
				if (heros->get_amount_golds() < selected.get_cost())
					slow_print("Vous n'avez pas assez d'or pour acheter " + selected.get_name() + "!\n", 25, TextColor::RED);
				else
				{
					heros->change_golds(-selected.get_cost());
					slow_print("✅ Vous achetez " + selected.get_name() + "!\n", 25, TextColor::GREEN);
					if (selected.get_hp() > 0)
						heros->change_max_hp(selected.get_hp());
					heros->set_hp(selected.get_hp());
					heros->set_speed(selected.get_speed());
					heros->set_defense(selected.get_defense());
					heros->set_shield(selected.get_shield());
					heros->set_atk_damage(selected.get_atk_damage());
					heros->set_crit_rate(selected.get_crit_rate());
					heros->set_crit_damage(selected.get_crit_damage());
					heros->set_dodge_rate(selected.get_dodge_rate());
					heros->change_golds(selected.get_reward());
					generate_shop();
				}
			}
			else
				slow_print("Choix invalide.\n", 25, TextColor::RED);
		}
		else
			slow_print("Entree invalide.\n", 25, TextColor::RED);
	}
	std::cout << get_color_code(TextColor::GREEN)
			  << "\nMerci de votre visite a la boutique !\n"
			  << get_color_code(TextColor::DEFAULT);
}
