#include <Eigen/Eigen>
#include <iostream>

using namespace std;
using namespace Eigen;

int main(int argc, char** argv)
{
  VectorXf foo(5);
  foo << 7, 3, 0, 1, 2;
  cout << foo.transpose() << endl;
  cout << (foo.array() >= 0).transpose() << endl;

  bool allpos = (foo.array() >= 0).all();
  bool allneg = (foo.array() <= 0).all();
  cout << "allpos: " << allpos << endl;
  cout << "allneg: " << allneg << endl;
  
  return 0;
}
