#include "enemylist.hpp"

EnemyList::EnemyList(SDL_Surface* display)
{
  this->display = display;
  this->enemies = new std::vector<Enemy*>();
}

EnemyList::~EnemyList()
{
  delete(enemies); // TODO delete ALL the enemies
}

void EnemyList::add(int map_x, int map_y)
{
  Enemy* the_enemy = new Enemy(display);
  the_enemy->loadSprite("enemy.png", 9, 10);
  the_enemy->setMapPosition(map_x, map_y);
  enemies->push_back(the_enemy);
}

void EnemyList::draw(int x, int y)
{
  for(std::vector<Enemy*>::iterator it = enemies->begin(); it < enemies->end(); it++)
  {
    (*it)->draw(x,y);
  }
}
