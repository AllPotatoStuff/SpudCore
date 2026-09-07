#ifndef TRANSFORM_H__
#define TRANSFORM_H__

#include "vector2.h"

struct Transform {
  Vector2 position{0, 0};
  Vector2 scale{1, 1};
  float rotation = 0.0f;
};

#endif // TRANSFORM_H__