#include "Keyboard.h"

Keyboard *Keyboard::instance = nullptr;

Keyboard::Keyboard() { Update(); }

Keyboard *Keyboard::GetInstance()
{
    instance = (instance) ? instance : new Keyboard();
    return instance;
}

bool Keyboard::IsKeyUp(sf::Keyboard::Key key)
{
    return !current_key_states[key] && !previous_key_states[key];
}

bool Keyboard::IsKeyDown(sf::Keyboard::Key key)
{
    return current_key_states[key] && previous_key_states[key];
}

bool Keyboard::IsKeyPressed(sf::Keyboard::Key key)
{
    // previously up, now pressed
    return current_key_states[key] && !previous_key_states[key];
}
bool Keyboard::IsKeyReleased(sf::Keyboard::Key key)
{
    // previously down, now released
    return !current_key_states[key] && previous_key_states[key];
}

void Keyboard::Update()
{
    for (int i = 0; i < sf::Keyboard::KeyCount; ++i)
    {
        previous_key_states[i] = current_key_states[i];
        current_key_states[i] = sf::Keyboard::isKeyPressed((sf::Keyboard::Key)i);
    }
}