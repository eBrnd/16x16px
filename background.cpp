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
  SDL_Rect bg_pos = { x, y, 320, 240 }; // TODO make width + height variable (window size)
  SDL_Rect dst_pos = { 0, 0, 320, 240 };
  SDL_BlitSurface(bg_surf, &bg_pos, display, &dst_pos);
}
