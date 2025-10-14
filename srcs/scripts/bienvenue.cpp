#include "game.hpp"

static bool to_skip(void)
{
    std::string input;

    while (true)
    {
        slow_print("\n[1] Continuer\n[2] Skip l'intro\n\nVotre choix (1-2) : ", 30, TextColor::YELLOW);
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
            return (false);
		if (is_number && std::stoi(input) == 2)
		{
			slow_print("\nEt ma belle intro alors ?\nSniff sniff\n\n", 50, TextColor::BLUE);
            return (true);
		}
        std::cout << get_color_code(TextColor::RED)
                  << "Choix invalide. Reessayez.\n"
                  << get_color_code(TextColor::DEFAULT);
    }

    std::cout << "\n";
}

void	bienvenue(Hero *heros)
{
	if(!to_skip())
	{
		slow_print("Vendredi soir, l'exam final vient de se terminer :\n", 50, TextColor::YELLOW);
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		slow_print("Par une belle nuit ensoleillee et... apres un ou deux petits verres au Pheno (peut-etre trois) pour feter la fin de piscine.\n", 50, TextColor::YELLOW);
		slow_print("Le piscineux, " + heros->get_name() + " le " + heros->get_class_name() + " decide de rentrer chez lui (enfin) tant qu'il est encore sobre...\n", 50, TextColor::YELLOW);
		slow_print("S'empressant de remettre son couvre-chef, il attrape son sac et se dirige vers la porte de sortie du bar.\n", 50, TextColor::YELLOW);
		slow_print("S'emmelant les pieds, il tombe", 50, TextColor::YELLOW);
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		slow_print(", une fois", 50, TextColor::YELLOW);
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		slow_print(", DEUX FOIS ! ", 40, TextColor::RED);
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		slow_print("(il est rond comme un ballon...).\n", 50, TextColor::YELLOW);
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		slow_print("Puis d'un pas decide il reprend sa marche funambulesque et fini enfin par sortir.\n\n", 50, TextColor::YELLOW);
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		slow_print("Deux semaines plus tard, il recoit un certain mail :", 50, TextColor::YELLOW);
		slow_print(" Cher Cadet...\n\n", 50, TextColor::MAGENTA);
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		slow_print("LE CURSUS PEUT ENFIN COMMENCER, BIENVENUE A 42 !\n\n", 40, TextColor::GREEN);
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	}
	slow_print("Un nouvel etudiant entre dans l'ecole, pret a entrer dans la legende avec cette nouvelle quete : \n", 20, TextColor::YELLOW);
	std::vector<std::string> quetes = {
        "\"Inserer un titre de quete stylee\"",
        "\"Parfait 😄 On va faire ça en deux etapes\"",
        "A la recherche du malloc perdu !",
        "Je t'ai concocte un boss de fin... pepite... eheheheh",
        "Retrouver le petit portugais !",
        "Non mais Salome, c'est quoi c'te main ??",
        "Retrouver le micro #@!&? de Wiwi !",
		"Survivre 3 nuits avec Max !",
        "Ta gueule Leo ! On te dira plus tard...",
		"EH MAIS ON VOIT TA COUILLE AFOUG !"
    };
	std::srand(std::time(nullptr));
    int index = std::rand() % quetes.size();
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
	slow_print(quetes[index] + "\n", 100, TextColor::GREEN);
	to_continue();
}
