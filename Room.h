#ifndef ROOM_H
#define ROOM_H

#include "GameObject.h"
#include <vector>

class Room
{
public:
    Room(); 
    // virtual destructor -> base class destructor is called first, then derived class destructor
    virtual ~Room();

    virtual void Step();
    virtual void Draw();

    void AddObject(GameObject* object);

private:
    std::vector<GameObject*> objects;
};

#endif