#ifndef GAME
#define GAME

#include <SDL/SDL.h>

#include "input.hpp"

class Game
{
  private:
    SDL_Surface* display;
    Input* input;

  public:
    Game(SDL_Surface* display);
    ~Game();
    bool frame();
};

#endif
