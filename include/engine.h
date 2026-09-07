#ifndef ENGINE_H__
#define ENGINE_H__

#include "input.h"
#include "timer.h"
#include "renderer.h"

// Temporary for debug and test use
#include "square.h"

class Engine {
private:
  Timer m_timer;
  Input m_input;
  Renderer m_renderer;


  int m_width;
  int m_height;

  Square m_square;

private:
  void update(float dt);
  void render();

public:
  Engine(int width, int height, const char *title, int fps);

  void run();
};

#endif // ENGINE_H__