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
  this->player = new Player(display, foreground);
  player->loadSprite("player.png", 10, 13);
  this->enemy = new Enemy(display);
  enemy->loadSprite("enemy.png", 9, 10);

  fpsmanager = new FPSmanager();
  SDL_initFramerate(fpsmanager);
  SDL_setFramerate(fpsmanager, 30);
}

bool Game::frame()
{
  int i = player->getX() - 160;
  SDL_framerateDelay(fpsmanager);
  background->draw(i, 0);
  foreground->draw(i, 0);
  player->input(input->direction);
  player->physics();
  player->draw(i, 0);
  enemy->draw(i, 0);
  SDL_Flip(display);
  input->read();
  if(input->escape)
    return false;
  else
    return true;
}
