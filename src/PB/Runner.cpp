#pragma once

#include "Runner.hpp"

namespace PB {
    Runner::Runner() {
        this->_moveSpeed = int(this->_moveSpeed * 1.5f);
        this->_strength = int(this->_strength * 0.7);
        // std::cout << "Runner created\n";
    }
    Runner::Runner(glm::vec2 pos) : Human(pos) {
        this->_moveSpeed = int(this->_moveSpeed * 1.5f);
        this->_strength = int(this->_strength * 0.7);
        // std::cout << "Runner created\n";
    }
    
    Runner::~Runner() {
    }
}