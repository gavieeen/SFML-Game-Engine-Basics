#include "SFMLGame.h"

int main()
{
    SFMLGame::GetInstance()->SetWindowSize(800, 600);

    SFMLGame::GetInstance()->Run();
    return 0;
}

// Compile command

// g++  -std=c++17 main.cpp -I/opt/homebrew/Cellar/sfml/2.6.1/include -o main -L/opt/homebrew/Cellar/sfml/2.6.1/lib -lsfml-graphics -lsfml-window -lsfml-system