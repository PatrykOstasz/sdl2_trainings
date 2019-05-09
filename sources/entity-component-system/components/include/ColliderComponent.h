#ifndef COLLIDERCOMPONENT_H
#define COLLIDERCOMPONENT_H

#include <string>
#include "SDL_rect.h"
#include "Component.h"

class TransformComponent;

class ColliderComponent : public Component {
private:
    SDL_Rect mCollider;
    std::string mTag;
    TransformComponent* mTransform;

public:
    SDL_Rect getCollider() const {return mCollider; }
    ColliderComponent(const std::string& tag);
    virtual void init() override;
    virtual void update() override;
};

#endif // COLLIDERCOMPONENT_H
