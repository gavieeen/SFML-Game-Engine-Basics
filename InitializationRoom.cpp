#include "InitializationRoom.h"
#include "TextureManager.h"
#include "Box.h"
#include "SFMLGame.h"
#include <SFML/Graphics.hpp>

InitializationRoom::InitializationRoom()
{
    TextureManager::GetInstance()->AddTexture("box", "assets/box.png");
    // TextureManager::GetInstance()->AddTexture("goal", "assets/goal.png");
    // TextureManager::GetInstance()->AddTexture("hero", "assets/hero.png");
    // TextureManager::GetInstance()->AddTexture("villain", "assets/villain.png");
    // TextureManager::GetInstance()->AddTexture("wall", "assets/wall.png");
    Box* box = new Box();
}

// void InitializationRoom::Step()
// {
//     shape.setFillColor(sf::Color::Green);
// }

// void InitializationRoom::Draw()
// {
//     SFMLGame::GetInstance()->GetWindow()->draw(shape);
// }