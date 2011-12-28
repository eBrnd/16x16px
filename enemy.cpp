#include "enemy.hpp"

Enemy::Enemy(SDL_Surface* display)
{
  this->display = display;
  this->sprite = NULL;
  px = 0;
  py = 0;
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

void Enemy::setMapPosition(int x, int y)
{
  px = x * 256;
  py = y * 256;
}

void Enemy::draw(int x, int y)
{
  SDL_Rect src = { 0, 0, 16, 16 };
  SDL_Rect dst = { px/16 - x, py/16 - y, 16, 16 };
  SDL_BlitSurface(sprite, &src, display, &dst);
}
