#include "engine.h"

#include "define.h"
#include <format>
#include <iostream>
#include <string>

void Engine::update(float dt) {
  if (m_input.isKeyDown(rl::KEY_W)) {
    m_square.posY -= 200.0f * dt;
  }
  if (m_input.isKeyDown(rl::KEY_S)) {
    m_square.posY += 200.0f * dt;
  }
  if (m_input.isKeyDown(rl::KEY_A)) {
    m_square.posX -= 200.0f * dt;
  }
  if (m_input.isKeyDown(rl::KEY_D)) {
    m_square.posX += 200.0f * dt;
  }
}

void Engine::render() {
  rl::BeginDrawing();

  rl::ClearBackground(rl::RAYWHITE);

  std::string elapsedTime =
      std::format("Elapsed Time : {:.2f}", m_timer.elapsedTime());
  rl::DrawText(elapsedTime.c_str(), 10, 10, 20, rl::DARKGRAY);

  rl::DrawRectangle(m_square.posX, m_square.posY, m_square.width,
                    m_square.height, rl::MAROON);

  rl::EndDrawing();
}

Engine::Engine(int width, int height, const char *title, int fps)
    : m_square(30, 30, width / 2, height / 2) {
  m_height = height;
  m_width = width;
  rl::InitWindow(width, height, title);
  rl::SetTargetFPS(fps);
}

void Engine::run() {
  while (!rl::WindowShouldClose()) {

    m_timer.update();

    update(m_timer.deltaTime());

    render();
  }

  rl::CloseWindow();
}
