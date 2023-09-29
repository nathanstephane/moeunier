#ifndef GAME_H
#define GAME_H
#include <stdint.h>
//#include "../libs/sfml/include/SFML/Graphics.hpp"
#include <SFML/Graphics.hpp>

class Game
{
    private:
    sf::RenderWindow* window;
    public:
        Game();
        ~Game();
        void Initialize(int8_t& width, int8_t& height);
        void Run();
        void ProcessInput();
        void Update();
        void Render();
        void Destroy();
};

#endif