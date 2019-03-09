#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "SDL_rect.h"

class SDL_Texture;

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char* filename);
    static void draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);

};

#endif // TEXTUREMANAGER_H
