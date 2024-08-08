#include "Hero.h"

Hero::Hero()
    : Object("hero")
{
    GetSprite()->setPosition(100, 100);
}