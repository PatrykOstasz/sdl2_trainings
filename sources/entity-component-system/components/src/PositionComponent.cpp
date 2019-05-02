#include "../include/PositionComponent.h"


PositionComponent::PositionComponent(int x, int y) : mXPos(x), mYPos(y) {
}

PositionComponent::PositionComponent() : mXPos(0), mYPos(0) {
}
void PositionComponent::setPosition(int newXPos, int newYPos) {
    mXPos = newXPos;
    mYPos = newYPos;
}

void PositionComponent::init() {
    mXPos = 0;
    mYPos = 0;
}

void PositionComponent::update() {
    mXPos++;
    mYPos++;
}

int PositionComponent::getXPos() const {
    return mXPos;
}

int PositionComponent::getYPos() const {
    return mYPos;
}
