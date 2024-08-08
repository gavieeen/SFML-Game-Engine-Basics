#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

class GameObject
{
public:
    GameObject();
    virtual ~GameObject();

    virtual void Step();
    virtual void Draw();
};

#endif