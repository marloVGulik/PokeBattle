#pragma once

namespace PB {
    char* PokemonTypeNames[6] = {
        "fire",
        "water",
        "ice",
        "lightning",
        "ground",
        "physical"
        };
    enum PokemonTypes {
        FIRE,
        WATER,
        ICE,
        LIGHTNING,
        GROUND,
        PHYSICAL
    };
    PokemonTypes getTypeFromString(char* name) {
        for(int i = 0; i < 6; i++) {
            if(!strcmp(name, PokemonTypeNames[i])) {
                std::cout << "Found! Number: " << i << "\n";
                return static_cast<PokemonTypes>(i);
                break;
            }
        }
    }
} // namespace PB
