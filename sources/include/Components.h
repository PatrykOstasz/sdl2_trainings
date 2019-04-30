#ifndef COMPONENTS_H_INCLUDED
#define COMPONENTS_H_INCLUDED

#include "ECS.h"

class PositionComponent : public Component {
private:
    int xpos;
    int ypos;

public:
    int x() {return xpos;}
    int y() {return ypos; }

    int setPos(int x, int y) {
        xpos = x;
        ypos = y;
    }

    void init() override {
        xpos = 0;
        ypos = 0;
    }

    void update() override {
        xpos++;
        ypos++;
    }
};

#endif // COMPONENTS_H_INCLUDED
