#ifndef COLLISION_H
#define COLLISION_H

class SDL_Rect;

class Collision {
public:
    static bool AABB(const SDL_Rect& r1, const SDL_Rect& r2);
};

#endif // COLLISION_H
