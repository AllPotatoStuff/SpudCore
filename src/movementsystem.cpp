#include "movementsystem.h"

#include "define.h"
#include "transform.h"
#include "velocity.h"


void MovementSystem::update(Scene &scene, float dt) {
  auto &velocities = scene.getStorage<Velocity>();

  for (EntityId id : velocities.entites()) {
    if (!scene.hasComponent<Transform>(id)) {
      continue;
    }

    auto &transform = scene.getComponent<Transform>(id);
    auto &velocity = scene.getComponent<Velocity>(id);

    transform.position.x += velocity.value.x * dt;
    transform.position.y += velocity.value.y * dt;
  }
}
