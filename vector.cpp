#include "vector.h"

Vector::Vector(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
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
float Vector::getX() {
    return this->x;
}
float Vector::getY() {
    return this->y;
}
float Vector::getZ() {
    return this->z;
}
void Vector::setX(float x) {
    this->x = x;
}
void Vector::setY(float y) {
    this->y = y;
}
void Vector::setZ(float z) {
    this->z = z;
}
void Vector::calcMagnitude() {
    this->magnitude = sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}
void Vector::calcDirection() {
    float magnitude = this->getMagnitude();
    this->alpha = acos(this->x/magnitude); 
    this->beta = acos(this->y/magnitude);
    this->gamma = acos(this->z/magnitude);
}
float Vector::getMagnitude() {
    return this->magnitude;
}
std::array<float, 3> Vector::getDirection() {
    return std::array<float, 3> {this->alpha, this->beta, this->gamma};
}