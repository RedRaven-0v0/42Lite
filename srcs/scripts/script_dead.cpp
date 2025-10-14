#include "game.hpp"

void	script_dead(Hero heros)
{
	std::cout << "\033[2J\033[1;1H";
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	slow_print("Ainsi s'acheve notre histoire\n", 50, TextColor::MAGENTA);
	slow_print("C'etait bien essaye mais tu t'es finalement fait absorber par le ", 50, TextColor::MAGENTA);
	slow_print("blackhole !\n", 333, TextColor::RED);
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	slow_print("Mais n'abandonne jamais " + heros.get_name() + " ! Tu reussiras peut-etre au prochain try !\n", 70, TextColor::MAGENTA);
}

void	script_dead_post_cc(Hero heros)
{
	std::cout << "\033[2J\033[1;1H";
	std::this_thread::sleep_for(std::chrono::milliseconds(2000));
	slow_print("Ainsi s'acheve notre histoire\n", 50, TextColor::MAGENTA);
	slow_print("C'etait bien essaye mais tu t'es finalement fait ", 50, TextColor::MAGENTA);
	slow_print("alumnise !\n", 333, TextColor::RED);
	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	slow_print("Mais n'abandonne jamais " + heros.get_name() + " le transcende ! Tu reussiras peut-etre au prochain try !\n", 70, TextColor::MAGENTA);
}
