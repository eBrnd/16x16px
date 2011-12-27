#include "foreground.hpp"

Foreground::Foreground(SDL_Surface* display)
{
  this->display = display;
  this->tiles = NULL;
  this->map = NULL;
  width = height = 0;
}

Foreground::~Foreground()
{
  if(tiles != NULL)
    SDL_FreeSurface(tiles);
  if(map != NULL)
    free(map);
}

bool Foreground::loadTiles(std::string filename)
{
  if(tiles != NULL)
    SDL_FreeSurface(tiles);
  if((tiles = IMG_Load(filename.c_str())) != NULL)
    return true;
  else
    return false;
}

bool Foreground::loadMap(std::string filename)
{
  if(map != NULL)
  {
    free(map);
    map = NULL;
  }
  std::ifstream file;
  file.open(filename.c_str());
  if(file.is_open())
  {
    file >> width;
    file >> height;

    map = (Uint8*)malloc(width * height);

    for(int i = 0; i < width * height; i++)
    {
      int val;
      file >> val;
      map[i] = (Uint8)val;
    }
    file.close();
    return true;
  } else {
    return false;
  }
}

void Foreground::draw(int x, int y)
{
  int st_x = x / 16;
  int st_y = y / 16;

  for(int t_y = st_y; t_y < st_y + 12; t_y++)
    for(int t_x = st_x; t_x < st_x + 20; t_x++)
    {
      if((int)map[width * t_y + t_x] != 0)
      {
        SDL_Rect src = { (map[width * t_y + t_x] - 1) * 16, 0, 16, 16 };
        SDL_Rect dst = { t_x * 16 - x, t_y * 16, 16, 16 };
        SDL_BlitSurface(tiles, &src, display, &dst);
      }
    }
}
