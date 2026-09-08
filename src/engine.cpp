#include "engine.h"

#include "define.h"
#include <format>
#include <iostream>
#include <string>

void Engine::update(float dt) {
  // if (m_input.isKeyDown(Keys::A)) {
  //   m_square.transform.position.x -= 200.0f * dt;
  // }
  // if (m_input.isKeyDown(Keys::D)) {
  //   m_square.transform.position.x += 200.0f * dt;
  // }
  // if (m_input.isKeyDown(Keys::W)) {
  //   m_square.transform.position.y -= 200.0f * dt;
  // }
  // if (m_input.isKeyDown(Keys::S)) {
  //   m_square.transform.position.y += 200.0f * dt;
  // }
}

void Engine::render() {
  m_renderer.beginFrame();

  m_renderer.endFrame();
}

Engine::Engine(int width, int height, const char *title, int fps)
    : m_height(height), m_width(width) {
  m_renderer.initializeWindow(width, height, title, fps);
}

void Engine::run() {
  while (!m_renderer.windowShouldClose()) {

    m_timer.update();

    update(m_timer.deltaTime());

    render();
  }

  m_renderer.closeWindow();
}
