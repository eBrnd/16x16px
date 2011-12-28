#ifndef FOREGROUND
#define FOREGROUND

#include <iostream>
#include <fstream>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class Foreground
{
  private:
    SDL_Surface* display;
    SDL_Surface* tiles;
    Uint8* map;
    Uint8* enemymap;
    int width, height;

  public:
    Foreground(SDL_Surface* display);
    ~Foreground();
    bool loadTiles(std::string filename);
    bool loadMap(std::string filename);
    void draw(int x, int y);
    Uint8 collision(int x, int y, int swidth, int sheight);
    int getWidth();
    int getHeight();
    Uint8* getEnemyMap();
};

#endif
