#pragma once
#include <iostream>
#include <vector>
#include "Pokemon/Pokemon.hpp"

namespace PB {
    class Game {
    private:
        bool running;
        std::vector<Pokemon> pokemons;
    public:
        Game(/* args */);
        ~Game();

        void run();
    };    
} // namespace Game


#include "Game.cpp"