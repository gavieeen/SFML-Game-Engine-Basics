#include "SFMLGame.h"
#include "Mouse.h"
#include <iostream>

Mouse *Mouse::instance = nullptr;

Mouse::Mouse() { Update(); }

bool Mouse::IsButtonUp(sf::Mouse::Button button)
{
    return !current_button_states[button] && !previous_button_states[button];
}

bool Mouse::IsButtonDown(sf::Mouse::Button button)
{
    return current_button_states[button] && previous_button_states[button];
}

bool Mouse::IsButtonPressed(sf::Mouse::Button button)
{
    // previously up, now pressed
    return current_button_states[button] && !previous_button_states[button];
}

bool Mouse::IsButtonReleased(sf::Mouse::Button button)
{
    // previously down, now released
    return !current_button_states[button] && previous_button_states[button];
}

Mouse *Mouse::GetInstance()
{
    instance = (instance) ? instance : new Mouse();
    return instance;
}

sf::Vector2i Mouse::GetMousePosition() { return sf::Mouse::getPosition(*SFMLGame::GetInstance()->GetWindow()); }

void Mouse::Update()
{
    for (int i = 0; i < sf::Mouse::ButtonCount; ++i)
    {
        previous_button_states[i] = current_button_states[i];
        current_button_states[i] = sf::Mouse::isButtonPressed((sf::Mouse::Button)i);
    }
}