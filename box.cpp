#include "box.hpp"

Box::Box(int x1, int x2, int y1, int y2)
{
  this->x1 = x1;
  this->x2 = x2;
  this->y1 = y1;
  this->y2 = y2;
}

Box::~Box() {}

bool Box::collision(Box b)
{
  return (b.x1 >= x1 && b.x1 <= x2 && b.y1 >= y1 && b.y1 <= y2)
        || (b.x2 >= x1 && b.x2 <= x2 && b.y1 >= y1 && b.y1 <= y2)
        || (b.x1 >= x1 && b.x1 <= x2 && b.y2 >= y1 && b.y2 <= y2)
        || (b.x2 >= x1 && b.x2 <= x2 && b.y2 >= y1 && b.y2 <= y2);
}
