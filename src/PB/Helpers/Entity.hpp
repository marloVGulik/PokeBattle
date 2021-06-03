#pragma once
#include <glm/glm.hpp>
#include <string>

namespace PB {

	class Entity {
	protected:
        int _moveSpeed;
        int _strength;
		int _damage;
        int _health;
        int _range;

		int _currentHealth;
		glm::vec2 _position;
		std::string _name;

		void _setDefaults();

	public:
		Entity();
		Entity(glm::vec2 position);

		virtual ~Entity();

		glm::vec2 getPos();

		
        void moveLeft();
        void moveUp();
        void moveDown();
        void moveRight();

		void damage(Entity& e);

		void receiveDamage(int damage);
		void receiveHealing(int health);

		virtual int calculateDamage();

		void name(const char* name) { this->_name = name; };
		const char* name() { return this->_name.c_str(); };
	};

}

#include "Entity.cpp"
