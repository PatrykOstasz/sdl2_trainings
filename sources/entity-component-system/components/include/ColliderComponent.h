#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H

#include <string>
#include "SDL_rect.h"
#include "Component.h"

class TransformComponent;

class ColliderComponent : public Component {
private:
    SDL_Rect collider;
    std::string tag;
    TransformComponent* transform;

public:
    SDL_Rect getCollider() const {return collider; }
    ColliderComponent(const std::string & nTag);
    virtual void init() override;
    virtual void update() override;
};

#endif // COLLIDERCOMPONENT_H
