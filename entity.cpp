#include "Entity.h"

Entity::Entity(std::string name, std::array<uint8_t, 3> color, 
                Point3D position, float mass, float radius,
                Vector velocity, Vector acceleration) {
    this->name = name;
    this->color = sf::Color(color[0], color[1], color[2]);
    this->position = position;
    this->mass = mass;
    this->radius = radius;
    this->velocity = velocity;
    this->acceleration = acceleration;
}
std::string Entity::getPlanetName() {
    return this->name;
}
Point3D Entity::getPos() {
    return this->position;
}
float Entity::getMass() {
    return this->mass;
}
float Entity::getRadius() {
    return this->radius;
}

sf::Color Entity::getColor() {
    return this->color;
}
void Entity::setAcceleration(float x, float y, float z) {
    this->acceleration.setX(x);
    this->acceleration.setY(y);
    this->acceleration.setZ(z);
}
void Entity::setVelocity(float x, float y, float z) {
    this->velocity.setX(x);
    this->velocity.setY(y);
    this->velocity.setZ(z);
}
void Entity::move() {
    this->velocity.add(this->acceleration);
    this->position.x += this->velocity.getX();
    this->position.y += this->velocity.getY();
    this->position.z += this->velocity.getZ();
}
std::array<float, 3> Entity::attract(Entity &planet){
    Point3D pos = planet.getPos();
    float dis_x = (pos.x-this->position.x);
    float dis_y = (pos.y-this->position.y);
    float dis_z = (pos.z-this->position.z);

    Vector position_vector = Vector(dis_x, dis_y, dis_z);
    float distance = position_vector.getMagnitude();

    float force = (G * this->mass * planet.getMass()) / pow(distance, 2);

    std::array<float, 3> angles = position_vector.getDirection();

    Vector resultant_force_vector = Vector(force, angles);
    std::array<float, 3> forces = {resultant_force_vector.getX(), resultant_force_vector.getY(), resultant_force_vector.getZ()};
    return forces;

}

void Entity::updateMovement(std::vector<Entity*>& planets) {
    if(planets.size() == 1) {
        this->move();
        return;
    }
    float t_fx = 0, t_fy = 0, t_fz = 0;
    for(auto &planet : planets) {
        if(planet->getPlanetName() == this->name)
            continue;
        std::array<float, 3> forces = this->attract(*planet);
        t_fx += forces[0];
        t_fy += forces[1];
        t_fz += forces[2];
    }
    float acc_x = t_fx/this->mass;
    float acc_y = t_fy/this->mass;
    float acc_z = t_fz/this->mass;
    //std::cout << acc_x << '\n';
    this->setAcceleration(acc_x, acc_y, acc_z);
    this->move();
}