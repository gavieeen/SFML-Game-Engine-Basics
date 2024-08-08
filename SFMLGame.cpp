#include "../Header/Engine/SFMLGame.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "InitializationRoom.h"
#include <iostream>

SFMLGame *SFMLGame::instance = nullptr;

SFMLGame::SFMLGame()
    : frame_rate(60.f),
      window_width(1280),
      window_height(720),
      window_title("Soko-ban Game"),
      window(new sf::RenderWindow(sf::VideoMode(window_width, window_height), window_title)),
      time_per_frame(sf::seconds(1.f / frame_rate)),
      current_room(new InitializationRoom())
{
    // Do nothing for now
}

SFMLGame::~SFMLGame()
{
    delete window;
}
z
void SFMLGame::ProcessEvents()
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }
}

void SFMLGame::Draw()
{
    // std::cout << "Starting Draw" << std::endl;
    window->clear();
    current_room->Draw();
    window->display();
    // std::cout << "Ending Draw" << std::endl;
}

void SFMLGame::Step()
{
    // std::cout << "Starting Step" << std::endl;
    current_room->Step();
    // std::cout << "Ending Step" << std::endl;
}

void SFMLGame::Run()
{
    sf::Clock clock; // sfml clock
    sf::Time time_since_last_update = sf::Time::Zero;
    // std::cout << "Starting Run" << std::endl;
    while (window->isOpen())
    {
        time_since_last_update += clock.restart();
        ProcessEvents();
        while (time_since_last_update > time_per_frame)
        {
            Keyboard::GetInstance()->Update();
            Mouse::GetInstance()->Update();
            time_since_last_update -= time_per_frame;
            ProcessEvents();
            Step();
        }
        Draw();
    }
    // std::cout << "Ending Run" << std::endl;
}

SFMLGame *SFMLGame::GetInstance()
{
    instance = (instance) ? instance : new SFMLGame();
    return instance;
}

sf::RenderWindow *SFMLGame::GetWindow() const { return window; }

Room *SFMLGame::GetCurrentRoom() const { return current_room; }

float SFMLGame::GetFrameRate() const { return frame_rate; }

void SFMLGame::SetFrameRate(float frame_rate)
{
    this->frame_rate = frame_rate;
    time_per_frame = sf::seconds(1.f / frame_rate);
}

sf::Vector2i SFMLGame::GetWindowSize() const { return sf::Vector2i(window_width, window_height); }

void SFMLGame::SetWindowSize(int width, int height)
{
    delete window;
    window_width = width;
    window_height = height;
    window = new sf::RenderWindow(sf::VideoMode(window_width, window_height), window_title);
}

std::string SFMLGame::GetWindowTitle() const { return window_title; }

void SFMLGame::SetWindowTitle(const std::string &title)
{
    window_title = title;
    window->setTitle(window_title);
}