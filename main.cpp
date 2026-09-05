#include <iostream>

#include "engine.h"

int main() {
  Engine engine(550, 200, "Only window!", 60);

  engine.run();

  return 0;
}