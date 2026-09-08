#ifndef SCENE_H__
#define SCENE_H__

#include "componentstorage.h"
#include "define.h"
#include "entity.h"
#include "renderer.h"
#include <any>
#include <typeindex>
#include <unordered_map>

class Scene {
private:
  EntityId m_nextEntityId = 0;
  std::vector<EntityId> m_entities;
  std::unordered_map<std::type_index, std::any> m_storages;

public:
  Entity createEntity();
  void destroyEntity(EntityId id);

  template <typename T> T &addComponent(EntityId id, T component) {
    return getStorage<T>().insert(id, std::move(component));
  }

  template <typename T> T &getComponent(EntityId id) {
    return getStorage<T>().get(id);
  }

  template <typename T> bool hasComponent(EntityId id) const {
    auto it = m_storages.find(std::type_index(typeid(T)));
    if (it == m_storages.end()) {
      return false;
    }
    auto *storage = std::any_cast<ComponentStorage<T>>(&it->second);
    return storage && storage->has(id);
  }

  template <typename T> void removeComponent(EntityId id) {
    getStorage<T>().remove(id);
  }

  template <typename T> ComponentStorage<T> &getStorage() {
    auto type = std::type_index(typeid(T));
    auto it = m_storages.find(type);
    if (it == m_storages.end()) {
      m_storages[type] = ComponentStorage<T>{};
    }
    return *std::any_cast<ComponentStorage<T>>(&m_storages[type]);
  }

  const std::vector<EntityId> &entities() const { return m_entities; }
};

#include "entity.inl"

#endif // SCENE_H__