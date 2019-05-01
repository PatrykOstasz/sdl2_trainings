#ifndef TILEMAP_H
#define TILEMAP_H

#include "SDL_rect.h"

class SDL_Texture;

class TileMap {
public:
    TileMap(unsigned width, unsigned height);
    void draw();
private:
    void load(int arr[20][25]);

    SDL_Rect mSrc;
    SDL_Rect mDest;
    SDL_Texture* mGrassTexture;
    SDL_Texture* mWaterTexture;
    SDL_Texture* mSandTexture;

    int mIndexMap[20][25];
    unsigned mWidth;
    unsigned mHeight;
};

#endif // TILEMAP_H
