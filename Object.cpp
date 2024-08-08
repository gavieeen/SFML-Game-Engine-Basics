#include "SFMLGame.h"
#include "Object.h"
#include "TextureManager.h"

Object::Object(const std::string &resource)
    : sprite(new sf::Sprite())
{
    if (!resource.empty())
    {
        sf::Texture *texture = TextureManager::GetInstance()->GetTexture(resource);
        sprite->setTexture(*texture); // must pass reference to texture object
    }
}

Object::~Object() { delete sprite; }

void Object::Step() {}

void Object::Draw()
{
    if (sprite)
        SFMLGame::GetInstance()->GetWindow()->draw(*sprite);
}

sf::Sprite *Object::GetSprite() { return sprite; }