#ifndef SQUARE_H__
#define SQUARE_H__

#include "vector2.h"

class Square {
public:
  Vector2 position;
  Vector2 size;

public:
  Square(int width = 30, int height = 30, int posX = 30, int posY = 30);
};

#endif // SQUARE_H__