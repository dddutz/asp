#ifndef AGENT_H
#define AGENT_H

#include <boost/shared_ptr.hpp>
#include <agent/lockable.h>

namespace boost {
class thread;
}
typedef boost::shared_ptr<boost::thread> ThreadPtr;

//! All of this is highly experimental.
class Agent : public SharedLockable
{
public:
  Agent() : SharedLockable(), quitting_(false), running_(false) {}
  // Should this call stop()?
  virtual ~Agent() {}

  //! TODO: Get rid of this function?
  void quit();
  void stop();
  bool running();
  void run();
  virtual void _run() = 0;
  //! This should be a void function.
  ThreadPtr launch();
  ThreadPtr thread() const { return thread_; }

  //! This should maybe not exist at all.
  void detach();

protected:
  ThreadPtr thread_;
  bool quitting_;
  bool running_;
};

#endif // AGENT_H
