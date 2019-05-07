#ifndef COMPONENT_H
#define COMPONENT_H

class Entity;

class Component {
public:
    Entity* entity = nullptr;
    virtual void init() {};
    virtual void update() {};
    virtual void draw() {};

    virtual ~Component() {}
};

#endif // COMPONENT_H
