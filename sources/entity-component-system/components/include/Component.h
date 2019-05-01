#ifndef COMPONENT_H
#define COMPONENT_H

class Entity;

class Component {
public:
    Entity* entity;
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;

    virtual ~Component();
};

#endif // COMPONENT_H
