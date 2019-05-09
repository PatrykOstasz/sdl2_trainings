#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <ostream>

class Vector2D {
public:
    Vector2D();
    Vector2D(float x, float y);
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
    Vector2D& operator*(const int& scalar);

    Vector2D& zero();

    float x;
    float y;

};

#endif // VECTOR2D_H
