#include "../include/SpriteComponent.h"
#include "../include/PositionComponent.h"

#include "../../entities/include/Entity.h"
#include "../../../game/include/TextureManager.h"

SpriteComponent::SpriteComponent(const char* sourcePath) {
    mTexture = TextureManager::LoadTexture(sourcePath);
}

void SpriteComponent::init() {
    mPosition = &entity->getComponent<PositionComponent>();
    mSrcRect.x = mSrcRect.y = 0;
    mSrcRect.w = mSrcRect.h = 32;
    mDstRect.w = mDstRect.h = 64;
}

void SpriteComponent::update() {
    mDstRect.x = mPosition->getXPos();
    mDstRect.y = mPosition->getYPos();
}

void SpriteComponent::draw() {
    TextureManager::draw(mTexture, mSrcRect, mDstRect);
}


