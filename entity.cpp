#include "Entity.h"

Entity::Entity(std::string name, std::array<uint8_t, 3> color, 
                Point3D position, float mass, float radius,
                Vector velocity, Vector acceleration, Vector force) {
    this->name = name;
    this->color = sf::Color(color[0], color[1], color[2]);
    this->position = position;
    this->mass = mass;
    this->radius = radius;
    this->velocity = velocity;
    this->acceleration = acceleration;
    this->force = force;
}

sf::Color Entity::getColor() {
    return this->color;
}

float Entity::getRadius() {
    return this->radius;
}

