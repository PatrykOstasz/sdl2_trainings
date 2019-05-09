#ifndef TRANSFORMCOMPONENT_H_INCLUDED
#define TRANSFORMCOMPONENT_H_INCLUDED

#include "Component.h"
#include "../../../game/include/Vector2d.h"

class TransformComponent : public Component {
public:
    TransformComponent();
    TransformComponent(float x, float y);
    TransformComponent(float x, float y, int w, int h, int s);
    virtual void init() override;
    virtual void update() override;
    virtual void draw() {}

    Vector2D position;
    Vector2D velocity;
    int speed = 3;
    int scale = 2;
    const int width = 32;
    const int height = 32;
};

#endif // TRANSFORMCOMPONENT_H_INCLUDED
