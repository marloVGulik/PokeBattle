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
            std::cout << "Type your action here (ADD, ACT, DEL, QUIT): ";
            char test[256]; 
            std::cin >> test;
            // std::cout << test;
            if(!strncmp(test, "ADD", 3)) {
                std::cout << "What type do you want to add (POK, MOV): ";
                std::cin >> test;
                // std::cout << PokemonTypes::LIGHTNING << "\n";
                // std::cout << getTypeFromString(test);

                if(!strncmp(test, "POK", 3)) {
                    char name[256];
                    PokemonTypes type;
                    int health;

                    std::cout << "Adding Pokemon! Type the name here: ";
                    std::cin >> name;

                    std::cout << "Type the type name here: ";
                    std::cin >> test;
                    type = getTypeFromString(test);

                    std::cout << "Type the amount of health here: ";
                    std::cin >> test;
                    health = std::stoi(test);

                    std::cout << "Adding a Pokemon called " << name << " with " << health << " health!\n";

                    Pokemon p = Pokemon(name, type, health);
                    pokemons.push_back(p);

                    std::cout << "Added pokemon succesfully!\n";
                } else if(!strncmp(test, "MOV", 3)) {
                    char name[256];
                    PokemonTypes type;
                    int damage;

                    std::cout << "Adding a move! Type the name here: ";
                    std::cin >> name;

                    std::cout << "Type the type name here: ";
                    std::cin >> test;
                    type = getTypeFromString(test);

                    std::cout << "Type the amount of damage here: ";
                    std::cin >> test;
                    damage = std::stoi(test);

                    Action a = Action(name, type, damage);
                    actions.push_back(a);
                    
                    std::cout << "Added move succesfully!\n";
                } else if(!strncmp(test, "LEARN", 5)) {
                    std::cout << "\n\nListing all moves! Choose one move to learn\n";
                    for(int i = 0; i < actions.size(); i++) {
                        std::cout << "NUM: " << i << "\t: " << actions[i].getName() << "\n";
                    }

                    int moveToLearn;
                    std::cout << "Choose a number of a move to learn: ";
                    std::cin >> test;
                    moveToLearn = std::stoi(test);

                    for(int j = 0; j < pokemons.size(); j++) {
                        std::cout << "NUM: " << j << "\t: " << pokemons[j].getName() << "\n";
                    }
                    
                    int chosenPokemon;
                    std::cout << "Choose a number of a Pokemon: ";
                    std::cin >> test;
                    chosenPokemon = std::stoi(test);

                    pokemons[chosenPokemon].learn(actions[moveToLearn]);

                    std::cout << "\n" << pokemons[chosenPokemon].getName() << " learned " << actions[moveToLearn].getName() << "!\n";
                }

            } else if(!strncmp(test, "ACT", 3)) {
                std::cout << "OwO\n";

            } else if(!strncmp(test, "DEL", 3)) {
                std::cout << "Ara ara~\n";
            } else if(!strncmp(test, "INFO", 4)) {
                std::cout << "Printing pokemon names...\n\n";
                for(int i = 0; i < pokemons.size(); i++) {
                    std::cout << "Pokemon " << i << ":\t" << pokemons[i].getName();
                }
            } else if(!strncmp(test, "QUIT", 4)) {
                running = false;

            } else {
                std::cout << "Implementation not found! Try again\n";
            }
        }
        
    }
} // namespace PB