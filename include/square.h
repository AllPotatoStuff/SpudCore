#ifndef SQUARE_H__
#define SQUARE_H__

#include "transform.h"

class Square {
public:
  Transform transform;


public:
  Square(int posX = 30, int posY = 30);
};

#endif // SQUARE_H__