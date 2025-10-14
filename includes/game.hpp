#ifndef GAME_H
#define GAME_H

#include "includes.hpp"

Hero					create_hero_from_file(const std::string &filename);
std::vector<Enemy>		load_enemies_from_file(const std::string &filename);
std::vector<Upgrades>	load_upgrades_from_file(const std::string &filename);
void					to_continue(void);
void					disableInput(void);
void					enableInput(void);
Enemy					get_random_enemy_in_level_range(const std::vector<Enemy> &enemies, int min_level, int max_level);
void					display_side_by_side(const Hero &hero, const Enemy &enemy);
void					bienvenue(Hero *hero);
void					first_shop(Hero heros);
void					first_rest(Hero heros);
void					mid_fight_script(Hero heros);
void					final_fight_script(Hero heros);
bool					victory_script(Hero *heros);
void					script_dead(Hero heros);
void					script_dead_post_cc(Hero heros);
void					slow_print(const std::string &text, int delay_ms, TextColor color);
std::string				get_color_code(TextColor color);
void					auto_battle(Hero &hero, Enemy &enemy);
void					new_adventure(Hero *hero, std::vector<Enemy> Enemies, std::vector<Upgrades> upgrades);
void					infinite_adventure(Hero *heros, const std::vector<Enemy> *baseEnemies, std::vector<Upgrades> &upgrades);
void					new_fight(Hero *heros, std::vector<Enemy> Enemies, int min_level, int max_level);
void					precise_fight(Hero *heros, const std::vector<Enemy> &Enemies, const std::string &name);
void					final_fight(Hero heros, std::vector<Enemy> Enemies);
void					rest(Hero *heros, std::vector<Upgrades> upgrades);
void					shop(Hero *heros, std::vector<Upgrades> &all_upgrades);


# endif