#include "GameObject.h"
#include "TextureManager.h"
#include "SDL_render.h"

GameObject::GameObject(const char* name, SDL_Renderer* render, int x, int y) :
    objectName(name), renderer(render), posX(x), posY(y), object(nullptr) {
        object = TextureManager::LoadTexture(objectName, renderer);
        srcRect.h = 64;
        srcRect.w = 68;
        srcRect.x = posX;
        srcRect.y = posY;

        destRect.h = srcRect.h*2;
        destRect.w = srcRect.w*2;
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
    SDL_RenderCopy(renderer, object, nullptr, &destRect);
}
