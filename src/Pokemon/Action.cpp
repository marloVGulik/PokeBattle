#include "Action.hpp"

namespace PB
{
    Action::Action() {
        std::cout << "New action (Empty)\n";
    };
    Action::Action(char* name, PokemonTypes type, int hitpoints) {
        _actionType = type;
        _hitpoints = hitpoints;
    }
    
    Action::~Action() {
    }

    int Action::act() {
        // std::cout << "Not implemented!\n";
        return _hitpoints;
    }
} // namespace PB
