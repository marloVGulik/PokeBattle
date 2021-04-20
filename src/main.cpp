#include "main.hpp"

#include "Pokemon/Pokemon.hpp"
#include "customActions.hpp"

#include "Game.hpp"

#include "tools/list.hpp"

namespace PB {
    class Action;
}

int main(int argc, char** argv) {
    std::cout << "      ___           ___           ___           ___           ___     \n";
    std::cout << "     /\\  \\         /\\  \\         /\\  \\         /\\  \\         /\\__\\    \n";
    std::cout << "    /::\\  \\       /::\\  \\       /::\\  \\       /::\\  \\       /:/  /    \n";
    std::cout << "   /:/\\:\\  \\     /:/\\:\\  \\     /:/\\:\\  \\     /:/\\ \\  \\     /:/  /     \n";
    std::cout << "  /:/  \\:\\  \\   /::\\~\\:\\  \\   /::\\~\\:\\  \\   _\\:\\~\\ \\  \\   /:/  /  ___ \n";
    std::cout << " /:/__/ \\:\\__\\ /:/\\:\\ \\:\\__\\ /:/\\:\\ \\:\\__\\ /\\ \\:\\ \\ \\__\\ /:/__/  /\\__\\\n";
    std::cout << " \\:\\  \\  \\/__/ \\/_|::\\/:/  / \\:\\~\\:\\ \\/__/ \\:\\ \\:\\ \\/__/ \\:\\  \\ /:/  /\n";
    std::cout << "  \\:\\  \\          |:|::/  /   \\:\\ \\:\\__\\    \\:\\ \\:\\__\\    \\:\\  /:/  / \n";
    std::cout << "   \\:\\  \\         |:|\\/__/     \\:\\ \\/__/     \\:\\/:/  /     \\:\\/:/  /  \n";
    std::cout << "    \\:\\__\\        |:|  |        \\:\\__\\        \\::/  /       \\::/  /   \n";
    std::cout << "     \\/__/         \\|__|         \\/__/         \\/__/         \\/__/    \n\n\n";
    
    std::cout << "PokeBattle C++ V1\n";

    // PB::Pokemon pikachu = PB::Pokemon("Pikachu", PB::PokemonTypes::LIGHTNING, 60);
    // PB::Pokemon charmander = PB::Pokemon("Charmander", PB::PokemonTypes::FIRE, 70);

    // PB::Pokemon* charmeleon = new PB::Pokemon("Charmeleon", PB::PokemonTypes::FIRE, 100);
    // std::cout << charmeleon << "\n";

    // PB::Action tailWhip = PB::Action("Tail whip", PB::PokemonTypes::PHYSICAL, 10);
    // pikachu.learn(tailWhip);
    // pikachu.act(charmander, "Tail whip");

    // charmander.heal(5);

    List<uint32_t> testList(0);
    testList.push(12);
    testList.push(128);
    testList.push(124);
    testList.push(125);
    testList.push(126);
    testList.push(127);
    testList.push(123);

    for(int i = 0; i < testList.size(); i++) {
        std::cout << testList.at(i) << "\n";
    }


    try {
        PB::Game game = PB::Game();
        game.run();
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    

    return 0;
}