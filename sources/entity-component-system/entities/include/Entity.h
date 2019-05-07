#ifndef ENTITY_H
#define ENTITY_H

#include <array>
#include <bitset>
#include <memory>
#include <vector>
#include "../../components/include/Component.h"

using std::array;
using std::bitset;
using std::unique_ptr;
using std::vector;

constexpr size_t maxComponents = 32;

using ComponentBitSet = bitset<maxComponents>;
using ComponentArray = array<Component*, maxComponents>;
using ComponentID = unsigned;

class Entity {
private:
    bool mActive = true;
    vector<unique_ptr<Component>> mComponents;
    ComponentBitSet mComponentBitSet;
    ComponentArray mComponentArray;
    ComponentID getComponentTypeId() const {
        static ComponentID lastId = 0;
        return lastId++;
    }

public:
    bool isActive() const;
    void update();
    void destroy();
    void draw();

    template <typename T> ComponentID getComponentTypeId() const noexcept {
        static_assert(std::is_base_of<Component, T>::value, "");
        static ComponentID typeId = getComponentTypeId();
        return typeId;
    }

    template <typename T> bool hasComponent() const {
        return mComponentBitSet[getComponentTypeId<T>()];
    }

    template<typename T, typename ...TArgs> T& addComponent(TArgs&& ... mArgs) {
        using std::forward;
        using std::move;

        T* component = new T(forward<TArgs>(mArgs)...);
        component->entity = this;
        unique_ptr<Component> uPtr{component};
        mComponents.emplace_back(move(uPtr));

        mComponentArray[getComponentTypeId<T>()] = component;
        mComponentBitSet[getComponentTypeId<T>()] = true;

        component->init();
        return *component;
    }

    template<typename T> T& getComponent() const {
        auto ptr = mComponentArray[getComponentTypeId<T>()];
        return *static_cast<T*>(ptr);
    }
};

#endif // ENTITY_H
