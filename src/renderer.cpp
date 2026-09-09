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

void Renderer::drawRectangle(Transform transform) {
  rl::DrawRectangle(transform.position.x, transform.position.y,
                    transform.scale.x, transform.scale.y, rl::MAROON);
}

void Renderer::drawSprite(Transform transform, Sprite sprite) {
  rl::DrawTexturePro(
      sprite.texture.get()->handle(),
      (rl::Rectangle){
          0,
          0,
          (float)sprite.texture.get()->width(),
          (float)sprite.texture.get()->height(),
      },
      (rl::Rectangle){
          transform.position.x,
          transform.position.y,
          (float)sprite.texture.get()->width(),
          (float)sprite.texture.get()->height(),
      },
      (rl::Vector2){sprite.texture.get()->width() * transform.scale.x,
                    sprite.texture.get()->height() * transform.scale.y},
      transform.rotation, sprite.tint);
}

void Renderer::drawCircle(Vector2 position, float radius) {
  rl::DrawCircle(position.x, position.y, radius, rl::MAROON);
}
