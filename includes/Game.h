#ifndef GAME_H
#define GAME_H
#include <stdint.h>
#include <SFML/Graphics.hpp>


#define FPS 30
#define MILLISECS_PER_FRAME 1000/FPS 


class Game
{
    private:
    bool isRunning;
    sf::RenderWindow* window;
    sf::Clock clock;
    sf::Time previous_millisec_frames;
    public:
        Game();
        ~Game();
        void Initialize(int16_t& width, int16_t& height);
        void Run();
        void ProcessInput();
        void Setup();
        void Update();
        void Render();
        void Destroy();
};

#endif