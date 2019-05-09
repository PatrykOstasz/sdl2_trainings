#include "../include/ColliderComponent.h"
#include "../../entities/include/Entity.h"
#include "../include/TransformComponent.h"
#include "../include/SpriteComponent.h"

void ColliderComponent::init() {
    if (!entity->hasComponent<TransformComponent>()) {
        entity->addComponent<TransformComponent>();
    }
    mTransform = &entity->getComponent<TransformComponent>();
}

void ColliderComponent::update() {
    mCollider.x = static_cast<int>(mTransform->position.x);
    mCollider.y = static_cast<int>(mTransform->position.y);
    mCollider.w = mTransform->width*mTransform->scale;
    mCollider.h = mTransform->height*mTransform->scale;
}

ColliderComponent::ColliderComponent(const std::string & tag) : mTag(tag) {
}
