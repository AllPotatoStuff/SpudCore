#ifndef SQUARE_H__
#define SQUARE_H__

class Square {
public:
  int width;
  int height;
  int posX;
  int posY;

public:
  Square(int width = 30, int height = 30, int posX = 30, int posY = 30);
};

#endif // SQUARE_H__