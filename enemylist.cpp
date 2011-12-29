#include "enemylist.hpp"

EnemyList::EnemyList(SDL_Surface* display, Foreground* foreground, Player* player)
{
  this->display = display;
  this->foreground = foreground;
  this->player = player;
  this->enemies = new std::vector<Enemy*>();

  // now, fill the map
  int mw = foreground->getWidth();
  int mh = foreground->getHeight();
  Uint8* em = foreground->getEnemyMap();
  for(int i = 0; i < mw * mh; i++)
    if(em[i])
      add(i % mw, i / mw);
}

EnemyList::~EnemyList()
{
  for(std::vector<Enemy*>::iterator it = enemies->begin(); it < enemies->end(); it++)
    delete(*it);
  delete(enemies);
}

void EnemyList::add(int map_x, int map_y)
{
  Enemy* the_enemy = new Enemy(display, foreground);
  the_enemy->loadSprite("enemy.png", 9, 10);
  the_enemy->setMapPosition(map_x, map_y);
  enemies->push_back(the_enemy);
}

void EnemyList::draw(int x, int y)
{
  for(std::vector<Enemy*>::iterator it = enemies->begin(); it < enemies->end(); it++)
    (*it)->draw(x,y);
}

void EnemyList::update()
{
  Box playerbbox = player->getBbox();
  for(std::vector<Enemy*>::iterator it = enemies->begin(); it < enemies->end(); it++)
  {
    switch((*it)->update())
    {
      case 0: // normal update
        if(playerbbox.collision((*it)->getBbox()))
        {
          if(player->hit() < 0)
            (*it)->hit();
        }
        break;
      case 1: // dead, but not despawned yet
        break;
      case -1: // dead, and wants to be deleted
        delete(*it);
        enemies->erase(it);
        break;
      default:
        break;
    }
  }
}
