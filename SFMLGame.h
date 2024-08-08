#ifndef SFMLGAME_H
#define SFMLGAME_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Room.h"

class SFMLGame
{
public:
    ~SFMLGame();

    void ProcessEvents();
    void Draw();
    void Step();
    void Run();
    static SFMLGame *GetInstance();

    sf::RenderWindow *GetWindow() const;

    Room *GetCurrentRoom() const;

    float GetFrameRate() const;
    void SetFrameRate(float frame_rate);

    sf::Vector2i GetWindowSize() const;
    void SetWindowSize(int width, int height);

    std::string GetWindowTitle() const;
    void SetWindowTitle(const std::string &title);

private:
    SFMLGame();

    float frame_rate;
    int window_width;
    int window_height;

    std::string window_title;

    sf::RenderWindow *window;
    sf::Time time_per_frame;
    Room* current_room;

    static SFMLGame *instance;
};

#endif