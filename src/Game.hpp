#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Pokemon/Pokemon.hpp"

#include "tools/list.hpp"

namespace PB {
    class Game {
    private:
        bool running;
        std::vector<Pokemon> pokemons;
        std::vector<Action> actions;
    public:
        Game(/* args */);
        ~Game();

        void run();
    };    
} // namespace Game


#include "Game.cpp"