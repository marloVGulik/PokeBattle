#pragma once

#include <iostream>
#include <vector>
#include <string.h>

#include "../Weapon.hpp"
#include "../Helpers/Entity.hpp"

namespace PB {
    class World {
    private:
        static std::vector<Weapon*> _weapons;
        static std::vector<Entity*> _entities;
        
    public:
        World(/* args */);
        ~World();

        static void addEntity(Entity* entity);
        static void removeEntity(Entity* entity);
        static void removeEntity(const char* name);
        static int getEntityCount() { return World::_entities.size(); };
        static Entity* getEntityFromName(const char* name);

        static void addWeapon(Weapon* weapon);
        static void removeWeapon(Weapon* weapon);
        static void removeWeapon(const char* name);
        static int getWeaponCount() { return World::_weapons.size(); };
        static Weapon* getWeaponFromName(const char* name);
};
    
} // namespace PB




#include "World.cpp"