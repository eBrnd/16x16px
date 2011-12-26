#include "game.hpp"

Game::Game(SDL_Surface* display)
{
  this->display = display;
  this->input = new Input();
  this->background = new Background(display);
  background->loadFile("background.png");
}

bool Game::frame()
{
  input->read();
  background->draw(0, 0);
  SDL_Flip(display);
  if(input->escape)
    return false;
  else
    return true;
}
