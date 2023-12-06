#include "Game.hpp"
#include <iostream>

 Game::Game()
{
    isRunning=false;
    std::cout<<"Game constructor called";
}

Game::~Game()
{
    std::cout<<"Game destructor called";

}

void Game::Initialize(int16_t& width, int16_t& height)
{
     window = new sf::RenderWindow(sf::VideoMode(width,height),"");
    if (!window)
    {
        std::cerr<<"Error Creating the window.\n";
    }
    isRunning=true;
    //window->setFramerateLimit(60);
}


glm::vec2 playerPosition;
glm::vec1 playerVelocity;
void Game::Setup()
{
    
    playerPosition = glm::vec2(10.0,20.0);
    playerVelocity = glm::vec1(20.0);
}

void Game::Run()
{
        Setup();
        while (isRunning)
        {
            ProcessInput();
            Update();
            Render();
        }
        
}

void Game::ProcessInput()
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            isRunning = false;
            break;
        
        case sf::Event::KeyPressed:
            if (event.key.scancode == sf::Keyboard::Scan::Escape)
            {
                isRunning = false;
            }
            break;
        }
    }
    
}
bool TimeDifference(const sf::Int32& t1,const sf::Int32& t2)
{
    // std::cout<<"t1: "<<t1<<"\n";
    // std::cout<<"t2: "<<t2<<"\n";
    return t1>t2;
}
void Game::Update()
{
   sf::Int32 timeToWait = MILLISECS_PER_FRAME - (clock.getElapsedTime().asMilliseconds()- previous_millisec_frames.asMilliseconds());
    if (timeToWait > 0 && timeToWait <= MILLISECS_PER_FRAME)
    {
        std::cout<<"SLEEPING\n";
        sf::sleep(sf::milliseconds(timeToWait));
    }   
//    while(!TimeDifference(clock.getElapsedTime().asMilliseconds(), previous_millisec_frames.asMilliseconds() + static_cast<sf::Int32>( MILLISECS_PER_FRAME)))
//    {
//        // std::cout<<"True\n" << previous_millisec_frames.asMilliseconds()<<"\n";
//    }
    double deltaTime = (clock.getElapsedTime().asMilliseconds() - previous_millisec_frames.asMilliseconds())/1000.0;
    previous_millisec_frames = clock.getElapsedTime();

    std::cout<<deltaTime<<"\n";
    playerPosition.x += playerVelocity.x*deltaTime;
    playerPosition.y += 0;
}

void Game::Render()
{
    window->clear({21,21,21,255});
    //display or draw stuff
    sf::RectangleShape r(sf::Vector2f(10,10));
    r.setFillColor({255,255,255,255});
    window->draw(r);
    //texture
    sf::Texture texture;
    if (!texture.loadFromFile("./assets/sprites/characters/bob_idle/tile000.png"))
    {
        std::cerr<<"Failed to load texture";
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(playerPosition.x, playerPosition.y);
    window->draw(sprite);
    window->display();
}

void Game::Destroy()
{
    if(window !=NULL)
    {
        delete window;
        window=NULL;
    }
}

