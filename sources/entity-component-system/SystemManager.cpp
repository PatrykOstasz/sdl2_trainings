#include "SystemManager.h"

#include<algorithm>
#include "entities/include/Entity.h"


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

void SystemManager::addEntity() {
    using std::unique_ptr;
    unique_ptr<Entity> uPtr(new Entity());
    mEntities.emplace_back(std::move(uPtr));
}
