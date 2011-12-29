#ifndef ENEMYLIST
#define ENEMYLIST

#include <vector>

#include "enemy.hpp"
#include "foreground.hpp"
#include "box.hpp"
#include "player.hpp"

class EnemyList
{
  private:
    std::vector<Enemy*>* enemies;
    SDL_Surface* display;
    Foreground* foreground;
    Player* player;

  public:
    EnemyList(SDL_Surface* display, Foreground* foreground, Player* player);
    ~EnemyList();
    void add(int map_x, int map_y);
    void draw(int x, int y);
    void update();
    //TODO clear
};

#endif
