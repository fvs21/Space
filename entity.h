#pragma once

#include <cmath>
#include <iostream>
#include <array>
#include <vector>
#include <SFML/Graphics/Color.hpp>
#include "Vector.h"

const float G = 6.67300e-11f;

class Entity {
    private:
        std::string name;
        sf::Color color;
        Point3D position;
        float mass;
        float radius;
        Vector velocity;
        Vector acceleration;
    public:
        Entity(std::string, std::array<uint8_t,3>, Point3D, float, float, Vector, Vector);
        Point3D getPos();
        std::string getPlanetName();
        float getMass();
        float getRadius();
        sf::Color getColor();
        void move();
        void setVelocity(float, float, float);
        void setAcceleration(float, float, float);
        std::array<float, 3> attract(Entity&);
        void updateMovement(std::vector<Entity*>&);
};