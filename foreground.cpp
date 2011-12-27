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

  for(int t_y = st_y; t_y <= st_y + 12; t_y++)
    for(int t_x = st_x; t_x <= st_x + 20; t_x++)
    {
      if(map[width * (t_y % height) + (t_x % width)] != 0)
      {
        SDL_Rect src = { (map[width * (t_y % height) + (t_x % width)] - 1) * 16, 0, 16, 16 };
        SDL_Rect dst = { t_x * 16 - x, t_y * 16, 16, 16 };
        SDL_BlitSurface(tiles, &src, display, &dst);
      }
    }
}

Uint8 Foreground::collision(int x, int y)
{
  int m_x = x / 16;
  int m_y = y / 16;
  Uint8 result = 0;

  if(map[width * (m_y % height) + (m_x % width)] != 0)
    result |= 0x01;
  if(map[width * ((m_y+1) % height) + (m_x % width)] != 0)
    result |= 0x02;
  if(map[width * (m_y % height) + ((m_x+1) % width)] != 0)
    result |= 0x04;
  if(map[width * ((m_y+1) % height) + ((m_x+1) % width)] != 0)
    result |= 0x08;

  std::cout << "Collision: A " << (result & 0x01) << " B " << (result & 0x02) << " C " << (result & 0x04) << " D " << (result & 0x08) << std::endl;
  return result;
}
