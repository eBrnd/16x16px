#include "player.hpp"

Player::Player(SDL_Surface* display, Foreground* foreground)
{
  this->display = display;
  this->foreground = foreground;
  px = py = 50*16;
  vx = vy = jumping = death_animation = 0;
  faceRight = true;
  sprite = NULL;
}

Player::~Player()
{
  if(sprite != NULL)
    SDL_FreeSurface(sprite);
}

bool Player::loadSprite(std::string filename, int width, int height) // TODO autodetect witdh / height
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

void Player::draw(int x, int y)
{
  //TODO animation
  animation_time = (animation_time + vx) % 512;
  int animation_phase = animation_time > 0 ? animation_time / 171 : -animation_time / 171;
  SDL_Rect src = { death_animation ? 64 : jumping ? 48 : animation_phase * 16, 0, 16, 16 };
  SDL_Rect dst = { px/16 - x, py/16 - y, 16, 16 };
  SDL_BlitSurface(sprite, &src, display, &dst);
}

void Player::input(Uint8 direction)
{
  if(death_animation)
  {
    vx = 0;
    if(death_animation-- == 100)
      vy = -32;
    vy += 16;
    py += vy;
  } else {
    // moving left and right
    if(direction & 0x04)
    {
      vx -= 16;
      faceRight = false;
    }
    if(direction & 0x08)
    {
      vx += 16;
      faceRight = true;
    }
    if(!direction)
      vx = 0;
    if(vx > 64)
      vx = 64;
    if(vx < -64)
      vx = -64;
    // test for collision
    if(foreground->collision((px+vx)/16, py/16, width, height) > 15)
      death_animation = 100;
    else
    {
      while(foreground->collision((px+vx)/16, py/16, width, height))
        faceRight ? vx-- : vx++;
      px += vx;

      if(direction & 0x01 && jumping < 4)
      {
        jumping++;
        vy -= 48;
      }
    }
  }
}

void Player::physics()
{
  if(!death_animation)
  {
    // gravity
    vy = vy >= 64 ? 64 : vy + 16;
    if(foreground->collision(px/16, (py+vy)/16, width, height) > 15)
      death_animation = 100;
    else
    {
      while(foreground->collision(px/16, (py+vy)/16, width, height))
      {
        if(vy > 0)
        {
          jumping = 0;
          vy--;
        } else {
          vy = 8;
        }
      }
      py += vy;
    }
  }
}

int Player::getX()
{
  return px / 16;
}

Box Player::getBbox()
{
  return Box(px / 16, px / 16 + width, py / 16, py / 16 + height);
}

int Player::hit()
{
  if(vy > 0)
    return -1; // player hit enemy
  else
  {
    death_animation = 100;
    return 0; // enemy hit player
  }
}
