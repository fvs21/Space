#include <iostream>
#include <vector>
#include <array>
#include <SFML/Graphics.hpp>
#include "Vector.h"
#include "Entity.h"
#include "Renderer3D.h"

sf::VideoMode videoMode = sf::VideoMode(2000, 1400);
std::vector<Entity*> entities;

int main(int argc, char **argv) {
    sf::RenderWindow window(videoMode, "Space");

    std::array<uint8_t, 3> white{255, 255, 255};
    std::array<uint8_t, 3> orange{255, 165, 0};

    Entity* entity1 = new Entity("Earth", white, Point3D{100.0f, 100.0f, 0.0f}, 5000.0f, 4.0f, Vector(0.05f, 0.01f, 0.0f), Vector(0.0f, 0.0f, 0.0f)); //5.972e24f
    Entity* entity2 = new Entity("Sun", orange, Point3D{900.0f, 700.0f, 50.0f}, 190000000000.0f, 10.0f, Vector(0.0f, 0.0f, 0.0f), Vector(0.0f, 0.0f, 0.0f)); //1.989e30f
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