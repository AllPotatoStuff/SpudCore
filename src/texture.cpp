#include "texture.h"

Texture::Texture(const std::string &path) {
  m_texture = rl::LoadTexture(path.c_str());
}

Texture::~Texture() { rl::UnloadTexture(m_texture); }
