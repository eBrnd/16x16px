#include "enemy.hpp"

Enemy::Enemy(SDL_Surface* display, Foreground* foreground)
{
  this->display = display;
  this->foreground = foreground;
  this->sprite = NULL;
  px = 0;
  py = 0;
  vy = 0;
  vx = 16;
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

void Enemy::update()
{
  // gravity
  vy = vy >= 64 ? 64 : vy + 16;
  while(foreground->collision(px/16, (py+vy)/16, width, height))
  {
    if(vy > 0)
    {
      vy--;
    } else {
      vy = 8;
    }
  }
  py += vy;

  // horizontal movement
  if(foreground->collision((px+vx)/16, py/16, width, height))
    vx = -vx;
  px += vx;
}

void Enemy::draw(int x, int y)
{
  SDL_Rect src = { vx > 0 ? 16 : 0, 0, 16, 16 };
  SDL_Rect dst = { px/16 - x, py/16 - y, 16, 16 };
  SDL_BlitSurface(sprite, &src, display, &dst);
}
