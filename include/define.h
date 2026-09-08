#ifndef DEFINE_H__
#define DEFINE_H__

#pragma once
#include <cstdint>

namespace rl {
#include <raylib.h>
} // namespace rl

enum Keys {
  D = 68,
  A = 65,
  W = 87,
  S = 83,
};

using EntityId = uint32_t;
constexpr EntityId INVALID_ENTITY = 0;

#endif // DEFINE_H__