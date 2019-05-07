#ifndef TRANSFORMCOMPONENT_H_INCLUDED
#define TRANSFORMCOMPONENT_H_INCLUDED

#include "Component.h"
#include "../../../game/include/Vector2d.h"

class TransformComponent : public Component {
private:
    Vector2D position;
    Vector2D velocity;
    int width = 32;
    int height = 32;
    int speed = 3;
    int scale = 2;

public:
    TransformComponent();
    TransformComponent(float x, float y);
    TransformComponent(float x, float y, int w, int h, int s);
    Vector2D getPosition() const;
    Vector2D getVelocity() const;
    void setScale(int newScale);
    int getScale() const;
    void setPosition(float newXPos, float newYPos);
    void setVelocity(float newXVel, float newYVel);
    virtual void init() override;
    virtual void update() override;
    virtual void draw() {}
    int getWidth() const;
    int getHeight() const;
};

#endif // TRANSFORMCOMPONENT_H_INCLUDED
