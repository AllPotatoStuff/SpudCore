#ifndef GAMECAMERA_H__
#define GAMECAMERA_H__

#include "define.h"
#include "vector2.h"

struct GameCamera {
  Vector2 position{0, 0};
  float zoom = 1.0f;
  float rotation = 0.0f;

  rl::Camera2D to_raylib(Vector2 screenCenter) const {
    rl::Camera2D cam{};
    cam.target = (rl::Vector2){position.x, position.y};
    cam.offset = (rl::Vector2){screenCenter.x, screenCenter.y};
    cam.zoom = zoom;
    cam.rotation = rotation;
    return cam;
  }
};

#endif // GAMECAMERA_H__