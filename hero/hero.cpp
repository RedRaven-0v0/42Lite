#include "hero.hpp"
#include "game.hpp"

Hero::Hero(std::string name)
	: Character(name)
{
	_max_hp = _hp;
	_amount_golds = 100;
}

Hero::Hero(std::string name, int hp, int speed, int defense, int shield,
		   int atk_damage, int crit_rate, int crit_damage, int dodge_rate,
		   int amount_golds)
	: Character(name, hp, speed, defense, shield, atk_damage, crit_rate, crit_damage, dodge_rate)
{
	_max_hp = hp;
	_amount_golds = amount_golds;
}

void Hero::display_info() const
{
	slow_print("=== ETUDIANT ===\n", 0, TextColor::CYAN);
	slow_print("Nom : " + _name + "\n", 0, TextColor::YELLOW);
	slow_print("Classe : " + _class_name + "\n", 0, TextColor::YELLOW);
	slow_print("PV : " + std::to_string(_hp) + "/" + std::to_string(_max_hp) + "\n", 0, TextColor::YELLOW);
	slow_print("Bouclier : " + std::to_string(_shield) + "\n", 0, TextColor::YELLOW);
	slow_print("Attaque : " + std::to_string(_atk_damage) + "\n", 0, TextColor::YELLOW);
	slow_print("Defense : " + std::to_string(_defense) + "%\n", 0, TextColor::YELLOW);
	slow_print("Vitesse : " + std::to_string(_speed) + "\n", 0, TextColor::YELLOW);
	slow_print("Taux critique : " + std::to_string(_crit_rate) + "%\n", 0, TextColor::YELLOW);
	slow_print("Degats critiques : " + std::to_string(_crit_damage) + "\n", 0, TextColor::YELLOW);
	slow_print("Taux d'esquive : " + std::to_string(_dodge_rate) + "%\n", 0, TextColor::YELLOW);
	slow_print("Or : " + std::to_string(_amount_golds) + "\n\n", 0, TextColor::YELLOW);
}

void	Hero::heal(int amount)
{
	int old_hp;
	
	old_hp = _hp;
	_hp += amount;
	if (_hp > _max_hp)
	{
		_hp = _max_hp;
	}
	std::cout << get_color_code(TextColor::GREEN);
	std::cout << _name << " recupere " << (_hp - old_hp)
			  << " PV (" << _hp << "/" << _max_hp << " PV)" << std::endl;
	std::cout << get_color_code(TextColor::DEFAULT);
}

static std::string	print_ability_chomeur()
{
	std::vector<std::string> quote = {
        "\"J'ai bien besoin d'une pause.\"\n",
		"\"On est le 28 ? Faut s'actualiser !\"\n",
		"\"Mon canape me maaaaanque...\"\n",
		"\"Cette fois-ci ca va le faire !\"\n",
		"\"J'ai besoin d'un boulot...\"\n"
    };
	std::srand(std::time(nullptr));
    int index = std::rand() % quote.size();
	return (quote[index]);
}

static std::string	print_ability_lyceen()
{
	std::vector<std::string> quote = {
        "\"Puree, toujours pas 17h ! Ah non, c'est vrai...\"\n",
		"\"Ils sont ou les profs ???\"\n",
		"\"Heureusement que j'ai fait info...\"\n",
		"\"C'est pas du python ???\"\n",
		"\"J'espere qu'ils ont des frites a la cantine !\"\n"
    };
	std::srand(std::time(nullptr));
    int index = std::rand() % quote.size();
	return (quote[index]);
}

static std::string	print_ability_sportif()
{
	std::vector<std::string> quote = {
        "\"Il faut que j'aille a la salle ce soir.\"\n",
		"\"J'ai besoin de plus de prots !\"\n",
		"\"Encore 3 tours de terrain.\"\n",
		"\"NO PAIN, NO GAIN !\"\n",
		"\"Moi taper ballooon\"\n"
    };
	std::srand(std::time(nullptr));
    int index = std::rand() % quote.size();
	return (quote[index]);
}

static std::string	print_ability_cuistot()
{
	std::vector<std::string> quote = {
        "\"Ca avec un peu de sel, ca s'mange !\"\n",
		"\"Stop au gaspi !\"\n",
		"\"Je vais cracher dans ta soupe !\"\n",
		"\"Un soupcon de poivre pour ces gourmets ?\"\n",
		"\"Mais c'est pas la saison ??!\"\n"
    };
	std::srand(std::time(nullptr));
    int index = std::rand() % quote.size();
	return (quote[index]);
}

static std::string	print_ability_graphiste()
{
	std::vector<std::string> quote = {
        "\"Stylee cette animation !\"\n",
		"\"Le bas-ni... quoi ?\"\n",
		"\"J'aurais fait plus beau\"\n",
		"\"Mais elle est ou la fenetre graphiqueee ?\"\n",
		"\"Pas de fenetre graphique ? Je ne joue pas !\"\n",
		"\"Mais que c'est laid !\"\n"
    };
	std::srand(std::time(nullptr));
    int index = std::rand() % quote.size();
	return (quote[index]);
}

static std::string	print_ability_historien()
{
	std::vector<std::string> quote = {
        "\"Il y a du lore ?\"\n",
		"\"J'ai besoin d'images svp.\"\n",
		"\"Ca fait un an que je buche dessus !\"\n",
		"\"Il y a longtemps, ce n'etait pas comme ca...\"\n"
    };
	std::srand(std::time(nullptr));
    int index = std::rand() % quote.size();
	return (quote[index]);
}

static std::string	print_ability_electronicien()
{
	std::vector<std::string> quote = {
        "\"J'ai juste besoin d'un oscillo.\"\n",
		"\"Nan mais ca doit etre un probleme hardware...\"\n",
		"\"T'es sur que c'est bien branche ?\"\n",
		"\"Il y a comme un bruit bizarre...\"\n",
		"\"C'est quoi cette odeur de brule ?\"\n"
    };
	std::srand(std::time(nullptr));
    int index = std::rand() % quote.size();
	return (quote[index]);
}

static std::string	print_ability_surfeur()
{
	std::vector<std::string> quote = {
        "\"Beaux pieds ! Tu fais gouter ?"\n",
		"\"Yo le gourmandinier tenebreux !\"\n",
		"\"Oh noooo, my big cranium !!!\"\n",
		"\"J'me tire en Grece les gens !\"\n"
    };
	std::srand(std::time(nullptr));
    int index = std::rand() % quote.size();
	return (quote[index]);
}

static std::string	print_ability_sudiste()
{
	std::vector<std::string> quote = {
        "\"Tranquiiiiiille on a le temps !\"\n",
		"\"P'tite binouze ?\"\n",
		"\"Ca vient faire un plouf dans la piscine ?\"\n",
		"\"J'vais t'mettre dans la poubelle !\"\n",
		"\"Gouuuuuuurmand va !\"\n"
    };
	std::srand(std::time(nullptr));
    int index = std::rand() % quote.size();
	return (quote[index]);
}

void	Hero::ability(void)
{
	switch (_class_name)
	{
		case "Chomeur":
			slow_print(print_ability_chomeur(), 30, TextColor::DEFAULT);
			break ;
		case "Lyceen":
			slow_print(print_ability_lyceen(), 30, TextColor::DEFAULT);
			break ;
		case "Sportif":
			slow_print(print_ability_sportif(), 30, TextColor::DEFAULT);
			break ;
		case "Cuistot":
			slow_print(print_ability_cuistot(), 30, TextColor::DEFAULT);
			break ;
		case "Graphiste":
			slow_print(print_ability_graphiste(), 30, TextColor::DEFAULT);
			break ;
		case "Historien":
			slow_print(print_ability_historien(), 30, TextColor::DEFAULT);
			break ;
		case "Electronicien":
			slow_print(print_ability_electronicien(), 30, TextColor::DEFAULT);
			break ;
		case "Surfeur":
			slow_print(print_ability_surfeur(), 30, TextColor::DEFAULT);
			break ;
		case "Sudiste":
			slow_print(print_ability_sudiste(), 30, TextColor::DEFAULT);
			break ;
		default :
			break ;
	}

}
