#include "../include/KeyboardControllerComponent.h"
#include "../../entities/include/Entity.h"
#include "../include/TransformComponent.h"
#include "../include/SpriteComponent.h"
#include "../../../game/include/Game.h"

void KeyboardControllerComponent::init() {
    mTransform = &entity->getComponent<TransformComponent>();
}

void KeyboardControllerComponent::update() {
    if (Game::getEventHandle().type == SDL_KEYDOWN) {
        switch (Game::getEventHandle().key.keysym.sym) {
        case SDLK_UP:
            mTransform->velocity.y = -1;
            break;
        case SDLK_DOWN:
            mTransform->velocity.y = 1;
            break;
        case SDLK_LEFT:
            mTransform->velocity.x = -1;
            break;
        case SDLK_RIGHT:
            mTransform->velocity.x = 1;
            break;
        }
    }

    if (Game::getEventHandle().type == SDL_KEYUP) {
        switch (Game::getEventHandle().key.keysym.sym) {
        case SDLK_UP:
            mTransform->velocity.y = 0;
            break;
        case SDLK_DOWN:
            mTransform->velocity.y = 0;
            break;
        case SDLK_LEFT:
            mTransform->velocity.x = 0;
            break;
        case SDLK_RIGHT:
            mTransform->velocity.x = 0;
            break;
        }
    }
}
