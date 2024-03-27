#pragma once

#include <cmath>
#include <iostream>
#include <array>
#include <vector>
#include <SFML/Graphics/Color.hpp>
#include "vector.h"

class Entity {
    private:
        std::string name;
        sf::Color color;
        float x;
        float y;
        float z;
        float mass;
        float radius;
        Vector velocity;
        Vector acceleration;
        Vector force;
    public:
        Entity(std::string, std::array<int,3>, float, float, float, float, float, Vector, Vector, Vector);
        std::tuple<int, int, int> getPos();
        float getMass();
        float getRadius();
        void move();
        void setVelocity(float, float, float);
        void setAcceleration(float, float, float);
        std::array<int, 3> attract(Entity);
        void updateMovement(std::vector<Entity>);
};