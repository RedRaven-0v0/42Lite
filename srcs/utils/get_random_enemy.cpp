#include "game.hpp"

Enemy get_random_enemy_in_level_range(const std::vector<Enemy> &enemies, int min_level, int max_level)
{
    std::vector<Enemy> filtered;
    for (const auto &e : enemies)
    {
        if (e.get_level() >= min_level && e.get_level() <= max_level)
            filtered.push_back(e);
    }
    if (filtered.empty())
    {
        std::cerr << "Aucun ennemi trouvé entre les niveaux "
                  << min_level << " et " << max_level << "." << std::endl;
        return Enemy("Ennemi_inexistant", 0, 1, 1, 0, 0, 0, 0, 0, 0, 0);
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, filtered.size() - 1);
    return filtered[distrib(gen)];
}
