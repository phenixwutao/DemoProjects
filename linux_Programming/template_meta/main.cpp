#include <iostream>

#include "wrapper.h"

using namespace std;

int main()
{
  ext::wrapper<int> a{ 10 };
  ext::f();
  ext::g();
  std::cout << "main " << a.data << '\n';
  return 0;
}
