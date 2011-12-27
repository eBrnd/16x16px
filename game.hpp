#ifndef GAME
#define GAME

#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_framerate.h>

#include "input.hpp"
#include "background.hpp"
#include "foreground.hpp"
#include "player.hpp"

class Game
{
  private:
    SDL_Surface* display;
    Input* input;
    Background* background;
    Foreground* foreground;
    Player* player;
    FPSmanager* fpsmanager;
    int i;

  public:
    Game(SDL_Surface* display);
    ~Game();
    bool frame();
};

#endif
