#pragma once

#include "Human.hpp"

namespace PB {
    Human::Human() {
        this->_weapon = Weapon();
        // std::cout << "Human created\n";
        // Entity();
    }
    Human::Human(glm::vec2 pos) : Entity(pos) {
        this->_weapon = Weapon();
        // std::cout << "Human created\n";
    }
    
    Human::~Human() {
        // std::cout << "Human removed\n";
    }

    void Human::wield(Weapon weapon) {
        if(weapon.weight <= this->_strength) {
            this->_weapon = weapon;
        }
    }
    void Human::drop() {
        this->_weapon = Weapon();
    }

    int Human::calculateDamage() {
        return (this->_strength * (this->_damage + this->_weapon.damage) / 1.5);
    }
}