#include "Renderer3D.h"

Renderer3D::Renderer3D(sf::RenderWindow* renderer, std::vector<Entity*>& entities, int windowSizeX, int windowSizeY) {
    this->renderer = renderer;
    this->entities = entities;
    this->WindowSizeX = windowSizeX;
    this->WindowSizeY = windowSizeY;
}

void Renderer3D::render() {
    auto time1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration(0);
    
    this->renderer->clear(sf::Color::Black);

    for(size_t i = 0; i<this->entities.size(); i++) {
        auto *entity = entities.at(i);
        Point3D pos = entity->getPos();
        std::cout << entity->getPlanetName() << ": " << pos.x << " " << pos.y << " " << pos.z << '\n';
        entity->updateMovement(this->entities);
        sf::CircleShape entity_shape(entity->getRadius() + (entity->getPos().z));
        entity_shape.setFillColor(entity->getColor());
        entity_shape.setPosition(pos.x, pos.y);
        this->renderer->draw(entity_shape);
    }
    this->renderer->display();
} 