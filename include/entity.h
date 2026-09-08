#ifndef ENTITY_H__
#define ENTITY_H__

#include "define.h"

class Scene;

class Entity {
private:
  EntityId m_id;
  Scene *m_scene = nullptr;

public:
  Entity() = default;
  Entity(EntityId id, Scene *scene) : m_id(id), m_scene(scene) {};

  template <typename T> T &add(T component = T{});

  template <typename T> T &get();

  template <typename T> bool has() const;

  template <typename T> void remove();

  EntityId id() const { return m_id; }
  bool isValid() const { return m_scene != nullptr && m_id != INVALID_ENTITY; }
};

#endif // ENTITY_H__