#include "game.hpp"

void	first_rest(Hero heros)
{
	std::cout << "\033[2J\033[1;1H";
	slow_print("Entre chaque epreuve, vous meritez bien une petite pause " + heros.get_name() + ".\n\n", 30, TextColor::MAGENTA);
}