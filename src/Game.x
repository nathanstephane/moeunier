#include "../includes/Game.h"
#include <iostream>

 Game::Game()
{
    std::cout<<"Game constructor called";
}

Game::~Game()
{
    std::cout<<"Game destructor called";

}

void Game::Initialize(int8_t& width, int8_t& height)
{
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(width,height),"");
    if (!window)
    {
        std::cerr<<"Error Creating the window.\n";
    }
    
}

void Game::Run()
{
        while (true)
        {
            ProcessInput();
            Update();
            Render();
        }
        
}

void Game::ProcessInput()
{

}

void Game::Update()
{

}

void Game::Render()
{

}

void Game::Destroy()
{

}

