#include "game.hpp"

Game::Game(SDL_Surface* display)
{
  this->display = display;
  this->input = new Input();
  this->background = new Background(display);
  background->loadFile("background.png");
  this->foreground = new Foreground(display);
  foreground->loadTiles("tiles.png");
  foreground->loadMap("map");
  this->player = new Player(display);
  player->loadSprite("player.png");

  fpsmanager = new FPSmanager();
  SDL_initFramerate(fpsmanager);
  SDL_setFramerate(fpsmanager, 30);

  i = 0;
}

bool Game::frame()
{
  SDL_framerateDelay(fpsmanager);
  background->draw(++i, 0);
  foreground->draw(i, 0);
  player->draw(i, 0);
  SDL_Flip(display);
  input->read();
  player->input(input->direction);
  if(input->escape)
    return false;
  else
    return true;
}
