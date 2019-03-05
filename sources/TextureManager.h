#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

class SDL_Texture;
class SDL_Renderer;

class TextureManager {
public:
    static SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* ren);

};

#endif // TEXTUREMANAGER_H
