#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>

// game object BASE class 
// - virtual functions -> virtual destructor to avoid memory leaks

class Object
{
public:
    Object(const std::string &resource = "");

    virtual ~Object();

    virtual void Step();
    virtual void Draw();

    sf::Sprite *GetSprite();

private:
    sf::Sprite *sprite; // sprite ptr
};


#endif