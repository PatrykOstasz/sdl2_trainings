#include "../include/TransformComponent.h"

TransformComponent::TransformComponent() : position() {
}

TransformComponent::TransformComponent(float x, float y) : position(x, y) {
}

TransformComponent::TransformComponent(float x, float y, int w, int h, int s) :
    position(x,y), width(w), height(h), scale(s) {
}

void TransformComponent::setPosition(float newXPos, float newYPos) {
    position = Vector2D(newXPos, newYPos);
}

void TransformComponent::init() {
    setPosition(this->getPosition().getX(), this->getPosition().getY());
    velocity = Vector2D();
}

void TransformComponent::update() {
    position.setX(position.getX()+velocity.getX()*speed);
    position.setY(position.getY()+velocity.getY()*speed);
}

Vector2D TransformComponent::getPosition() const {
    return position;
}

Vector2D TransformComponent::getVelocity() const {
    return velocity;
}

void TransformComponent::setVelocity(float newXVel, float newYVel) {
    velocity.setX(newXVel);
    velocity.setY(newYVel);
}

void TransformComponent::setScale(int newScale) {
    scale = newScale;
}

int TransformComponent::getScale() const {
    return scale;
}

int TransformComponent::getWidth() const {
    return width;
}

int TransformComponent::getHeight() const {
    return height;
}
