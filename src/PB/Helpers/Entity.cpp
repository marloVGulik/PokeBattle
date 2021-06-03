#pragma once
#include "Entity.hpp"

namespace PB {
	void Entity::_setDefaults() {
		this->_position = glm::vec2(0, 0);
		this->_health = 100;
		this->_moveSpeed = 5;
		this->_range = 2;
		this->_strength = 5;
		this->_damage = 2;

		this->_currentHealth = this->_health;
	}

	Entity::Entity() {
		_setDefaults();
	}
	Entity::Entity(glm::vec2 position) {
		_setDefaults();
		this->_position = position;
	}	
	Entity::~Entity() {
		std::cout << "Entity was removed!\n";
	}

    void Entity::moveUp() {
        this->_position.y += this->_moveSpeed;
        std::cout << "Moved " << this->_name << " to: (" << this->_position.x << ", " << this->_position.y << ")\n";
    }
    void Entity::moveDown() {
        this->_position.y -= this->_moveSpeed;
        std::cout << "Moved " << this->_name << " to: (" << this->_position.x << ", " << this->_position.y << ")\n";
    }
    void Entity::moveLeft() {
        this->_position.y -= this->_moveSpeed;
        std::cout << "Moved " << this->_name << " to: (" << this->_position.x << ", " << this->_position.y << ")\n";
    }
    void Entity::moveRight() {
        this->_position.x += this->_moveSpeed;
        std::cout << "Moved " << this->_name << " to: (" << this->_position.x << ", " << this->_position.y << ")\n";
    }

	void Entity::damage(Entity& e) {
		std::cout << this->_name << " hit " << e.name() << " for " << this->calculateDamage() << " damage!\n";
		e.receiveDamage(this->calculateDamage());
	}
	void Entity::receiveDamage(int damage) {
		this->_currentHealth -= damage;
		std::cout << this->_name << "'s current health: " << this->_currentHealth << "\n";
	}
	void Entity::receiveHealing(int health) {
		this->_currentHealth += health;
	}

	int Entity::calculateDamage() {
		return (this->_strength * this->_damage);
	}

	glm::vec2 Entity::getPos() {
		return this->_position;
	}
}
