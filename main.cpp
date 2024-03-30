#include <iostream>
#include <vector>
#include <array>
#include <SFML/Graphics.hpp>
#include "Vector.h"
#include "Entity.h"
#include "Renderer3D.h"

sf::VideoMode videoMode = sf::VideoMode(2000, 1400);
std::vector<Entity*> entities;

Entity getNewEntity() {
    std::array<uint8_t, 3> color{255, 255, 255};

    return Entity("Earth", color, Point3D{200, 300, 0}, 2000, 30, Vector(0.0005, 0.0005, 0), Vector(0.0005, 0.0005, 0));
}

int main(int argc, char **argv) {
    sf::RenderWindow window(videoMode, "Space");

    std::array<uint8_t, 3> color{255, 255, 255};

    Entity* entity1 = new Entity("Earth", color, Point3D{200, 300, -100}, 200000000000, 10, Vector(0, 0, 0), Vector(0, 0, 0));
    Entity* entity2 = new Entity("Pepe", color, Point3D{1000, 800, 400}, 200000000000, 10, Vector(0, 0, 0), Vector(0, 0, 0));
    entities.push_back(entity1);
    entities.push_back(entity2);

    Renderer3D renderer3D(&window, entities, 1200, 1000);

    while(window.isOpen()) {
        window.clear(sf::Color::Black);
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed){
                for(auto entity : entities) {
                    delete entity;
                }
                entities.clear();
                window.close();
            }
        }
        renderer3D.render();
    }

    return 0;
}