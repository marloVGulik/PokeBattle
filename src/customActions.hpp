#include "Pokemon/Action.hpp"

namespace PB {
    class TailWhip : public Action {
    protected:
        char* _name = "Tail whip";
        PokemonTypes _actionType = PokemonTypes::PHYSICAL;
        int _hitpoints = 10;
    public:
        TailWhip() {
            // std::cout << " whips tail\n";
        };
        void act(Pokemon& p) {
            std::cout << _name << "\n";
            p.damage(_hitpoints, _actionType);
        }
    };
}