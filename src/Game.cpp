#include <iostream>
#include "Game.hpp"
#include "Logger.hpp"
#include "ECS.hpp"

 Game::Game()
{
    isRunning=false;
    Logger::Log("Game constructor called");
}

Game::~Game()
{
    Logger::Log("Game destructor called");
}

void Game::Initialize(int16_t& width, int16_t& height)
{
     window = new sf::RenderWindow(sf::VideoMode(width,height),"");
    if (!window)
    {
        Logger::Err("Error Creating the window.\n");
    }
    isRunning=true;
    
}

void Game::Setup()
{
    
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
    return t1>t2;
}

void Game::Update()
{
   sf::Int32 timeToWait = MILLISECS_PER_FRAME - (clock.getElapsedTime().asMilliseconds()- previous_millisec_frames.asMilliseconds());
    if (timeToWait > 0 && timeToWait <= MILLISECS_PER_FRAME)
    {
    
        sf::sleep(sf::milliseconds(timeToWait));
    }   

    double deltaTime = (clock.getElapsedTime().asMilliseconds() - previous_millisec_frames.asMilliseconds())/1000.0;
    previous_millisec_frames = clock.getElapsedTime();

   
}

void Game::Render()
{
    window->clear({21,21,21,255}); 
  
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

