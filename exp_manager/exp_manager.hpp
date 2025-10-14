#ifndef EXP_MANAGER_HPP
#define EXP_MANAGER_HPP

#include "game.hpp"
#include <unordered_map>
#include <vector>

class ExpManager
{
public:
	static int get_total_exp();
	static void add_exp(int amount);
	static std::unordered_map<std::string, int> load_unlocks(const std::string &filename);
	static void display_unlockable_classes(const std::string &filename);
	static std::vector<HeroClass> get_unlocked_classes(const std::string &class_file, const std::string &unlock_file);

private:
	static const std::string exp_file;
};

#endif
