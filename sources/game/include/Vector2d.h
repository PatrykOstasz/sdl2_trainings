#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <ostream>

class Vector2D {
private:
    float mX;
    float mY;
public:
    Vector2D();
    Vector2D(float x, float y);
    float getX() const;
    float getY() const;
    void setX(float newX) {mX = newX;}
    void setY(float newY) {mY = newY;}
    Vector2D& add(const Vector2D& vec);
    Vector2D& substract(const Vector2D& vec);
    Vector2D& multiply(const Vector2D& vec);
    Vector2D& divide(const Vector2D& vec);

    friend Vector2D& operator+(Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator-(Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator*(Vector2D& v1, const Vector2D& v2);
    friend Vector2D& operator/(Vector2D& v1, const Vector2D& v2);
    friend std::ostream& operator<<(const std::ostream& os, const Vector2D& vec);

    Vector2D& operator+=(const Vector2D& vec);
    Vector2D& operator-=(const Vector2D& vec);
    Vector2D& operator*=(const Vector2D& vec);
    Vector2D& operator/=(const Vector2D& vec);

};

#endif // VECTOR2D_H
