#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>

#include <ros/assert.h>
#include <timer/profile.h>
#include <timer/timer.h>

using std::map;
using std::pair;
using std::sort;
using std::string;
using std::vector;

typedef map<string, HighResTimer> TimerTable;

TimerTable& timers() {
  static TimerTable it;
  return it;
}

const HighResTimer &GetTimer(const string& timer) {
  return timers()[timer];
}

HighResTimer& unique_timer(const char* s) {
  return timers()[s];
}

void reset_timers() {
  unique_timer("Entire test").stop();
  for (TimerTable::iterator it=timers().begin(); it!=timers().end(); it++) {
    it->second.reset();
  }
  unique_timer("Entire test").start();
}

void print_timers() {
  unique_timer("Entire test").stop();
  ROS_INFO("%30s %6s %8s %8s %8s", "FUNCTION NAME", "COUNT", "SUM (s)",
           "AVG (ms)", "FPS");
  typedef pair<HighResTimer, string> Name;
  typedef pair<string, HighResTimer> RName;

  // sort and print out in order of time spent
  vector<Name> sort_timers;
  for (TimerTable::iterator it=timers().begin(); it!=timers().end(); it++) {
    const RName &n = *it;
    sort_timers.push_back( make_pair(n.second, n.first) );
  }
  sort(sort_timers.begin(), sort_timers.end());

  for(size_t i = 0; i < sort_timers.size(); i++) {
    const Name &n = sort_timers[i];
    ROS_INFO("%30s %6d %8.2f %10.5f %9.2f", n.second.c_str(),
             n.first.getCallCount(), n.first.getSeconds(),
             n.first.getMilliseconds() / n.first.getCallCount(),
             n.first.getCallCount() / n.first.getSeconds());
  }
  unique_timer("Entire test").start();
}

