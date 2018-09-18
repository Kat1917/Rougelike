#include "Game.hpp"


Game::Game(){}
Game::~Game(){}

void Game::init(const char* title, int x_pos, int y_pos, int width, int height, bool fullscreen) {
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    std::cout << "SDL initialised" << std::endl;

    int flags = 0;

    if(fullscreen) {
      flags = SDL_WINDOW_FULLSCREEN;
    }

    window = SDL_CreateWindow(title, x_pos, y_pos, width, height, flags);
    //check window initialised ok
    if(window) {
      std::cout << "Window Created" << std::endl;
    }

  }

}

void Game::handleEvents(){}

void Game::update(){}

void Game::render(){}

void Game::clean(){}
