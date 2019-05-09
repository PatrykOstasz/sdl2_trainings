#include "../include/Vector2d.h"
#include <iostream>

Vector2D::Vector2D() : x(0.0f), y(0.0f) {
}

Vector2D::Vector2D(float xi, float yi) : x(xi), y(yi) {
}

Vector2D& Vector2D::add(const Vector2D& vec) {
    x += vec.x;
    y += vec.y;
    return *this;
}

Vector2D& Vector2D::substract(const Vector2D& vec) {
    x -= vec.x;
    y -= vec.y;
    return *this;
}

Vector2D& Vector2D::multiply(const Vector2D& vec) {
    x *= vec.x;
    y *= vec.y;
    return *this;
}

Vector2D& Vector2D::divide(const Vector2D& vec) {
    if (vec.x == 0.0 or vec.y == 0.0) {
        std::cerr << "Division by zero error. Operation not allowed\n";
        return *this;
    }
    x /= vec.x;
    y /= vec.y;
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

Vector2D& Vector2D::operator*(const int& scalar) {
    this->x *= scalar;
    this->y *= scalar;

    return *this;
}

Vector2D& Vector2D::zero() {
    this->x = 0.0f;
    this->y = 0.0f;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Vector2D& vec) {
    return os << "Vec2D(" << vec.x << "," << vec.y << ")" << std::endl;
}
