#include "enemy.hpp"

Enemy::Enemy(SDL_Surface* display)
{
  this->display = display;
  this->sprite = NULL;
  px = 4000;
  py = 1500;
  width = height = 0;
}

Enemy::~Enemy()
{
  if(sprite != NULL)
    SDL_FreeSurface(sprite);
}

bool Enemy::loadSprite(std::string filename, int width, int height)
{
  this->width = width;
  this->height = height;
  if(sprite != NULL)
    SDL_FreeSurface(sprite);
  if((sprite = IMG_Load(filename.c_str())) != NULL)
    return true;
  else
    return false;
}

void Enemy::draw(int x, int y)
{
  //TODO animation
  SDL_Rect src = { 0, 0, 16, 16 };
  SDL_Rect dst = { px/16 - x, py/16 - y, 16, 16 };
  SDL_BlitSurface(sprite, &src, display, &dst);
}
