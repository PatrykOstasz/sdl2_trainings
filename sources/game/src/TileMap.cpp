#include "../include/TileMap.h"

#include "../include/TextureManager.h"
#include "SDL.h"

static int level1[20][25] = {
    {2,2,2,2,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0},
    {2,2,2,2,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0},
    {2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

TileMap::TileMap(unsigned width, unsigned height) : mGrassTexture(nullptr), mWaterTexture(nullptr),
    mSandTexture(nullptr), mWidth(width), mHeight(height) {
        mGrassTexture = TextureManager::LoadTexture("resources/assets/tiles/grass.png");
        mWaterTexture = TextureManager::LoadTexture("resources/assets/tiles/water.png");
        mSandTexture = TextureManager::LoadTexture("resources/assets/tiles/sand.png");

        load(level1);

        mSrc.x = mSrc.y = 0;
        mDest.x = mDest.y = 0;
        mSrc.w = mDest.w = 32;
        mSrc.h = mDest.h = 32;

}

TileMap::~TileMap() {
    SDL_DestroyTexture(mGrassTexture);
    SDL_DestroyTexture(mWaterTexture);
    SDL_DestroyTexture(mSandTexture);
}

void TileMap::load(int arr[20][25]) {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 25; ++j) {
            mIndexMap[i][j] = arr[i][j];
        }
    }
}

void TileMap::draw() {
    int tileType = 0;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 25; ++j) {
            tileType = mIndexMap[i][j];
            mDest.x = j * 32;
            mDest.y = i * 32;
            switch(tileType) {
            case 0:
                TextureManager::draw(mGrassTexture, mSrc, mDest);
                break;
            case 1:
                TextureManager::draw(mWaterTexture, mSrc, mDest);
                break;
            case 2:
                TextureManager::draw(mSandTexture, mSrc, mDest);
                break;
            }
        }
    }
}


