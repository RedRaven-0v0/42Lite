#include "game.hpp"

int	main()
{
	disableInput();
	Hero myHero = create_hero_from_file("datas/hero.txt");
	std::vector<Enemy> Enemies = load_enemies_from_file("datas/enemies.txt");
	if (!Enemies.size())
		return (1);
	std::vector<Upgrades> Upgrades = load_upgrades_from_file("datas/upgrades.txt");
	if (!Upgrades.size())
		return (1);
	new_adventure(&myHero, Enemies, Upgrades);
	return (0);
}