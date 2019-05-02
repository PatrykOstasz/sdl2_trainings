#ifndef POSITIONCOMPONENT_H_INCLUDED
#define POSITIONCOMPONENT_H_INCLUDED

#include "Component.h"

class PositionComponent : public Component {
private:
    int mXPos;
    int mYPos;

public:
    PositionComponent();
    PositionComponent(int x, int y);
    int getXPos() const;
    int getYPos() const;
    void setPosition(int newXPos, int newYPos);
    virtual void init() override;
    virtual void update() override;
    virtual ~PositionComponent();
};

#endif // POSITIONCOMPONENT_H_INCLUDED
