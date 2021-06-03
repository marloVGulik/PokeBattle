#pragma once

#include "Human.hpp"

namespace PB {
    class Runner : public Human {
    private:
        
    public:
        Runner();
        Runner(glm::vec2 pos);
        ~Runner();
    };    
}

#include "Runner.cpp"