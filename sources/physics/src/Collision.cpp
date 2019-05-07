#include "Collision.h"

#include "SDL_rect.h"

bool Collision::AABB(const SDL_Rect& r1, const SDL_Rect& r2) {
    bool isACollidedWithBByWidth = (r1.x + r1.w >= r2.x);
    bool isBCollidedWithAByWidth = (r2.x + r2.w >= r1.x);
    bool isACollidedWithBByHeight = (r1.y + r1.h >= r2.y);
    bool isBCollidedWithAByHeight = (r2.y + r2.h >= r1.y);

    return (isACollidedWithBByWidth && isBCollidedWithAByWidth &&
            isACollidedWithBByHeight && isBCollidedWithAByHeight);
}
