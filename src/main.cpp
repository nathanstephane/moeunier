#include <iostream>
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <stdint.h>

int main(int argc, char* argv[])
{
    int16_t width = 800, height = 800;
    Game game;
    game.Initialize(width,height);
    game.Run();
    game.Destroy();
    return 0;
}