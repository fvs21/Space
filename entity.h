#pragma once

#include <cmath>
#include <iostream>
#include <array>
#include <vector>
#include <SFML/Graphics/Color.hpp>
#include "Vector.h"

const double G = 6.67300e-11f;

class Entity {
    private:
        std::string name;
        sf::Color color;
        Point3D position;
        double mass;
        double radius;
        Vector velocity;
        Vector acceleration;
    public:
        Entity(std::string, std::array<uint8_t,3>, Point3D, double, double, Vector, Vector);
        Point3D getPos();
        std::string getPlanetName();
        double getMass();
        double getRadius();
        sf::Color getColor();
        void move();
        void setVelocity(double, double, double);
        void setAcceleration(double, double, double);
        std::array<double, 3> attract(Entity&);
        void updateMovement(std::vector<Entity*>&);
};