#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <SFML/Graphics.hpp>

class Keyboard
{
public:
    static Keyboard *GetInstance();

    bool IsKeyUp(sf::Keyboard::Key key); // while up TRUE
    bool IsKeyDown(sf::Keyboard::Key key); // while down TRUE
    bool IsKeyPressed(sf::Keyboard::Key key); // moment of press TRUE
    bool IsKeyReleased(sf::Keyboard::Key key); // moment of release TRUE

    void Update();


private:
    Keyboard();

    static Keyboard *instance;

    bool current_key_states[sf::Mouse::ButtonCount];
    bool previous_key_states[sf::Mouse::ButtonCount];
};

#endif