#pragma once

#include <cmath>
#include <array>

class Vector {
    private:
        float x;
        float y;
        float z;
        float alpha;
        float beta;
        float gamma;
        float magnitude;
    public:
        Vector(float, float, float);
        float getX();
        float getY();
        float getZ();
        void setX(float);
        void setY(float);
        void setZ(float);
        void calcMagnitude();
        void calcDirection();
        float getMagnitude();
        std::array<float, 3> getDirection();
        void add(Vector const&);
        void substract(Vector const&);
};