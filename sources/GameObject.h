#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "SDL_rect.h"

class SDL_Renderer;
class SDL_Texture;

class GameObject {
public:
    GameObject(const char* name, SDL_Renderer* render, int x, int y);
    void update();
    void render();
private:
    const char* objectName;
    SDL_Renderer* renderer;
    int posX;
    int posY;
    SDL_Texture* object;
    SDL_Rect srcRect;
    SDL_Rect destRect;
};

#endif // GAMEOBJECT_H
