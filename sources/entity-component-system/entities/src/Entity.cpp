#include "../include/Entity.h"

void Entity::update() {
    for (auto& c : mComponents) c->update();
    for (auto& c : mComponents) c->draw();
}

bool Entity::isActive() const {
    return mActive;
}

void Entity::destroy() {
    mActive = false;
}

ComponentID Entity::getComponentTypeId() {
        static ComponentID lastId = 0;
        return lastId++;
}

template <typename T> ComponentID Entity::getComponentTypeId() noexcept {
    ComponentID typeID = getComponentTypeId();
    return typeID;
}

template <typename T> bool Entity::hasComponent() const {
    return mComponentBitSet[getComponentTypeId<T>()];
}

template<typename T, typename ...TArgs> T& Entity::addComponent(TArgs&& ... mArgs) {
    using std::forward;
    using std::move;

    T* component = new T(forward<TArgs>(mArgs)...);
    component->entity = this;
    unique_ptr<Component> uPtr(component);
    mComponents.emplace_back(move(uPtr));

    mComponentArray[getComponentTypeId<T>()] = component;
    mComponentBitSet[getComponentTypeId<T>()] = true;

    component->init();
    return *component;
}

template<typename T> T& Entity::getComponent() const {
    auto ptr = mComponentArray[getComponentTypeId<T>()];
    return *static_cast<T*>(ptr);
}
