#include "wrapper.h"
#include <iostream>

using namespace std;

namespace ext
{
  template struct wrapper<int>; // [2] explicit instantiation definition

  void f()
  {
    ext::wrapper<int> a{ 42 };
    std::cout << "f() " << a.data << '\n';
  }
}
