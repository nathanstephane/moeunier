#include "Game.h"
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
    
}

void Game::Run()
{
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

void Game::Update()
{

}

void Game::Render()
{
    //display or draw stuff
    window->clear({255,0,0,255});

    //todo render game obj
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

