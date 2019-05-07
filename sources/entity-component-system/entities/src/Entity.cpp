#include "../include/Entity.h"
#include <iostream>

void Entity::update() {
    for (auto& c : mComponents) c->update();
}

void Entity::draw() {
    for (auto& c : mComponents) c->draw();
}

bool Entity::isActive() const {
    return mActive;
}

void Entity::destroy() {
    mActive = false;
}
