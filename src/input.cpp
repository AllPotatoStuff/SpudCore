#include "input.h"

#include "define.h"

Input::Input() {}

bool Input::isKeyDown(int key) const { return rl::IsKeyDown(key); }

bool Input::isKeyPressed(int key) const { return rl::IsKeyPressed(key); }

bool Input::isKeyReleased(int key) const { return rl::IsKeyReleased(key); }
