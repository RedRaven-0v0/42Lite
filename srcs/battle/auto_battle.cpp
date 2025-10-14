#include "game.hpp"

void auto_battle(Hero &hero, Enemy &enemy)
{
    slow_print("\nUn ennemi approche...\n", 25, TextColor::YELLOW);
    slow_print("C'est " + enemy.get_name() + " (Level " + std::to_string(enemy.get_level()) + ")\n", 25, TextColor::MAGENTA);
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    display_side_by_side(hero, enemy);
    to_continue();
    std::cout << "\033[2J\033[1;1H";

    Character *first;
    Character *second;

    if (hero.get_speed() >= enemy.get_speed())
    {
        first = &hero;
        second = &enemy;
    }
    else
    {
        first = &enemy;
        second = &hero;
    }
    slow_print(first->get_name() + " est plus rapide !\n", 30, TextColor::YELLOW);
    int turn = 1;
    while (hero.is_alive() && enemy.is_alive())
    {
        slow_print("=== Tour " + std::to_string(turn) + " ===\n", 15, TextColor::CYAN);
        int dmg = first->attack();
        if (!second->is_dodge())
            second->take_damage(dmg);
        if (!second->is_alive())
            break;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        dmg = second->attack();
        if (!first->is_dodge())
            first->take_damage(dmg);
        std::this_thread::sleep_for(std::chrono::milliseconds(2500));
        turn++;
    }
    slow_print("\n=== Fin du combat ===\n", 30, TextColor::CYAN);
    if (hero.is_alive())
    {
        slow_print("Victoire ! Tu as vaincu " + enemy.get_name() + " !\n", 25, TextColor::GREEN);
        slow_print("Tu gagnes ", 25, TextColor::YELLOW);
        slow_print(std::to_string(enemy.get_gold_reward()), 25, TextColor::BLUE);
        slow_print(" pieces d'or. (" + std::to_string(hero.get_amount_golds() + enemy.get_gold_reward()) + " d'or)\n", 25, TextColor::YELLOW);
        hero.change_golds(enemy.get_gold_reward());
    }
    else
        slow_print("Tu as ete vaincu par " + enemy.get_name() + "...\n", 25, TextColor::RED);
    to_continue();
}
