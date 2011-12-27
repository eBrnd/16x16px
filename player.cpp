#include "player.hpp"

Player::Player(SDL_Surface* display, Foreground* foreground)
{
  this->display = display;
  this->foreground = foreground;
  px = py = 50*16;
  vx = vy = jumping = 0;
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
  SDL_Rect dst = { px/16 - x, py/16 - y, 16, 16 };
  SDL_BlitSurface(sprite, &src, display, &dst);
}

void Player::input(Uint8 direction)
{
  control = direction;
  if(control & 0x01 && jumping < 4) // jump
  {
    vy -= 12;
    jumping++;
  }
  if(control & 0x04) // right
  {
    vx = -64;
  } else if(control & 0x08) // right
  {
    vx = 64;
  } else {
    vx = 0;
  }
}

void Player::physics()
{
  // Gravity
  if(vy < 64)
    vy+=2;
  if(vy > 0 && foreground->collision(px/16, py/16)) // touching the ground
  {
    vy = 0;
    jumping = 0;
  }
  py += vy;
  px += vx;
}
