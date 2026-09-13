#ifndef ASSETMANAGER_H__
#define ASSETMANAGER_H__

#include "texture.h"
#include <memory>
#include <string>
#include <unordered_map>

class AssetManager {
private:
  std::unordered_map<std::string, std::shared_ptr<Texture>> m_textures;

public:
  std::shared_ptr<Texture> load_textures(const std::string &path) {
    auto it = m_textures.find(path);
    if (it != m_textures.end()) {
      return it->second;
    }

    auto texture = std::make_shared<Texture>(path);
    m_textures[path] = texture;
    return texture;
  }
};

#endif // ASSETMANAGER_H__