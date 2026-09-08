
template <typename T> T &Entity::add(T component) {
  return m_scene->addComponent<T>(m_id, std::move(component));
}

template <typename T> T &Entity::get() {
  return m_scene->getComponent<T>(m_id);
}

template <typename T> bool Entity::has() const {
  return m_scene->hasComponent<T>(m_id);
}

template <typename T> void Entity::remove() {
  m_scene->removeComponent<T>(m_id);
}