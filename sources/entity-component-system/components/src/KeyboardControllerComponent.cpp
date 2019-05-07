#include "../include/KeyboardControllerComponent.h"
#include "../../entities/include/Entity.h"
#include "../include/TransformComponent.h"
#include "../include/SpriteComponent.h"
#include "../../../game/include/Game.h"

void KeyboardControllerComponent::init() {
    transform = &entity->getComponent<TransformComponent>();
}

void KeyboardControllerComponent::update() {
    if (Game::getEventHandle().type == SDL_KEYDOWN) {
        switch (Game::getEventHandle().key.keysym.sym) {
        case SDLK_UP:
            transform->setVelocity(0,-1);
            break;
        case SDLK_DOWN:
            transform->setVelocity(0,1);
            break;
        case SDLK_LEFT:
            transform->setVelocity(-1,0);
            break;
        case SDLK_RIGHT:
            transform->setVelocity(1,0);
            break;
        }
    }

    if (Game::getEventHandle().type == SDL_KEYUP) {
        switch (Game::getEventHandle().key.keysym.sym) {
        case SDLK_UP:
            transform->setVelocity(0,0);
            break;
        case SDLK_DOWN:
            transform->setVelocity(0,0);
            break;
        case SDLK_LEFT:
            transform->setVelocity(0,0);
            break;
        case SDLK_RIGHT:
            transform->setVelocity(0,0);
            break;
        }
    }
}
