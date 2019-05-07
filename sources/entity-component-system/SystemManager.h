#ifndef SYSTEM_MANAGER_H_INCLUDED
#define SYSTEM_MANAGER_INCLUDED

#include <memory>
#include <vector>

using std::unique_ptr;
using std::vector;

class Entity;
class SystemManager {
private:
    vector<unique_ptr<Entity>> mEntities;

public:
    SystemManager();
    ~SystemManager();
    void update();
    void draw();
    void refresh();
    Entity& addEntity();
};
#endif // SYSTEM_MANAGER_INCLUDED
