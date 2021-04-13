#pragma once
#include "PokeTypes.hpp"
#include "Pokemon.hpp"

namespace PB
{
    class Pokemon;

    class Action {
    protected:
        char* _name;
        PokemonTypes _actionType;
        int _hitpoints;
    public:
        Action();
        Action(char* name, PokemonTypes type, int hitpoints);
        ~Action();

        int act();
        char* getName() { return _name; };
        PokemonTypes getType() { return _actionType; };
    };    
} // namespace PB

#include "Action.cpp"