#include "exp_manager.hpp"

const std::string ExpManager::exp_file = "datas/player_data.txt";

int ExpManager::get_total_exp()
{
	std::ifstream file(exp_file);
	if (!file.is_open())
		return 0;

	std::string key;
	int value = 0;
	file >> key >> value;
	return value;
}

void ExpManager::add_exp(int amount)
{
	int current_exp = get_total_exp();
	current_exp += amount;
	std::ofstream file(exp_file, std::ios::trunc);
	if (!file.is_open())
	{
		std::cerr << "Erreur : impossible d'ouvrir " << exp_file << std::endl;
		return;
	}
	file << "EXP_TOTAL " << current_exp << std::endl;
	std::cout << "🎖️  +" << amount << " EXP (total : " << current_exp << ")\n";
}

std::unordered_map<std::string, int> ExpManager::load_unlocks(const std::string &filename)
{
	std::unordered_map<std::string, int> unlocks;
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Erreur : impossible d'ouvrir " << filename << std::endl;
		return unlocks;
	}
	std::string name;
	int exp;
	while (file >> name >> exp)
		unlocks[name] = exp;
	return (unlocks);
}

void ExpManager::display_unlockable_classes(const std::string &filename)
{
	int total_exp = get_total_exp();
	auto unlocks = load_unlocks(filename);
	std::cout << "\n=== 🏅 CLASSES DEBLOQUABLES ===\n";
	for (const auto &[cls, req] : unlocks)
	{
		if (total_exp >= req)
			std::cout << "✅ " << cls << " (Debloquee)\n";
		else
			std::cout << "🔒 " << cls << " (Requiert " << req << " EXP)\n";
	}
	std::cout << std::endl;
}

std::vector<HeroClass> ExpManager::get_unlocked_classes(const std::string &class_file, const std::string &unlock_file)
{
	std::vector<HeroClass> classes;
	std::ifstream file(class_file);
	if (!file.is_open())
	{
		std::cerr << "Erreur : impossible d'ouvrir " << class_file << std::endl;
		return classes;
	}
	auto unlocks = load_unlocks(unlock_file);
	int total_exp = get_total_exp();

	std::string line;
	while (std::getline(file, line))
	{
		if (line.empty() || line[0] == '#')
			continue;

		std::istringstream iss(line);
		HeroClass hc;
		iss >> hc.name >> hc.hp >> hc.speed >> hc.defense >> hc.shield
			>> hc.atk_damage >> hc.crit_rate >> hc.crit_damage >> hc.dodge_rate;

		if (unlocks.find(hc.name) == unlocks.end() || total_exp >= unlocks[hc.name])
			classes.push_back(hc);
	}
	return (classes);
}
