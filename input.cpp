#include "input.hpp"

Input::Input()
{
}

void Input::read()
{
  // set them all to false
  // TODO think about using a bitmask here, will make things much faster!
  escape = false;
  SDL_Event event;
  while(SDL_PollEvent(&event))
  {
    switch(event.type)
    {
      case SDL_KEYDOWN:
        switch(event.key.keysym.sym)
        {
          case SDLK_ESCAPE:
            escape = true;
            break;
          default:
            break;
        }
        break;
      case SDL_QUIT:
        exit(0);
    }
  }
}
