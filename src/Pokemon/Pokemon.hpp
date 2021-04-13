#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string.h>
#include "PokeTypes.hpp"
#include "Action.hpp"

namespace PB {

    class Pokemon {
    protected:
        char* _name;
        PokemonTypes _type;
        int _health;
        std::vector<Action*> _actions;
    public:
        Pokemon(char* name, PokemonTypes type, int health);
        ~Pokemon();

        // virtual void attack(Pokemon &p);
        virtual void act(Pokemon& receiver, char* actionName);
        void learn(Action action);
        void forget(char* name);

        void damage(int damage, PokemonTypes type);
        void heal(int amount);

        char* getName() { return _name; };
    };
    
} // namespace PB

#include "Pokemon.cpp"