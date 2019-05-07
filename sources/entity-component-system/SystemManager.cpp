#include "SystemManager.h"

#include<algorithm>
#include "entities/include/Entity.h"


SystemManager::SystemManager() {}
SystemManager::~SystemManager() {}
void SystemManager::update() {
    for (auto& e : mEntities) e->update();
}

void SystemManager::draw() {
    for (auto& e : mEntities) e->draw();
}

void SystemManager::refresh() {
    mEntities.erase(remove_if(begin(mEntities),end(mEntities),
                                [](const std::unique_ptr<Entity> &mEntity)
                                {
                                    return !mEntity->isActive();
                                }
                            ), end(mEntities));
}

Entity& SystemManager::addEntity() {
    Entity* e = new Entity();
    using std::unique_ptr;
    unique_ptr<Entity> uPtr(e);
    mEntities.emplace_back(std::move(uPtr));
    return *e;
}
