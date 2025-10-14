#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
#include <cstdlib>

class Character
{
public:
    Character(std::string name);

	Character(std::string name, int hp, int speed, int defense, int shield,
              int atk_damage, int crit_rate, int crit_damage, int dodge_rate);
    virtual ~Character() = default;

    virtual void display_info() const = 0;

	int		attack() const;
    bool	is_crit() const;
    bool	is_dodge() const;
    void	take_damage(int amount);
    bool	is_alive() const; 

    void    set_name(std::string name) { _name = name; }
    void    set_hp(int amount) { _hp += amount; }
    void    set_speed(int amount) { _speed += amount; }
    void    set_defense(int amount)
    {
        _defense += amount;
        if (_defense > 90)
            _defense = 90;
    }
    void    set_shield(int amount) { _shield += amount; }
    void    set_atk_damage(int amount) { _atk_damage += amount; }
    void    set_crit_rate(int amount)
    {
        _crit_rate += amount;
        if (_crit_rate > 90)
            _crit_rate = 90;
    }
    void    set_crit_damage(int amount) { _crit_damage += amount; }
    void    set_dodge_rate(int amount)
    {
        _dodge_rate += amount;
        if (_dodge_rate > 90)
            _dodge_rate = 90;
    }

    std::string get_name() const { return _name; }
    int get_hp() const { return _hp; }
    int get_speed() const { return _speed; }
    int get_defense() const { return _defense; }
    int get_shield() const { return _shield; }
    int get_atk_damage() const { return _atk_damage; }
    int get_crit_rate() const { return _crit_rate; }
    int get_crit_damage() const { return _crit_damage; }
    int get_dodge_rate() const { return _dodge_rate; }

protected:
    std::string _name;
    int			_hp;
	int			_speed;
	int			_defense;
	int			_shield;
	int			_atk_damage;
	int			_crit_rate;
	int			_crit_damage;
	int			_dodge_rate;
};

# endif
