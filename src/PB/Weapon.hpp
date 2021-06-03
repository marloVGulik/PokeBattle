#pragma once

#include <string>

namespace PB {
	struct Weapon {
		int weight;
		int damage;
		std::string name;

		Weapon() {
			this->weight = 0;
			this->damage = 6;
			this->name = "hands";
		}
		Weapon(int damage, int weight, const char* name) {
			this->damage = damage;
			this->weight = weight;
			this->name = name;
		}
	};
}

