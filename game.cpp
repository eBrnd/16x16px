#include "game.hpp"

Game::Game(SDL_Surface* display)
{
  this->display = display;
  this->input = new Input();
}

bool Game::frame()
{
  input->read();
  if(input->escape)
    return false;
  else
    return true;
}
