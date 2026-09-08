#ifndef MOVEMENTSYSTEM_H__
#define MOVEMENTSYSTEM_H__

#include "scene.h"

class MovementSystem {
public:
  void update(Scene &scene, float dt);
};

#endif // MOVEMENTSYSTEM_H__