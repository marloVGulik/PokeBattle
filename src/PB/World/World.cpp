#pragma once

#include "World.hpp"

namespace PB {
    std::vector<Weapon*> World::_weapons;
    std::vector<Entity*> World::_entities;

    World::World(/* args */) {
        std::cout << "World starting...\n";
    }

    World::~World() {
        std::cout << "World stopping...\n";
    }

    void World::addEntity(Entity* entity) {
        World::_entities.push_back(entity);
    }
    void World::removeEntity(Entity* entity) {
        bool remove = false;
        int removeIndex = 0;
        for (size_t i = 0; i < World::_entities.size(); i++) {
            if(World::_entities[i] == entity) {
                remove = true;
                removeIndex = i;
                std::cout << "Removing " << i << "\n";
                break;
            }
        }
        if(remove) {
            World::_entities.erase(World::_entities.begin() + removeIndex);
        }
    }
    void World::removeEntity(const char* name) {
        World::removeEntity(World::getEntityFromName(name));
    }
    Entity* World::getEntityFromName(const char* name) {
        for (size_t i = 0; i < World::_entities.size(); i++) {
            if(!strncmp(World::_entities[i]->name(), name, sizeof(name))) {
                return World::_entities[i];
            }
        }
        return nullptr;
    }


    
    void World::addWeapon(Weapon* weapon) {
        World::_weapons.push_back(weapon);
    }
    void World::removeWeapon(Weapon* weapon) {
        bool remove = false;
        int removeIndex = 0;
        for (size_t i = 0; i < World::_weapons.size(); i++) {
            if(World::_weapons[i] == weapon) {
                remove = true;
                removeIndex = i;
                std::cout << "Removing " << i << "\n";
                break;
            }
        }
        if(remove) {
            World::_weapons.erase(World::_weapons.begin() + removeIndex);
        }
    }
    void World::removeWeapon(const char* name) {
        World::removeWeapon(World::getWeaponFromName(name));
    }
    Weapon* World::getWeaponFromName(const char* name) {
        for (size_t i = 0; i < World::_weapons.size(); i++) {
            if(!strncmp(World::_weapons[i]->name.c_str(), name, sizeof(name))) {
                return World::_weapons[i];
            }
        }
        return nullptr;        
    }
}