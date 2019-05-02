#ifndef ECS_H_INCLUDED
#define ECS_H_INCLUDED

#include <memory>
#include <vector>
#include "entities/include/Entity.h"

using std::unique_ptr;
using std::vector;

class Entity;

class SystemManager {
private:
    vector<unique_ptr<Entity>> mEntities;

public:
    void update();
    void draw();
    void refresh();
    Entity& addEntity();
};
#endif // ECS_H_INCLUDED
