#ifndef TEXTURE_H__
#define TEXTURE_H__

#include "define.h"
#include <string>

class Texture {
private:
  rl::Texture2D m_texture;

public:
  explicit Texture(const std::string &path);
  ~Texture();

  rl::Texture2D handle() { return m_texture; }
  int width() const { return m_texture.width; }
  int height() const { return m_texture.height; }
};

#endif // TEXTURE_H__