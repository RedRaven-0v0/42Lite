#include "game.hpp"

static void shake_print(const std::string &text, int intensity = 2, int duration_ms = 500)
{
    using namespace std::chrono_literals;
    const int frame_delay = 30;
    int frames = duration_ms / frame_delay;

    for (int i = 0; i < frames; ++i)
    {
        int offset = (rand() % (intensity * 2 + 1)) - intensity;
        std::string spaces(std::max(0, offset), ' ');

		std::cout << get_color_code(TextColor::RED);
        std::cout << "\r" << spaces << text << std::flush;
		std::cout << get_color_code(TextColor::DEFAULT);
        std::this_thread::sleep_for(std::chrono::milliseconds(frame_delay));
    }
	std::cout << get_color_code(TextColor::RED);
    std::cout << "\r" << text << std::flush;
    std::cout << std::endl;
	std::cout << get_color_code(TextColor::DEFAULT);
}

static std::string touppers(const std::string &str)
{
	std::string str_cpy = str;
	for (char &c : str_cpy)
		c = std::toupper(static_cast<unsigned char>(c));
	return str_cpy;
}

bool	victory_script(Hero *heros)
{
	std::cout << "\033[2J\033[1;1H";
	slow_print("BRAVO ! BRAVO ! " + heros->get_name() + " BRAVO !\nVous avez reussi la ou maintes et maintes fois des etudiants ont echoue !\n", 50, TextColor::CYAN);
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	slow_print("Vous obtenez donc le fameux TRONC COMMUN de 42, " + heros->get_name() + " le " + heros->get_class_name() + "... Ou devrais-je plutot dire... ", 50, TextColor::GREEN);
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	slow_print(heros->get_name() + " le TRANSCENDE !\n", 50, TextColor::GREEN);
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	slow_print("\nMaintenant que choisissez-vous de faire ?\n", 100, TextColor::YELLOW);
	std::this_thread::sleep_for(std::chrono::milliseconds(500));
	
	std::string input;
    while (true)
    {
        slow_print("\n[1] Continuer en post tronc commun\n[2] Me faire alumniser, je n'ai pas le temps je veux travailler\n\nVotre choix (1-2) ? ", 30, TextColor::YELLOW);
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
        disableInput();
        input.erase(0, input.find_first_not_of(" \t\r\n"));
        input.erase(input.find_last_not_of(" \t\r\n") + 1);
        bool is_number = !input.empty() &&
                         std::all_of(input.begin(), input.end(), ::isdigit);
        if (is_number && std::stoi(input) == 1)
		{
        	slow_print("\nFatigue apres cet enchainement d'evenements, vous vous reposez sur la banquette.\n", 50, TextColor::YELLOW);
			if (heros->get_max_hp() > heros->get_hp())
				heros->heal(heros->get_max_hp() - heros->get_hp());
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        	slow_print("\"Je reconnais la votre puissante volonte de s'ameliorer...\"\n", 50, TextColor::BLUE);
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
        	slow_print("\"C'est bien, c'est tres bien...\"\n", 100, TextColor::BLUE);
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
        	slow_print("\"ALORS MONTRE MOI CETTE VOLONTE EN TOI " + touppers(heros->get_name()) + " !\"\n\n", 50, TextColor::RED);
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			slow_print("Le dieu omnipresent des lieux daigne se montrer pour tester vos capacites " + heros->get_name() + " (il a l'air de croire en vous).\n", 50, TextColor::YELLOW);
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			slow_print("Vous vous rendez compte que la banquette sur laquelle vous etes assis se met a trembler !\n", 50, TextColor::YELLOW);
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			shake_print("C'est un veritable tremblement de terre !", 3, 5000);
			std::this_thread::sleep_for(std::chrono::milliseconds(333));
			slow_print("\nDepuis le debut ce n'etait ni une banquette ni une blanquette\n", 50, TextColor::YELLOW);
			slow_print("C'etait...\n", 50, TextColor::YELLOW);
			to_continue();
            return (false);
		}
		if (is_number && std::stoi(input) == 2)
		{
        	slow_print("\nBon courage a toi " + heros->get_name() + " pour cette nouvelle epreuve !\n", 50, TextColor::CYAN);
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
        	slow_print("J'espere que tu ne seras pas front developpeur...\n", 50, TextColor::MAGENTA);
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        	slow_print("Ou pire...", 50, TextColor::RED);
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
        	slow_print(" un adepte du bas-niveau...\n", 50, TextColor::RED);
            return (true);
		}
        std::cout << get_color_code(TextColor::RED)
                  << "Choix invalide. Reessayez.\n"
                  << get_color_code(TextColor::DEFAULT);
    }
}
