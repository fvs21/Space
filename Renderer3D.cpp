#include "Renderer3D.h"

Renderer3D::Renderer3D(sf::RenderWindow* renderer, std::vector<Entity>& entities, int windowSizeX, int windowSizeY) {
    this->renderer = renderer;
    this->entities = entities;
    this->WindowSizeX = windowSizeX;
    this->WindowSizeY = windowSizeY;
}

void Renderer3D::render() {
    auto time1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration(0);

    for(auto& entity : entities) {
        sf::CircleShape entity_shape(entity.getRadius());
        entity_shape.setFillColor(entity.getColor());
        entity_shape.setPosition(100,100);
        this->renderer->draw(entity_shape);
    }
    this->renderer->display();
}