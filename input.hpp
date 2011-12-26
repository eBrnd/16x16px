#ifndef INPUT
#define INPUT

#include <SDL/SDL.h>

class Input
{
  private:

  public:
    Input();
    ~Input();
    void read();

    bool escape;
};

#endif
