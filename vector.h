#pragma once

#include <cmath>
#include <array>
#include <iostream>

struct Point3D {
    float x, y, z;
};

class Vector {
    private:
        float x;
        float y;
        float z;
        float alpha;
        float beta;
        float gamma;
        float magnitude;
        void calcMagnitude();
        void calcDirection();
        void calcXYZ();
    public:
        Vector(float, float, float);
        Vector();
        Vector(float, std::array<float, 3>);
        float getX();
        float getY();
        float getZ();
        void setX(float);
        void setY(float);
        void setZ(float);
        float getMagnitude();
        std::array<float, 3> getDirection();
        void add(Vector const&);
        void substract(Vector const&);
};