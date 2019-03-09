#include "../include/GameObject.h"

#include "../include/Game.h"
#include "../include/TextureManager.h"

GameObject::GameObject(const char* name, int x, int y) : objectName(name), posX(x), posY(y),
    object(nullptr) {
        object = TextureManager::LoadTexture(objectName);
        srcRect.h = 64;
        srcRect.w = 68;
        srcRect.x = posX;
        srcRect.y = posY;

        destRect.h = srcRect.h;
        destRect.w = srcRect.w;
        destRect.x = srcRect.x;
        destRect.y = srcRect.y;
}

void GameObject::update() {
    posX++;
    posY++;

    destRect.x = posX;
    destRect.y = posY;

}

void GameObject::render(){
    SDL_RenderCopy(Game::getRenderer(), object, nullptr, &destRect);
}
