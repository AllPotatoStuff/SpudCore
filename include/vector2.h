#ifndef VECTOR2_H__
#define VECTOR2_H__

#include <cmath>
#include <iostream>

struct Vector2 {
  float x = 0.0f;
  float y = 0.0f;

  Vector2() : x(0.0f), y(0.0f) {}
  Vector2(float x, float y) : x(x), y(y) {}

  constexpr Vector2 &operator+=(const Vector2 &rhs) noexcept {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }

  constexpr Vector2 &operator-=(const Vector2 &rhs) noexcept {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
  }

  Vector2 operator+(const Vector2 &other) const {
    return Vector2(x + other.x, y + other.y);
  }

  Vector2 operator*(float scalar) const {
    return Vector2(x * scalar, y * scalar);
  }

  [[nodiscard]] float dot(const Vector2 &rhs) const noexcept {
    return (x * rhs.x) + (y * rhs.y);
  }

  [[nodiscard]] constexpr float length() const noexcept {
    return std::hypot(x, y);
  }
};

#endif // VECTOR2_H__