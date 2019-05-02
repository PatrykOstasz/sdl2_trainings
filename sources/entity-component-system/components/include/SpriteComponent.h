#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H

#include "Component.h"
#include "SDL_rect.h"

class PositionComponent;
class SDL_Texture;

class SpriteComponent : public Component {
private:
    PositionComponent* mPosition;
    SDL_Texture* mTexture;
    SDL_Rect mSrcRect;
    SDL_Rect mDstRect;
public:
    SpriteComponent() = default;
    SpriteComponent(const char* sourcePath);
    virtual void init() override;
    virtual void update() override;
    virtual void draw() override;
};
#endif // SPRITECOMPONENT_H
