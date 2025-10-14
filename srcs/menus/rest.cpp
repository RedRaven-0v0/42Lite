#include "game.hpp"

static void	banane(Hero *heros)
{
	heros->set_atk_damage(10);
	heros->set_crit_damage((heros->get_crit_damage() / heros->get_atk_damage() * 10));
	slow_print(heros->get_name() + " se sent plus puissant !\n", 30, TextColor::GREEN);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	slow_print("Beurk une banane.\n", 50, TextColor::RED);
}

static void kahwa(Hero *heros)
{
	heros->set_dodge_rate(5);
	heros->set_speed(5);
	if (rand() % 100 > 33)
	{
		slow_print("Ouf pas de cafard !\n", 50, TextColor::GREEN);
		slow_print(heros->get_name() + " se sent plus leger !\n", 30, TextColor::GREEN);
	}
	else
	{
		heros->change_max_hp(5);
		slow_print("Il est croustillant ce cafe...\n", 50, TextColor::RED);
		slow_print(heros->get_name() + " se sent legerement plus lourd !\n", 30, TextColor::MAGENTA);
	}
}

static void binouze(Hero *heros)
{
	heros->set_defense(5);
	slow_print(heros->get_name() + " sent son bidou grossir !\n", 30, TextColor::GREEN);
	slow_print("Aaaaaaah elle est bien fraiche !\n", 30, TextColor::GREEN);
}

static void belvita(Hero *heros)
{
	heros->change_max_hp(10);
	slow_print(heros->get_name() + " se sent mieux, il est bon ce Belvita !\n", 30, TextColor::GREEN);
	heros->heal(20);
}

static void	tegou(Hero *heros)
{
	int choice = 0;
	while (true)
	{
		slow_print("Vous prendrez bien :\n[1] Kahwa\n[2] Banane\n[3] Binouze\n[4] Belvita\n\nVotre choix (1-4) : ", 30, TextColor::YELLOW);
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
			if (choice == 1)
			{
				kahwa(heros);
				break;
			}
			if (choice == 2)
			{
				banane(heros);
				break;
			}
			if (choice == 3)
			{
				binouze(heros);
				break;
			}
			if (choice == 4)
			{
				belvita(heros);
				break;
			}
		}
		std::cout << get_color_code(TextColor::RED);
		std::cout << "Choix invalide. Reessayez.\n";
		std::cout << get_color_code(TextColor::DEFAULT);
	}
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
	slow_print("Miam miam...\n", 30, TextColor::YELLOW);
	std::cout << "\n";
}

void	rest(Hero *heros, std::vector<Upgrades> upgrades)
{
	slow_print("C'est l'heure du TEGOU ! J'espere que vous avez rapporte de quoi grignoter !\n", 30, TextColor::GREEN);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
	slow_print("Asseyez vous et reposez vous, c'est le moment !\n", 30, TextColor::GREEN);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
	slow_print("Vous vous posez sur une banquette : ", 30, TextColor::GREEN);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	heros->heal(50);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	to_continue();
	std::cout << "\033[2J\033[1;1H";
	heros->display_info();
	tegou(heros);
}