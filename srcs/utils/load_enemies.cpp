#include "game.hpp"

std::vector<Enemy> load_enemies_from_file(const std::string &filename)
{
    std::vector<Enemy> enemies;
    std::ifstream file(filename);

    if (!file.is_open())
    {
        std::cerr << "Erreur : impossible d'ouvrir le fichier " << filename << std::endl;
        return (enemies);
    }
    std::string line;
    while (std::getline(file, line))
    {
        if (line.empty() || line[0] == '#')
            continue;
        std::istringstream iss(line);
        std::string name;
        int level, hp, speed, defense, shield;
        int atk_damage, crit_rate, crit_damage, dodge_rate, reward;
        if (!(iss >> name >> level >> hp >> speed >> defense >> shield
                  >> atk_damage >> crit_rate >> crit_damage >> dodge_rate >> reward))
        {
            std::cerr << "Erreur de format dans la ligne : " << line << std::endl;
            continue;
        }
        enemies.emplace_back(name, level, hp, speed, defense, shield,
                             atk_damage, crit_rate, crit_damage, dodge_rate, reward);
    }
    file.close();
    return (enemies);
}
