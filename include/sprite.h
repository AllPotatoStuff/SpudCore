#ifndef SPRITE_H__
#define SPRITE_H__

#include <memory>
#include "texture.h"
#include "define.h"

struct Sprite{
    std::shared_ptr<Texture> texture;
    rl::Color tint = rl::WHITE;
};

#endif // SPRITE_H__