#include <boost/filesystem.hpp>

namespace boost {
  namespace filesystem {
    // Return path when appended to "from" will resolve to same as "to".
    boost::filesystem::path make_relative(boost::filesystem::path from, boost::filesystem::path to);
  }
}
