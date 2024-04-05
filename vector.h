#pragma once

#include <cmath>
#include <array>
#include <iostream>

struct Point3D {
    double x, y, z;
};

class Vector {
    private:
        double x;
        double y;
        double z;
        double alpha;
        double beta;
        double gamma;
        double magnitude;
        void calcMagnitude();
        void calcDirection();
        void calcXYZ();
    public:
        Vector(double, double, double);
        Vector();
        Vector(double, std::array<double, 3>);
        double getX();
        double getY();
        double getZ();
        void setX(double);
        void setY(double);
        void setZ(double);
        double getMagnitude();
        std::array<double, 3> getDirection();
        void add(Vector const&);
        void substract(Vector const&);
};