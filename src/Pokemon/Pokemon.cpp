#include "Pokemon.hpp"

namespace PB {
    Pokemon::Pokemon(char* name, PokemonTypes type, int health) {
        _name = name;
        _type = type;
        _health = health;
        // _attackDamage = attack;

        std::cout << "New Pokemon: " << name << "\n";
    }
    Pokemon::~Pokemon() {
        delete _name;
    }

    // void Pokemon::attack(Pokemon &p) {
    //     p.damage(_attackDamage, _type);
    // }
    void Pokemon::act(Pokemon& receiver, char* actionName) {
        for(int i = 0; i < _actions.size(); i++) {
            std::cout << "Checking " << _actions[i]->getName() << " to " << actionName << "\n";
            if(strcmp(_actions[i]->getName(), actionName)) {
                receiver.damage(_actions[i]->act(), _actions[i]->getType());
                break;
            }
        }
    }
    void Pokemon::learn(Action action) {
        _actions.push_back(&action);
    }
    void Pokemon::damage(int damage, PokemonTypes type) {
        int receiveDamage = damage;
        switch (type)
        {
        case PokemonTypes::FIRE:
            receiveDamage *= 1.25;
            break;
        case PokemonTypes::WATER:
            receiveDamage *= 0.75;
            break;
        default:
            receiveDamage *= 1;
            break;
        }
        _health -= receiveDamage;
        std::cout << _name << " received " << receiveDamage << " damage!\n";
    }
    void Pokemon::heal(int amount) {
        std::cout << _name << " healed " << amount << " health!\n";
        _health += amount;
    }
} // namespace PB
