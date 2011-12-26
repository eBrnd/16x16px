#ifndef GAME
#define GAME

#include <iostream>
#include <SDL/SDL.h>

#include "input.hpp"
#include "background.hpp"

class Game
{
  private:
    SDL_Surface* display;
    Input* input;
    Background* background;

  public:
    Game(SDL_Surface* display);
    ~Game();
    bool frame();
};

#endif
