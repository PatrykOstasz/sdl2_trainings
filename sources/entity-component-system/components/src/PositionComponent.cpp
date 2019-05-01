#include "../include/PositionComponent.h"

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
