#include "engine.h"

#include "define.h"
#include "velocity.h"
#include <format>
#include <iostream>
#include <string>

void Engine::update(float dt) {
  auto &velocity = m_scene.getComponent<Velocity>(m_player);
  velocity.value = {0.0f, 0.0f};

  const float speed = 200.0f;
  if (m_input.isKeyDown(Keys::A))
    velocity.value.x -= speed;
  if (m_input.isKeyDown(Keys::D))
    velocity.value.x += speed;
  if (m_input.isKeyDown(Keys::W))
    velocity.value.y -= speed;
  if (m_input.isKeyDown(Keys::S))
    velocity.value.y += speed;

  m_movementSystem.update(m_scene, dt);
}

void Engine::render() {
  m_renderer.beginFrame();

  for (EntityId id : m_scene.entities()) {
    if (m_scene.hasComponent<Transform>(id) &&
        m_scene.hasComponent<Sprite>(id)) {
      m_renderer.drawSprite(m_scene.getComponent<Transform>(id),
                            m_scene.getComponent<Sprite>(id));
    }
  }

  m_renderer.endFrame();
}

Engine::Engine(int width, int height, const char *title, int fps)
    : m_height(height), m_width(width) {
  m_renderer.initializeWindow(width, height, title, fps);

  Entity player = m_scene.createEntity();
  auto texture = m_assets.load_textures("assets/player.png");
  player.add<Sprite>(Sprite{texture});
  player.add<Transform>(
      Transform{Vector2{100.0f, 100.0f}, Vector2{0.25f, 0.25f}});
  player.add<Velocity>(Velocity{});
  m_player = player.id();
}

void Engine::run() {
  while (!m_renderer.windowShouldClose()) {
    m_timer.update();
    update(m_timer.deltaTime());
    render();
  }

  m_renderer.closeWindow();
}
