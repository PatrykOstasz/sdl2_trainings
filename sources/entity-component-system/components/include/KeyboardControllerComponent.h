#ifndef KEYBOARDCONTROLLER_H
#define KEYBOARDCONTROLLER_H

#include "Component.h"

class TransformComponent;

class KeyboardControllerComponent : public Component {
private:
    TransformComponent* mTransform;

public:
    virtual void init() override;
    virtual void update() override;
};

#endif // KEYBOARDCONTROLLER_H
