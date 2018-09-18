#include "Game.hpp"


Game::Game(){}
Game::~Game(){}

void Game::init(const char* title, int x_pos, int y_pos, int width, int height, bool fullscreen) {
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0) {
    std::cout << "SDL initialised" << std::endl;

    //Creates Window
    int flags = 0;

    if(fullscreen) {
      flags = SDL_WINDOW_FULLSCREEN;
    }

    window = SDL_CreateWindow(title, x_pos, y_pos, width, height, flags);
    //check window initialised ok
    if(window)
      std::cout << "Window Created" << std::endl;

    //Creates Renderer
    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer) {
      //It's Colour
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      std::cout << "Renderer Created" << std::endl;
    }
    isRunning = true;
  } else { //SDL not initisalised
    isRunning = false;
  }
}


void Game::handleEvents() {
  SDL_Event event;

  SDL_PollEvent(&event);
  switch(event.type) {
    case SDL_QUIT:
      isRunning = false;
      break;

    default:
      break;
  }
}

void Game::update(){}

void Game::render() {
  SDL_RenderClear(renderer); //Clear Screen 1st
  //Stuff will be rendered here
  SDL_RenderPresent(renderer);
}

void Game::clean() {
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "Game cleaned" << std::endl;
}
