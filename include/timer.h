#ifndef TIME_H__
#define TIME_H__

#include <chrono>

class Timer {
private:
  using Clock = std::chrono::steady_clock;
  using TimePoint = std::chrono::time_point<Clock>;
  using Duration = std::chrono::duration<float>;

  TimePoint m_startTime;
  TimePoint m_lastFrameTime;

  float m_deltaTime = 0.0f;
  float m_elapsedTime = 0.0f;

public:
  Timer();

  void reset();
  void update();

  float deltaTime() const;
  float elapsedTime() const;
};

#endif // TIME_H__