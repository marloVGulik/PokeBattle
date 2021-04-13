#include "Game.hpp"
namespace PB {
    Game::Game(/* args */) {
        std::cout << "Starting game!\n";
    }
    
    Game::~Game() {
        std::cout << "Shutting down....\n";
    }

    void Game::run() {
        running = true;
        while (running) {
            std::cout << "Type your action here (ADD, ACT, DEL): ";
            char test[256]; 
            std::cin >> test;
            std::cout << test;
        }
        
    }
} // namespace PB