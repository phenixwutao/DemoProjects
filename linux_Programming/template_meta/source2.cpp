#include "wrapper.h"
#include <iostream>

using namespace std;

namespace ext
{
  void g()
  {
    wrapper<int> a{ 100 };
    std::cout << "g() " << a.data << '\n';
  }
}