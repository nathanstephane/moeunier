#ifndef GAME_H
#define GAME_H
#include <stdint.h>
#include <SFML/Graphics.hpp>

class Game
{
    private:
    bool isRunning;
    sf::RenderWindow* window;
    public:
        Game();
        ~Game();
        void Initialize(int16_t& width, int16_t& height);
        void Run();
        void ProcessInput();
        void Update();
        void Render();
        void Destroy();
};

#endif