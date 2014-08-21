#include <agent/agent.h>

#include <boost/bind.hpp>
#include <boost/foreach.hpp>
#include <boost/thread.hpp>
#include <agent/lockable.h>

void Agent::quit()
{
  scopeLockWrite; quitting_ = true;}

void Agent::stop()
{
  lockWrite();
  quitting_ = true;
  unlockWrite();
  thread_->join();
}

bool Agent::running()
{
  scopeLockRead;
  return running_;
}

void Agent::run()
{
  running_ = true;
  _run();
  running_ = false;
}

ThreadPtr Agent::launch()
{
  thread_ = ThreadPtr(new boost::thread(boost::bind(&Agent::run, this)));
  return thread_;
}

void Agent::detach()
{
  boost::thread thread(boost::bind(&Agent::run, this));
  thread.detach();
}

