#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED
//Zenarii 2018


#include "SDL.h"
#include <iostream>

class Game {
public:
  Game();
  ~Game();

  void init(const char* title, int x_pos, int y_pos, int width, int height, bool fullscreen);

  void handleEvents();
  void update();
  void render();
  void clean();

  bool running() {return isRunning;}

private:
  bool isRunning;
  SDL_Window* window;
  SDL_Renderer* renderer;

};



#endif // GAME_HPP_INCLUDED
