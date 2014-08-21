#include <bag_of_tricks/relative_path.h>
#include <boost/program_options.hpp>

using namespace std;
namespace bfs = boost::filesystem;

int main(int argc, char** argv)
{
  namespace bpo = boost::program_options;
  bpo::options_description opts_desc("Allowed options");
  bpo::positional_options_description p;

  string path0;
  string path1;
  opts_desc.add_options()
    ("help,h", "produce help message")
    ("path0", bpo::value(&path0)->required(), "")
    ("path1", bpo::value(&path1)->required(), "")
    ;

  p.add("path0", 1);
  p.add("path1", 1);

  bpo::variables_map opts;
  bpo::store(bpo::command_line_parser(argc, argv).options(opts_desc).positional(p).run(), opts);
  bool badargs = false;
  try { bpo::notify(opts); }
  catch(...) { badargs = true; }
  if(opts.count("help") || badargs) {
    cout << "Usage: " << argv[0] << " [OPTS] PATH0 PATH1 " << endl;
    cout << endl;
    cout << opts_desc << endl;
    return 1;
  }

  cout << "path0: " << path0 << endl;
  cout << "path1: " << path1 << endl;

  cout << "Absolute path0: " << bfs::absolute(path0) << endl;
  cout << "Absolute path1: " << bfs::absolute(path1) << endl;

  cout << "Canonical path0: " << bfs::canonical(path0) << endl;
  cout << "Canonical path1: " << bfs::canonical(path1) << endl;

  cout << "path0 relative to path1: " << bfs::make_relative(path1, path0) << endl;
  cout << "path1 relative to path0: " << bfs::make_relative(path0, path1) << endl;
  
  return 0;
}
