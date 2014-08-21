#ifndef HIGH_RES_TIMER_H
#define HIGH_RES_TIMER_H

#include <time.h>
#include <string>
#include <sstream>
#include <cstddef>
#include <iostream>

/// /brief Time units to control reporting
struct TimeUnit
{
  enum Unit {
    AUTO,
    US,
    MS,
    SEC,
    MIN,
    HR
  };
};

//! CLOCK_MONOTONIC_RAW will not be adjusted by NTP.
//! See man clock_gettime.
class HighResTimer
{
public:
  std::string description_;

  HighResTimer(const std::string& description = "HighResTimer");
  void start();
  void stop();
  void reset(const std::string& description);
  void reset();
  double getMicroseconds() const;
  double getMilliseconds() const { return getMicroseconds() / 1000.; }
  double getSeconds() const { return getMilliseconds() / 1000.; }
  double getMinutes() const { return getSeconds() / 60.; }
  double getHours() const { return getMinutes() / 60.; }
  int getCallCount() const { return call_count_; }

  std::string report() const;
  std::string report(TimeUnit::Unit unit) const;
  std::string reportMicroseconds() const;
  std::string reportMilliseconds() const;
  std::string reportSeconds() const;
  std::string reportMinutes() const;
  std::string reportHours() const;
  bool operator<(const HighResTimer& o) const;
  
private:
  double total_us_;
  timespec start_;
  timespec end_;
  bool stopped_;
  int call_count_;
};

class ScopedTimer
{
public:
  HighResTimer hrt_;
  ScopedTimer(const std::string& description = "ScopedTimer", TimeUnit::Unit unit=TimeUnit::AUTO);
  ~ScopedTimer();

private:
  TimeUnit::Unit unit_;
};

#endif // HIGH_RES_TIMER_H
