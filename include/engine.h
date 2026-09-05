#ifndef ENGINE_H__
#define ENGINE_H__

#include "timer.h"

class Engine {
private:
  Timer m_timer;

private:
  void update(float dt);
  void render();

public:
  Engine(int width, int heigth, const char *title);

  void run();
};

#endif // ENGINE_H__