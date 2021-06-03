#pragma once

#include <iostream>
#include "Helpers/Entity.hpp"
#include "Weapon.hpp"

namespace PB {
    class Human : public Entity {
    protected:
        Weapon _weapon;
    public:
        Human();
        Human(glm::vec2 pos);
        ~Human();

        void wield(Weapon weapon);
        void drop();

        using Entity::calculateDamage;
        int calculateDamage();
    };
}


#include "Human.cpp"