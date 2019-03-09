#include "../include/TileMap.h"

#include "../include/TextureManager.h"

static int level1[20][25] = {
    {0,0,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
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
        mGrassTexture = TextureManager::LoadTexture("assets/tiles/grass.png");
        mWaterTexture = TextureManager::LoadTexture("assets/tiles/water.png");
        mSandTexture = TextureManager::LoadTexture("assets/tiles/sand.png");

        load(level1);

        mSrc.x = mSrc.y = 0;
        mDest.x = mDest.y = 0;
        mSrc.w = mDest.w = 32;
        mSrc.h = mDest.h = 32;

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


