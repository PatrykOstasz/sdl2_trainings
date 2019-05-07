#include "../include/Vector2d.h"
#include <iostream>

Vector2D::Vector2D() : mX(0.0), mY(0.0) {
}

Vector2D::Vector2D(float x, float y) : mX(x), mY(y) {
}

Vector2D& Vector2D::add(const Vector2D& vec) {
    mX += vec.mX;
    mY += vec.mY;
    return *this;
}

Vector2D& Vector2D::substract(const Vector2D& vec) {
    mX -= vec.mX;
    mY -= vec.mY;
    return *this;
}

Vector2D& Vector2D::multiply(const Vector2D& vec) {
    mX *= vec.mX;
    mY *= vec.mY;
    return *this;
}

Vector2D& Vector2D::divide(const Vector2D& vec) {
    if (vec.mX == 0.0 or vec.mY == 0) {
        std::cerr << "Division by zero error. Operation not allowed\n";
        return *this;
    }
    mX /= vec.mX;
    mY /= vec.mY;
    return *this;
}

Vector2D& operator+(Vector2D& v1, const Vector2D& v2) {
    return v1.add(v2);
}

Vector2D& operator-(Vector2D& v1, const Vector2D& v2) {
    return v1.substract(v2);
}

Vector2D& operator*(Vector2D& v1, const Vector2D& v2) {
    return v1.multiply(v2);
}

Vector2D& operator/(Vector2D& v1, const Vector2D& v2) {
    return v1.divide(v2);
}

Vector2D& Vector2D::operator+=(const Vector2D& vec) {
    return this->add(vec);
}

Vector2D& Vector2D::operator-=(const Vector2D& vec) {
    return this->substract(vec);
}

Vector2D& Vector2D::operator*=(const Vector2D& vec) {
    return this->multiply(vec);
}

Vector2D& Vector2D::operator/=(const Vector2D& vec) {
    return this->divide(vec);
}

float Vector2D::getX() const {
    return mX;
}

float Vector2D::getY() const {
    return mY;
}

std::ostream& operator<<(std::ostream& os, const Vector2D& vec) {
    return os << "Vec2D(" << vec.getX() << "," << vec.getY() << ")" << std::endl;
}
