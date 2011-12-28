#ifndef ENEMYLIST
#define ENEMYLIST

#include <vector>

#include "enemy.hpp"
#include "foreground.hpp"

class EnemyList
{
  private:
    std::vector<Enemy*>* enemies;
    SDL_Surface* display;
    Foreground* foreground;

  public:
    EnemyList(SDL_Surface* display, Foreground* foreground);
    ~EnemyList();
    void add(int map_x, int map_y);
    void draw(int x, int y);
    void update();
    //TODO clear
};

#endif
