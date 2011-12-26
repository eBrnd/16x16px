#include <iostream>
#include <SDL/SDL.h>

#include "game.hpp"

int main(int argc, char** argv)
{
  int sdlopts = SDL_SWSURFACE | SDL_DOUBLEBUF;
  int colordepth = 32;

  SDL_Surface *display;
  display = SDL_SetVideoMode(320, 240, colordepth, sdlopts); // HWSURFACE?
  if(display == NULL)
  {
    std::cout << "Could not initialize video: " << SDL_GetError() << std::endl;
    exit(1);
  }

  Game* game = new Game(display);

  while(game->frame());
}
