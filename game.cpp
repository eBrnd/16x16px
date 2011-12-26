#include "game.hpp"

Game::Game(SDL_Surface* display)
{
  this->display = display;
  this->input = new Input();
  this->background = new Background(display);
  background->loadFile("background.png");

  fpsmanager = new FPSmanager();
  SDL_initFramerate(fpsmanager);
  SDL_setFramerate(fpsmanager, 30);
}

bool Game::frame()
{
  SDL_framerateDelay(fpsmanager);
  background->draw(i++, 0);
  SDL_Flip(display);
  input->read();
  if(input->escape)
    return false;
  else
    return true;
}
