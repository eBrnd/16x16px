#ifndef BOX
#define BOX

class Box
{
  protected:
    int x1, x2, y1, y2;
  public:
    Box(int x1, int x2, int y1, int y2);
    ~Box();
    bool collision(Box b);
};

#endif
