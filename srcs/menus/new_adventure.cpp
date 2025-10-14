#include "game.hpp"

static bool check_death(Hero *heros)
{
	if (!heros->is_alive())
	{
		script_dead(*heros);
		return (true);
	}
	return (false);
}

static bool check_death_post_cc(Hero *heros)
{
	if (!heros->is_alive())
	{
		script_dead_post_cc(*heros);
		return (true);
	}
	return (false);
}

void	new_adventure(Hero *heros, std::vector<Enemy> Enemies, std::vector<Upgrades> upgrades)
{
	bienvenue(heros);
	new_fight(heros, Enemies, 1, 2);
	if (check_death(heros))
		return ;
	new_fight(heros, Enemies, 1, 2);
	if (check_death(heros))
		return ;
	first_rest(*heros);
	rest(heros, upgrades);
	new_fight(heros, Enemies, 2, 3);
	if (check_death(heros))
		return ;
	first_shop(*heros);
	shop(heros, upgrades);
	if (check_death(heros))
		return ;
	new_fight(heros, Enemies, 2, 4);
	if (check_death(heros))
		return ;
	rest(heros, upgrades);
	new_fight(heros, Enemies, 3, 4);
	if (check_death(heros))
		return ;
	shop(heros, upgrades);
	if (check_death(heros))
		return ;
	mid_fight_script(*heros);
	precise_fight(heros, Enemies, "minishell");
	if (check_death(heros))
		return ;
	rest(heros, upgrades);
	shop(heros, upgrades);
	if (check_death(heros))
		return ;
	new_fight(heros, Enemies, 6, 7);
	if (check_death(heros))
		return ;
	new_fight(heros, Enemies, 6, 8);
	if (check_death(heros))
		return ;
	rest(heros, upgrades);
	new_fight(heros, Enemies, 8, 10);
	if (check_death(heros))
		return ;
	rest(heros, upgrades);
	shop(heros, upgrades);
	if (check_death(heros))
		return ;
	final_fight_script(*heros);
	precise_fight(heros, Enemies, "Transcende");
	if (check_death(heros))
		return ;
	if (victory_script(heros))
		return ;
	precise_fight(heros, Enemies, "Anaconda_de_Maxence");
	if (check_death_post_cc(heros))
		return ;
	infinite_adventure(heros, &Enemies, upgrades);
}

void	infinite_adventure(Hero *heros, const std::vector<Enemy> *baseEnemies, std::vector<Upgrades> &upgrades)
{
	int loop_count = 1;

	while (true)
	{
		std::vector<Enemy> Enemies = *baseEnemies;
		int level_increase = loop_count * 10;
		float stat_multiplier = 1.0f + (loop_count * 1.0f);
		for (auto &enemy : Enemies)
		{
			enemy.change_level(enemy.get_level() + level_increase);
			enemy.set_hp(enemy.get_hp() * stat_multiplier);
			enemy.set_atk_damage(enemy.get_atk_damage() * stat_multiplier);
			enemy.set_crit_damage(enemy.get_crit_damage() * (1.0f + loop_count * 0.5f));
		}
		if (7 + loop_count == 18)
		{
			slow_print("Bien joue ! Vous avez atteint le niveau 17, vous obtenez le RNCP 6 !\n", 40, TextColor::GREEN);
		}
		else if (7 + loop_count == 22)
		{
			slow_print("Bien joue ! Vous avez atteint le niveau 21, vous obtenez le RNCP 7 !\n", 40, TextColor::GREEN);
		}
		slow_print("\n--- 🌋 Niveau +1 (" + std::to_string(7 + loop_count) + ") ---\n", 40, TextColor::MAGENTA);
		std::this_thread::sleep_for(std::chrono::milliseconds(800));
		new_fight(heros, Enemies, 1 + level_increase, 2 + level_increase);
		if (check_death_post_cc(heros)) return;
		new_fight(heros, Enemies, 1 + level_increase, 2 + level_increase);
		if (check_death_post_cc(heros)) return;
		rest(heros, upgrades);
		new_fight(heros, Enemies, 2 + level_increase, 3 + level_increase);
		if (check_death_post_cc(heros)) return;
		shop(heros, upgrades);
		if (check_death_post_cc(heros)) return;
		new_fight(heros, Enemies, 2 + level_increase, 4 + level_increase);
		if (check_death_post_cc(heros)) return;
		rest(heros, upgrades);
		new_fight(heros, Enemies, 3 + level_increase, 4 + level_increase);
		if (check_death_post_cc(heros)) return;
		shop(heros, upgrades);
		if (check_death_post_cc(heros)) return;
		precise_fight(heros, Enemies, "minishell");
		if (check_death_post_cc(heros)) return;
		rest(heros, upgrades);
		shop(heros, upgrades);
		if (check_death_post_cc(heros)) return;
		new_fight(heros, Enemies, 6 + level_increase, 7 + level_increase);
		if (check_death_post_cc(heros)) return;
		new_fight(heros, Enemies, 6 + level_increase, 8 + level_increase);
		if (check_death_post_cc(heros)) return;
		rest(heros, upgrades);
		new_fight(heros, Enemies, 8 + level_increase, 10 + level_increase);
		if (check_death_post_cc(heros)) return;
		rest(heros, upgrades);
		shop(heros, upgrades);
		if (check_death_post_cc(heros)) return;
		precise_fight(heros, Enemies, "Transcende");
		if (check_death_post_cc(heros)) return;
		loop_count++;
	}
}
