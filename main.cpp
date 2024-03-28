#include <iostream>
#include <vector>
#include <array>
#include <SFML/Graphics.hpp>
#include "Vector.h"
#include "Entity.h"
#include "Renderer3D.h"

sf::VideoMode videoMode = sf::VideoMode(1200, 1000);
std::vector<Entity> entities;

Entity getNewEntity() {
    std::array<uint8_t, 3> color{255, 0, 0};

    return Entity("Earth", color, Point3D{200, 100, 300}, 2000, 30, Vector(), Vector(), Vector());
}

int main(int argc, char **argv) {
    sf::RenderWindow window(videoMode, "Space");

    entities.push_back(getNewEntity());

    Renderer3D renderer3D(&window, entities, 1200, 1000);

    while(window.isOpen()) {
        sf::Event event;
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        renderer3D.render();
    }

    return 0;
}