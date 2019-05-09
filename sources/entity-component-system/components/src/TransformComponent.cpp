#include "../include/TransformComponent.h"

TransformComponent::TransformComponent() : position() {
}

TransformComponent::TransformComponent(float x, float y) : position(x, y) {
}

TransformComponent::TransformComponent(float x, float y, int w, int h, int s) :
    position(x,y), width(w), height(h), scale(s) {
}

void TransformComponent::init() {
    velocity.zero();
}

void TransformComponent::update() {
    position += velocity*speed;
}
