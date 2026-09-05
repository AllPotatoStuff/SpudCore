#include "engine.h"

#include "define.h"
#include <format>
#include <string>
#include <iostream>

void Engine::update(float dt) {}

void Engine::render() {
  rl::BeginDrawing();

  rl::ClearBackground(rl::RAYWHITE);

  std::string elapsedTime =
      std::format("Elapsed Time : {:.2f}", m_timer.elapsedTime());
  rl::DrawText(elapsedTime.c_str(), 10, 10, 20, rl::DARKGRAY);

  rl::EndDrawing();
}

Engine::Engine(int width, int heigth, const char *title) {
  rl::InitWindow(width, heigth, title);
  rl::SetTargetFPS(60);
}

void Engine::run() {
  while (!rl::WindowShouldClose()) {

    m_timer.update();

    update(m_timer.deltaTime());

    render();
  }

  rl::CloseWindow();
}
