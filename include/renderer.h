#ifndef RENDERER_H__
#define RENDERER_H__

#include "gamecamera.h"
#include "sprite.h"
#include "transform.h"
#include "vector2.h"


class Renderer {
public:
  void initializeWindow(int windowWidth, int windowHeight,
                        const char *windowTitle, int targetFPS);

  bool windowShouldClose();
  void closeWindow();

  void beginFrame();
  void endFrame();

  void drawRectangle(Transform transform);
  void drawSprite(Transform transform, Sprite sprite);
  void drawCircle(Vector2 position, float radius);

  void begin2DMode(GameCamera camera, Vector2 screenCenter);
  void end2DMode();
};

#endif // RENDERER_H__