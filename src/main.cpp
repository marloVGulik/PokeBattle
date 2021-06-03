#include <iostream>

#include "PB/Helpers/Entity.hpp"

#include "PB/Human.hpp"
#include "PB/Runner.hpp"

#include "PB/Weapon.hpp"

#include "PB/World/World.hpp"

#include "string.h"


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

	// PB::Entity testEntity = PB::Entity(glm::vec2(12, 23));

	// std::cout << "(" << testEntity.getPos().x << ", " << testEntity.getPos().y << ")\n";



	
	// testHuman.wield(dagger);



	


	// testHuman.damage(testRunner);
	
	// PB::World::addEntity(&testHuman);
	// PB::World::addEntity(&testRunner);


	// std::cout << "Human 1 pointer: " << &testRunner << "\n";
	// std::cout << "Human 1 pointer in class: " << PB::World::getEntityFromName("Runner 1") << "\n";
	
	PB::Human testHuman = PB::Human(glm::vec2(10, 10));
	testHuman.name("Human_1");
	PB::Runner testRunner = PB::Runner(glm::vec2(5, 13));
	testRunner.name("Runner_1");
	
	PB::Weapon dagger = PB::Weapon(12, 1, "dagger");
	
	PB::World::addWeapon(&dagger);
	PB::World::addEntity(&testHuman);
	PB::World::addEntity(&testRunner);

	bool running = true;
	PB::Entity* selectedEntity;
	PB::Weapon* selectedWeapon;

	while (running) 
	{ 
		char input[16];
		std::cin >> input;

		if(!strncmp("q", input, 16)) 
		{
			std::cout << "Quitting!\n";
			running = false;
		}
		
		if(!strncmp("add", input, 16)) 
		{
			std::cout << "Adding entity or weapon: ";
			std::cin >> input;

			if(!strncmp("entity", input, 16)) 
			{
				std::cout << "What do you want to add? (human, runner): ";
				std::cin >> input;
				PB::Entity* newEntity;

				if(!strncmp("human", input, 16)) 
				{
					std::cout << "Adding human!\nType a name here: ";
					newEntity = new PB::Human();
				} 
				else if(!strncmp("runner", input, 16)) 
				{
					std::cout << "Adding runner!\n Type a name here: ";
					newEntity = new PB::Runner();
				}

				std::cin >> input;
				newEntity->name(input);
				// newEntity->name(static_cast<const char*>(input));

				PB::World::addEntity(newEntity);
			} 
			else if(!strncmp("weapon", input, 16)) 
			{
				PB::Weapon* newWeapon = new PB::Weapon();

				std::cout << "Type weapon name: ";
				std::cin >> input;
				newWeapon->name = std::string(input);

				std::cout << "Type weapon damage: ";
				std::cin >> input;
				newWeapon->damage = std::stoi(input);

				std::cout << "Type weapon weight: ";
				std::cin >> input;
				newWeapon->weight = std::stoi(input);

				PB::World::addWeapon(newWeapon);
			}
		}

		if(!strncmp("select", input, 16)) 
		{
			std::cout << "What needs to be selected? (entity, weapon): ";
			std::cin >> input;

			if(!strncmp("entity", input, 16)) 
			{
				std::cout << "Type the name of the entity here: ";
				std::cin >> input;
				PB::Entity* tmpEntityPtr = PB::World::getEntityFromName(input);

				if(tmpEntityPtr != nullptr) 
				{
					selectedEntity = tmpEntityPtr;
					std::cout << "Succesfully selected " << tmpEntityPtr->name() << "\n";
				}
			}
			else if(!strncmp("weapon", input, 16)) 
			{
				std::cout << "Type the name of the weapon here: ";
				std::cin >> input;
				PB::Weapon* tmpWeaponPtr = PB::World::getWeaponFromName(input);

				if(tmpWeaponPtr != nullptr) 
				{
					selectedWeapon = tmpWeaponPtr;
					std::cout << "Succesfully selected " << tmpWeaponPtr->name << "\n";
				}
			}
		}

		if(!strncmp("wield", input, 16)) 
		{
			PB::Human* humanPtr = dynamic_cast<PB::Human*>(selectedEntity);

			if(humanPtr != nullptr) 
			{
				humanPtr->wield(*selectedWeapon);
				std::cout << humanPtr->name() << " is now wielding " << selectedWeapon->name << "\n";
				std::cout << humanPtr->name() << "'s damage is now " << humanPtr->calculateDamage() << "\n";
			} 
			else 
			{
				std::cout << selectedEntity->name() << " is not a human!\n";
			}
		}

		if(!strncmp("damage", input, 16)) 
		{
			std::cout << "Type name of entity to damage: ";
			std::cin >> input;

			PB::Entity* damagedEntity = PB::World::getEntityFromName(input);

			if(damagedEntity != nullptr) {
				selectedEntity->damage(*damagedEntity);
			}
		}
	}
	

	
	return 0;
}
