#ifndef COMPONENTSTORAGE_H__
#define COMPONENTSTORAGE_H__

#include "define.h"
#include <cassert>
#include <unordered_map>
#include <vector>

template <typename T> class ComponentStorage {
private:
  std::vector<T> m_components;
  std::vector<EntityId> m_indexToEntity;
  std::unordered_map<EntityId, size_t> m_entityToIndex;

public:
  T &insert(EntityId entity, T component) {
    assert(m_entityToIndex.find(entity) == m_entityToIndex.end() &&
           "Component already exists for this entity");

    size_t newIndex = m_components.size();
    m_entityToIndex[entity] = newIndex;
    m_indexToEntity.push_back(entity);
    m_components.push_back(std::move(component));

    return m_components[newIndex];
  }

  void remove(EntityId entity) {
    auto it = m_entityToIndex.find(entity);
    if (it == m_entityToIndex.end()) {
      return;
    }

    size_t indexToRemove = it->second;
    size_t lastIndex = m_components.size() - 1;
    EntityId lastEntity = m_indexToEntity[lastIndex];

    m_components[indexToRemove] = std::move(m_components[lastIndex]);
    m_indexToEntity[indexToRemove] = lastEntity;
    m_entityToIndex[lastEntity] = indexToRemove;

    m_components.pop_back();
    m_indexToEntity.pop_back();
    m_entityToIndex.erase(entity);
  }

  bool has(EntityId entity) const {
    return m_entityToIndex.find(entity) != m_entityToIndex.end();
  }

  T &get(EntityId entity) {
    assert(has(entity) && "No Compoenent for this entity");
    return m_components[m_entityToIndex.at(entity)];
  }

  std::vector<T> &all() { return m_components; }
  const std::vector<EntityId> &entites() const { return m_indexToEntity; }
};

#endif // COMPONENTSTORAGE_H__