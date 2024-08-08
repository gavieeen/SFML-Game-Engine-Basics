#include "Box.h"
#include "SFMLGame.h"

Box::Box()
    : Object("box")
{
    GetSprite()->setPosition(100, 100); // Access the sprite through the public method.
}