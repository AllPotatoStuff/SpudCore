#include "scene.h"

#include <algorithm>

Entity Scene::createEntity() {
  Entity newEntity(m_nextEntityId, this);
  m_entities.push_back(m_nextEntityId);
  m_nextEntityId++;
  return newEntity;
}

void Scene::destroyEntity(EntityId id) {
  auto it = std::find(m_entities.begin(), m_entities.end(), id);
  if (it == m_entities.end()) {
    return;
  }

  m_entities.erase(it);
}
