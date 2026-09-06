#include "timer.h"

Timer::Timer() { reset(); }

void Timer::reset() {
  m_startTime = Clock::now();
  m_lastFrameTime = m_startTime;
  m_deltaTime = 0.0f;
  m_elapsedTime = 0.0f;
}

void Timer::update() {
  TimePoint currentFrameTime = Clock::now();

  m_deltaTime =
      std::chrono::duration_cast<Duration>(currentFrameTime - m_lastFrameTime)
          .count();

  m_elapsedTime =
      std::chrono::duration_cast<Duration>(currentFrameTime - m_startTime)
          .count();

  m_lastFrameTime = currentFrameTime;
}

float Timer::deltaTime() const { return m_deltaTime; }

float Timer::elapsedTime() const { return m_elapsedTime; }