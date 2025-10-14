#include "game.hpp"

std::vector<Upgrades> load_upgrades_from_file(const std::string &filename)
{
	std::vector<Upgrades> upgrades;
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Erreur : impossible d'ouvrir le fichier " << filename << std::endl;
		return (upgrades);
	}
	std::string line;
	while (std::getline(file, line))
	{
		if (line.empty() || line[0] == '#')
			continue;
		std::istringstream iss(line);
		std::string name;
		int cost, hp, speed, defense, shield;
		int atk_damage, crit_rate, crit_damage, dodge_rate, reward;
		if (!(iss >> name >> cost >> hp >> speed >> defense >> shield
				  >> atk_damage >> crit_rate >> crit_damage >> dodge_rate >> reward))
		{
			std::cerr << "Erreur de format dans la ligne : " << line << std::endl;
			continue;
		}
		upgrades.emplace_back(name, hp, speed, defense, shield,
							  atk_damage, crit_rate, crit_damage, dodge_rate,
							  cost, reward);
	}
	file.close();
	return (upgrades);
}
