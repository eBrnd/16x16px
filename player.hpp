#ifndef PLAYER
#define PLAYER

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <string>

#include "foreground.hpp"
#include "box.hpp"

class Player
{
  private:
    SDL_Surface* display;
    SDL_Surface* sprite;
    Foreground* foreground;
    int width, height;
    int px, py;
    int vx, vy;
    int jumping;
    bool faceRight;
    int animation_time;
    int death_animation;
  public:
    Player(SDL_Surface* display, Foreground* foreground);
    ~Player();
    Uint8 control;
    bool loadSprite(std::string filename, int width, int height);
    void draw(int x, int y);
    void input(Uint8 direction);
    void physics();
    int getX();
    Box getBbox();
    int hit();
};

#endif
