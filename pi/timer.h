#include <chrono>
#include <ostream>

class Timer {
public:
  Timer();
  void stop();
  std::chrono::milliseconds check();

private:
  typedef std::chrono::system_clock clock;
  typedef std::chrono::time_point<clock> time_point;
  time_point start, end;
  bool stopped;
};

