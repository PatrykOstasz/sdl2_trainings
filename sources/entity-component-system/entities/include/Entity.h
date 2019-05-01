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
using ComponentID = size_t;

class Entity {
private:
    bool mActive = true;
    vector<unique_ptr<Component>> mComponents;
    ComponentBitSet mComponentBitSet;
    ComponentArray mComponentArray;

    ComponentID getComponentTypeId();

public:
    bool isActive() const;
    void update();
    void destroy();
    void draw() {}

    template <typename T> ComponentID getComponentTypeId() noexcept;
    template <typename T> bool hasComponent() const;
    template<typename T> T& getComponent() const;
    template<typename T, typename ... TArgs> T& addComponent(TArgs&& ... mArgs);
};

#endif // ENTITY_H
