#ifndef POSITIONCOMPONENT_H_INCLUDED
#define POSITIONCOMPONENT_H_INCLUDED

#include "Component.h"

class PositionComponent : public Component {
private:
    int mXPos;
    int mYPos;

public:
    int getXPos() const;
    int getYPos() const;
    void setPosition(int newXPos, int newYPos);
    virtual void init() override;
    virtual void update() override;
};

#endif // POSITIONCOMPONENT_H_INCLUDED
