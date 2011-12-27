#include "player.hpp"

Player::Player(SDL_Surface* display, Foreground* foreground)
{
  this->display = display;
  this->foreground = foreground;
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

  foreground->collision(px, py); // TODO this is not the right place to to this - make somethig like a game logic...
}

void Player::input(Uint8 direction)
{
  if(direction & 0x01)
    py-=1;
  if(direction & 0x02)
    py+=1;
  if(direction & 0x04)
    px-=1;
  if(direction & 0x08)
    px+=1;
}
