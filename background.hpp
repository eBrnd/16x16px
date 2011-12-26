#ifndef BACKGROUND
#define BACKGROUND

#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class Background
{
  private:
    SDL_Surface* bg_surf;
    SDL_Surface* display;
  public:
    Background(SDL_Surface* display);
    ~Background();
    bool loadFile(std::string filename);
    void draw(int x, int y);
};

#endif
