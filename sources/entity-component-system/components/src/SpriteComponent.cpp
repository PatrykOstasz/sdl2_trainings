#include "../include/SpriteComponent.h"

#include "../include/TransformComponent.h"
#include "../../entities/include/Entity.h"
#include "../../../game/include/TextureManager.h"
#include "SDL.h"
#include <iostream>

SpriteComponent::SpriteComponent(const char* sourcePath) {
    mTexture = TextureManager::LoadTexture(sourcePath);
}

SpriteComponent::~SpriteComponent() {
    SDL_DestroyTexture(mTexture);
}

void SpriteComponent::init() {
    mTransform = &entity->getComponent<TransformComponent>();
    mSrcRect.x = 0, mSrcRect.y = 0;
    mSrcRect.w = 48;
    mSrcRect.h = 72;
    mDstRect.w = mTransform->width*mTransform->scale;
    mDstRect.h = mTransform->height*mTransform->scale;
}

void SpriteComponent::update() {
    mDstRect.x = static_cast<int>(mTransform->position.x);
    mDstRect.y = static_cast<int>(mTransform->position.y);
    mDstRect.w = mTransform->width*mTransform->scale;
    mDstRect.h = mTransform->height*mTransform->scale;
}

void SpriteComponent::draw() {
    TextureManager::draw(mTexture, mSrcRect, mDstRect);
}
