#include "renderer.h"

#include "define.h"

void Renderer::initializeWindow(int windowWidth, int windowHeight,
                                const char *windowTitle, int targetFPS) {
  rl::InitWindow(windowWidth, windowHeight, windowTitle);
  rl::SetTargetFPS(targetFPS);
}

bool Renderer::windowShouldClose() { return rl::WindowShouldClose(); }

void Renderer::closeWindow() { rl::CloseWindow(); }

void Renderer::beginFrame() {
  rl::BeginDrawing();
  rl::ClearBackground(rl::RAYWHITE);
}

void Renderer::endFrame() { rl::EndDrawing(); }

void Renderer::drawRectangle(Vector2 &position, Vector2 &size) {
  rl::DrawRectangle(position.x, position.y, size.x, size.y, rl::MAROON);
}

void Renderer::drawCircle(Vector2 &position, float radius) {
  rl::DrawCircle(position.x, position.y, radius, rl::MAROON);
}
