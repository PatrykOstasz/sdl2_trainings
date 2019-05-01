#ifndef ECS_H_INCLUDED
#define ECS_H_INCLUDED

#include <algorithm>
#include <array>
#include <bitset>
//#include <iostream>
#include <memory>
#include <vector>

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
    void addEntity();
};
#endif // ECS_H_INCLUDED
