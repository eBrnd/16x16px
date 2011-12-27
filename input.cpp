#include "input.hpp"

Input::Input()
{
  direction = 0x00;
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
          case SDLK_UP:
            direction |= 0x01;
            break;
          case SDLK_DOWN:
            direction |= 0x02;
            break;
          case SDLK_LEFT:
            direction |= 0x04;
            break;
          case SDLK_RIGHT:
            direction |= 0x08;
            break;
          default:
            break;
        }
        break;
      case SDL_KEYUP:
        switch(event.key.keysym.sym)
        {
          case SDLK_ESCAPE:
            escape = false;
            break;
          case SDLK_UP:
            direction &= ~0x01;
            break;
          case SDLK_DOWN:
            direction &= ~0x02;
            break;
          case SDLK_LEFT:
            direction &= ~0x04;
            break;
          case SDLK_RIGHT:
            direction &= ~0x08;
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
