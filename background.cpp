#include "background.hpp"

Background::Background(SDL_Surface* display)
{
  this->display = display;
  this->bg_surf = NULL;
}

Background::~Background()
{
  if(bg_surf != NULL)
    SDL_FreeSurface(bg_surf);
}

bool Background::loadFile(std::string filename)
{
  if(bg_surf != NULL)
    SDL_FreeSurface(bg_surf);
  if((bg_surf = IMG_Load(filename.c_str())) != NULL)
    return true;
  else
    return false;
}

void Background::draw(int x, int y)
{
  SDL_Rect bg_pos = { x % bg_surf->w, y % bg_surf->h, 320, 240 }; // TODO make width + height variable (window size)
  SDL_Rect dst_pos = { 0, 0, 320, 240 };
  SDL_BlitSurface(bg_surf, &bg_pos, display, &dst_pos);
  if((x % bg_surf->w) + 320 > bg_surf->w) // fill in the rest when we're scrolling "between" instances of the bg
  { // TODO make this work for vertical scrolling as well
    SDL_Rect bg_fill_pos = { 0, y % bg_surf->h, 320, 240 };
    SDL_Rect fill_dst = { bg_surf->w - (x % bg_surf->w), 0, 320, 240 };
    SDL_BlitSurface(bg_surf, &bg_fill_pos, display, &fill_dst);
  }
}
