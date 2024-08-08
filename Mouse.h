#ifndef MOUSE_H
#define MOUSE_H

#include <SFML/Graphics.hpp>

class Mouse
{
public:
    static Mouse *GetInstance();

    sf::Vector2i GetMousePosition();

    bool IsButtonUp(sf::Mouse::Button button); // while up TRUE
    bool IsButtonDown(sf::Mouse::Button button); // while down TRUE
    bool IsButtonPressed(sf::Mouse::Button button); // moment of press TRUE
    bool IsButtonReleased(sf::Mouse::Button button); // moment of release TRUE

    void Update();

private:
    Mouse();

    static Mouse *instance;

    bool current_button_states[sf::Mouse::ButtonCount];
    bool previous_button_states[sf::Mouse::ButtonCount];
};

#endif