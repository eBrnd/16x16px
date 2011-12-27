#include "player.hpp"

Player::Player(SDL_Surface* display)
{
  this->display = display;
  px = py = 50;
  sprite = NULL;
}

Player::~Player()
{
  if(sprite != NULL)
    SDL_FreeSurface(sprite);
}

bool Player::loadSprite(std::string filename)
{
  if(sprite != NULL)
    SDL_FreeSurface(sprite);
  if((sprite = IMG_Load(filename.c_str())) != NULL)
    return true;
  else
    return false;
}

void Player::draw(int x, int y)
{
  //TODO animation
  SDL_Rect src = { 0, 0, 16, 16 };
  SDL_Rect dst = { px - x, py - y, 16, 16 };
  SDL_BlitSurface(sprite, &src, display, &dst);
}

void Player::input(Uint8 direction)
{
  if(direction & 0x01)
    py-=2;
  if(direction & 0x02)
    py+=2;
  if(direction & 0x04)
    px-=2;
  if(direction & 0x08)
    px+=2;
}
