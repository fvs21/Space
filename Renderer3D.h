#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>
#include <chrono>
#include <vector>
#include <iostream>
#include "Entity.h"

class Renderer3D {
    private:
        sf::RenderWindow* renderer;
        std::vector<Entity*> entities;

        float FOV = 10.0;
        float deltaTime = 0.0f;

        int WindowSizeX;
        int WindowSizeY;
    public:
        Renderer3D(sf::RenderWindow*, std::vector<Entity*>&, int, int);
        void render();
};