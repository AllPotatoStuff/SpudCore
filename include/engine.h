#ifndef ENGINE_H__
#define ENGINE_H__

#include "input.h"
#include "timer.h"
#include "renderer.h"

class Engine {
private:
  Timer m_timer;
  Input m_input;
  Renderer m_renderer;

  int m_width;
  int m_height;

private:
  void update(float dt);
  void render();

public:
  Engine(int width, int height, const char *title, int fps);

  void run();
};

#endif // ENGINE_H__