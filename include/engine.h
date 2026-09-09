#ifndef ENGINE_H__
#define ENGINE_H__

#include "input.h"
#include "timer.h"
#include "renderer.h"
#include "scene.h"
#include "assetmanager.h"
#include "movementsystem.h"
#include "gamecamera.h"

class Engine {
private:
  Timer m_timer;
  Input m_input;
  Renderer m_renderer;
  Scene m_scene;
  AssetManager m_assets;
  MovementSystem m_movementSystem;
  GameCamera m_camera;

  EntityId m_player = INVALID_ENTITY;

  int m_width;
  int m_height;

  Vector2 m_screenCenter;

private:
  void update(float dt);
  void render();

public:
  Engine(int width, int height, const char *title, int fps);

  void run();
};

#endif // ENGINE_H__