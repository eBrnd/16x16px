#ifndef FOREGROUND
#define FOREGROUND

#include <iostream>
#include <fstream>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include "enemylist.hpp"

class Foreground
{
  private:
    SDL_Surface* display;
    SDL_Surface* tiles;
    Uint8* map;
    int width, height;
    EnemyList* enemylist;

  public:
    Foreground(SDL_Surface* display, EnemyList* enemylist);
    ~Foreground();
    bool loadTiles(std::string filename);
    bool loadMap(std::string filename);
    void draw(int x, int y);
    Uint8 collision(int x, int y, int swidth, int sheight);
};

#endif
