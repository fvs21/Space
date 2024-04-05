#include "Vector.h"

Vector::Vector() {}

Vector::Vector(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->calcMagnitude();
    this->calcDirection();
}
Vector::Vector(double magnitude, std::array<double, 3> angles) {
    this->magnitude = magnitude;
    this->alpha = angles[0];
    this->beta = angles[1];
    this->gamma = angles[2];
    this->calcXYZ();
}
void Vector::add(Vector const& vector2) {
    this->x += vector2.x;
    this->y += vector2.y;
    this->z += vector2.z;
}
void Vector::substract(Vector const& vector2) {
    this->x -= vector2.x;
    this->y -= vector2.y;
    this->z -= vector2.z;
}
double Vector::getX() {
    return this->x;
}
double Vector::getY() {
    return this->y;
}
double Vector::getZ() {
    return this->z;
}
void Vector::setX(double x) {
    this->x = x;
}
void Vector::setY(double y) {
    this->y = y;
}
void Vector::setZ(double z) {
    this->z = z;
}
void Vector::calcXYZ() {
    this->x = cos(this->alpha)*this->magnitude;
    this->y = cos(this->beta)*this->magnitude;
    this->z = cos(this->gamma)*this->magnitude;
}
void Vector::calcMagnitude() {
    this->magnitude = sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}
void Vector::calcDirection() {
    double magnitude = this->getMagnitude();
    this->alpha = acos(this->x/magnitude); 
    this->beta = acos(this->y/magnitude);
    this->gamma = acos(this->z/magnitude);
}
double Vector::getMagnitude() {
    return this->magnitude;
}
std::array<double, 3> Vector::getDirection() {
    return std::array<double, 3> {this->alpha, this->beta, this->gamma};
}