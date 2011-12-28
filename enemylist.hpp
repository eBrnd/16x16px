#ifndef ENEMYLIST
#define ENEMYLIST

#include <vector>

#include "enemy.hpp"

class EnemyList
{
  private:
    std::vector<Enemy*>* enemies;
    SDL_Surface* display;

  public:
    EnemyList(SDL_Surface* display);
    ~EnemyList();
    void add(int map_x, int map_y);
    void draw(int x, int y);
    //TODO clear
};

#endif
