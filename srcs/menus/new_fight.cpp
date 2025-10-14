#include "game.hpp"

static void	display_enemy_compact(const Enemy &enemy)
{
    std::cout << std::setw(20) << std::left << enemy.get_name();
    std::cout << "Lvl: " << std::setw(3) << enemy.get_level()
              << " PV: " << std::setw(4) << enemy.get_hp()
              << " ATK: " << std::setw(4) << enemy.get_atk_damage()
              << " DEF: " << std::setw(3) << enemy.get_defense()
              << "\n";
}

void    precise_fight(Hero *heros, const std::vector<Enemy> &Enemies, const std::string &name)
{
    std::cout << "\033[2J\033[1;1H";
    Enemy selected = Enemy("Inconnu", 1, 1, 1, 0, 1, 0, 0, 0, 0, 0);
    bool found = false;

    for (const auto &enemy : Enemies)
    {
        if (enemy.get_name() == name)
        {
            selected = enemy;
            found = true;
            break;
        }
    }
    if (!found)
    {
        std::cout << get_color_code(TextColor::RED)
                  << "Ennemi \"" << name << "\" introuvable dans la base de donnees.\n"
                  << get_color_code(TextColor::DEFAULT);
        return;
    }
    auto_battle(*heros, selected);
}

void	new_fight(Hero *heros, std::vector<Enemy> Enemies, int min_level, int max_level)
{
    std::cout << "\033[2J\033[1;1H";
	std::vector<int> valid_indices;
    for (size_t i = 0; i < Enemies.size(); ++i)
    {
        int lvl = Enemies[i].get_level();
        if (lvl >= min_level && lvl <= max_level)
            valid_indices.push_back(i);
    }
    if (valid_indices.empty() || valid_indices.size() < 3)
    {
        std::cout << "Aucun ennemi trouve dans cette fourchette de niveaux (" 
                  << min_level << "-" << max_level << ")\n";
        return;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    slow_print("\nUne nouvelle epreuve s'offre a vous :\n", 30, TextColor::GREEN);
    std::vector<Enemy> choices;
    std::unordered_set<int> used_indices;
    int available = std::min(3, (int)valid_indices.size());
    while ((int)choices.size() < available)
    {
        int rand_index = valid_indices[rand() % valid_indices.size()];
        if (used_indices.insert(rand_index).second)
            choices.push_back(Enemies[rand_index]);
    }
    std::cout << get_color_code(TextColor::GREEN);
	std::cout << "\n=== 👤 Rappel de votre Etudiant ===\n";
    std::cout << get_color_code(TextColor::YELLOW);
    std::cout << "Nom : " << heros->get_name()
              << " | PV : " << heros->get_hp() << "/" << heros->get_max_hp()
              << " | ATK : " << heros->get_atk_damage()
              << " | DEF : " << heros->get_defense() << "%"
              << "\n\n";
    std::cout << get_color_code(TextColor::RED);
	std::cout << "=== 👹 Choisissez votre adversaire ===\n\n";
    std::cout << get_color_code(TextColor::MAGENTA);
	std::cout << std::left;
    std::cout << std::setw(4) << "#" 
              << std::setw(20) << "Nom"
              << std::setw(10) << "Niveau"
              << std::setw(10) << "PV"
              << std::setw(10) << "ATK"
              << std::setw(10) << "DEF"
              << "\n";
    std::cout << get_color_code(TextColor::CYAN);
    std::cout << "------------------------------------------------------------\n";
    std::cout << get_color_code(TextColor::YELLOW);
	for (int i = 0; i < 3; i++)
    {
        std::cout << std::setw(4) << (i + 1)
                  << std::setw(20) << choices[i].get_name()
                  << std::setw(10) << choices[i].get_level()
                  << std::setw(10) << choices[i].get_hp()
                  << std::setw(10) << choices[i].get_atk_damage()
                  << std::setw(10) << choices[i].get_defense()
                  << "\n";
    }
    std::cout << get_color_code(TextColor::CYAN);
    std::cout << "------------------------------------------------------------\n";
	int choix = 0;
    std::string input;
    while (choix < 1 || choix > 3)
    {
        std::cout << get_color_code(TextColor::YELLOW);
        std::cout << "\nQui voulez-vous affronter (1-3) ? ";
        std::cout << get_color_code(TextColor::DEFAULT);
		enableInput();
        std::getline(std::cin, input);
		disableInput();
        input.erase(0, input.find_first_not_of(" \t\r\n"));
        input.erase(input.find_last_not_of(" \t\r\n") + 1);
        bool is_number = !input.empty() && std::all_of(input.begin(), input.end(), ::isdigit);
        if (is_number)
        {
            choix = std::stoi(input);
            if (choix >= 1 && choix <= available)
                break;
        }
        std::cout << get_color_code(TextColor::RED)
                  << "Choix invalide. Reessayez.\n"
                  << get_color_code(TextColor::DEFAULT);
    }
    Enemy selected = choices[choix - 1];
    std::cout << "\n🗡️  Tu as choisi d'affronter : " << selected.get_name()
              << " (Niveau " << selected.get_level() << ")\n";
    auto_battle(*heros, selected);
}
