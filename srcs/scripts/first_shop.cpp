#include "game.hpp"

void	first_shop(Hero heros)
{
	std::cout << "\033[2J\033[1;1H";
	slow_print("C'est l'heure de faire un peu d'activite autre que du code !\nIl ne faudrait pas se faire mal a la tete !\nPensez un peu a vous " + heros.get_name() + " ! N'hesitez pas a faire une activite ou a acheter un objet !\n", 50, TextColor::CYAN);
	to_continue();
}