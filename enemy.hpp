#ifndef ENEMY
#define ENEMY

#include <iostream>
#include <string>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

class Enemy
{
  private:
    SDL_Surface* display;
    SDL_Surface* sprite;
    int px, py;
    int width, height;
  public:
    Enemy(SDL_Surface* display);
    ~Enemy();
    bool loadSprite(std::string filename, int width, int height);
    void setMapPosition(int x, int y);
    void draw(int x, int y);
};

#endif
