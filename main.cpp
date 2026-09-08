#include <iostream>

#include "define.h"
#include "engine.h"
#include "entity.h"
#include "scene.h"
#include "transform.h"

void test_engine() {
  Engine engine(550, 200, "Only window!", 60);

  engine.run();
}

void test_scene() {

  Scene scene;

  Entity player = scene.createEntity();
  player.add(Transform{{100, 100}});

  Entity enemy = scene.createEntity();
  enemy.add(Transform{{300, 200}});

  Transform &t34 = scene.getComponent<Transform>(player.id());
  assert(t34.position.x == 100 && t34.position.y == 100);

  Entity a = scene.createEntity();
  a.add(Transform{{1, 1}});

  Entity b = scene.createEntity();
  b.add(Transform{{2, 2}});

  Entity c = scene.createEntity();
  c.add(Transform{{3, 3}});

  scene.destroyEntity(a.id());

  Transform &tb = scene.getComponent<Transform>(b.id());
  Transform &tc = scene.getComponent<Transform>(c.id());
  assert(tb.position.x == 2);
  assert(tc.position.x == 3);

  Transform &t = scene.getComponent<Transform>(player.id());
  t.position.x = 999;

  Transform &t2 = scene.getComponent<Transform>(player.id());
  assert(t2.position.x == 999);

  for (EntityId id : scene.entities()) {
    if (scene.hasComponent<Transform>(id)) {
      Transform &t = scene.getComponent<Transform>(id);
      std::cout << "Entity " << id << " -> (" << t.position.x << ", "
                << t.position.y << ")\n";
    }
  }
}

int main() {
  test_scene();
  return 0;
}