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
  float texWidth = (float)sprite.texture->width();
  float texHeight = (float)sprite.texture->height();

  float destWidth = texWidth * transform.scale.x;
  float destHeight = texHeight * transform.scale.y;

  rl::DrawTexturePro(sprite.texture->handle(),
                     (rl::Rectangle){0, 0, texWidth, texHeight},
                     (rl::Rectangle){transform.position.x, transform.position.y,
                                     destWidth, destHeight},
                     (rl::Vector2){destWidth * 0.5f, destHeight * 0.5f},
                     transform.rotation, sprite.tint);
}

void Renderer::drawCircle(Vector2 position, float radius) {
  rl::DrawCircle(position.x, position.y, radius, rl::MAROON);
}
