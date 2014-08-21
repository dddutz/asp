#ifndef PROFILE_H
#define PROFILE_H

#include <timer/timer.h>

HighResTimer& unique_timer(const char* s);
void print_timers();
void reset_timers();

struct ScopedHighResTimer {
  HighResTimer& t;
  inline ScopedHighResTimer(HighResTimer& t): t(t) { t.start();  }
  inline ~ScopedHighResTimer() { t.stop(); }
};

static HighResTimer& global_cpu_timer = unique_timer("Entire test");
static ScopedHighResTimer global_timer( global_cpu_timer );

const HighResTimer &GetTimer(const std::string& timer);

#define PROFILE_FUNC \
  static HighResTimer& __timer = unique_timer(__FUNCTION__); \
  ScopedHighResTimer __scoped_timer(__timer);

#define PROFILE_BLOCK(name) \
  static HighResTimer& __timer = unique_timer(name); \
  ScopedHighResTimer __scoped_timer(__timer);

inline clock_t& TOC_CLOCK() {
  static clock_t cur = clock();
  return cur;
}
#define TOC(X) fprintf(stderr, X":%.2f seconds\n", float(clock()-TOC_CLOCK()) / CLOCKS_PER_SEC ); TOC_CLOCK() = clock();

#endif  // PROFILE_H
