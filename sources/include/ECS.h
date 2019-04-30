/*
ECS.h - Entity Component System

Ten plik zawiera implementacjê ECS za pomoc¹ szablonów w c++.
outline:
    inline ComponentId getComponentTypeId() : zwraca identyfikator aktualnie utworzonego componentu
    t<>inline ComponentId getComponentTypeId(): zwaraca identyfikator dla konkretnego typu Componentu

    przechowuje te¿ informacje o componentach w postaci mapy bitowej flag. <ComponentBitSet>

    klasa Component zawiera wskaŸnik na swojego w³aœciciela typu Entity
    oraz standardowe metody init(), update() oraz draw()

    klasa Entity zawiera:
        informacje o tym czy jest aktywna,
        wektor wskaŸników na komponenty
        identyczn¹ tablicê komponentów oraz bitset flag

        update() globalnie aktualizuje wszystkie componenty zwi¹zane z dan¹ jednostk¹


*/
#ifndef ECS_H_INCLUDED
#define ECS_H_INCLUDED

#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <memory>
#include <vector>

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentTypeId() {
    static ComponentID lastId = 0;
    return lastId++;
}

template <typename T> inline ComponentID getComponentTypeId() noexcept { //czemu tu jest template?
    ComponentID typeID = getComponentTypeId();
    return typeID;
}

constexpr std::size_t maxComponents = 32; //maksymalna iloœæ komponentów per jednostkê

using ComponentBitSet = std::bitset<maxComponents>; // mapa bitowa w³¹czonych/wy³¹czonych flag komponentów
using ComponentArray = std::array<Component*, maxComponents>; //tablica wskaŸników na aktualne komponenty

class Component {
public:
    Entity* entity;
    virtual void init() {}
    virtual void update() {}
    virtual void draw() {}

    virtual ~Component();
};

class Entity {
private:
    bool active = true;
    std::vector<unique_ptr<Component>> components;
    ComponentBitSet componentBitSet;
    ComponentArray componentArray;

public:
    void update() {
        for (auto& c : componenets) c->update();
        for (auto& c : componenets) c->draw();
    }

    void draw() {}
    bool isActive() const {return active;}
    void destroy() {active = false;}

    template <typename T> bool hasComponent() const {
        return componentBitSet[getComponentTypeId<T>()];
    }
    template<typename T, typename ... TArgs> T& addComponent(TArgs&& ... mArgs) {
        T* component = new T(std::forward<TArgs>(mArgs)...));
        component->entity = this;
        std::unique_ptr<Component> uPtr{component};
        components.emplace_back(std::move(uPtr));

        componentArray[getComponentTypeId<T>()] = component;
        componentBitSet[getComponentTypeId<T>()] = true;

        component->init();
        return *component;
    }

    template<typename T> T& getComponent() const {
        auto ptr(componentArray[getComponentTypeId<T>()]);
        return *static_cast<T*>(ptr);
    }
};

class Manager {
private:
    std::vector<std::unique_ptr<Entity>> entities;
public:
    void update() {
        for (auto e : entities) e->update();
    }
    void draw() {
        for (auto e : entities) e->draw();
    }

    void refresh() {
        entities.erase(remove_if(begin(entities), end(entities), [](const std::unique_ptr<Entity> &mEntity){return !mEntity->isActive()}), end(entities));
    }

    Entity& addEntity() {
        Entity* e(new Entity());
        unique_ptr<Entity> uPtr(e);
        entities.emplace_back(std::move(uPtr));
        return *e;
    }
};
#endif // ECS_H_INCLUDED
