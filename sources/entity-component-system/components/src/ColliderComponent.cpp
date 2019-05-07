#include "../include/ColliderComponent.h"
#include "../../entities/include/Entity.h"
#include "../include/TransformComponent.h"
#include "../include/SpriteComponent.h"

void ColliderComponent::init() {
    if (!entity->hasComponent<TransformComponent>()) {
        entity->addComponent<TransformComponent>();
    }
    transform = &entity->getComponent<TransformComponent>();
}

void ColliderComponent::update() {
    collider.x = transform->getPosition().getX();
    collider.y = transform->getPosition().getY();
    collider.w = transform->getWidth()*transform->getScale();
    collider.h = transform->getHeight()*transform->getScale();
}

ColliderComponent::ColliderComponent(const std::string & nTag) : tag(nTag) {
}
