#include <iostream>
import math_template;

using std::cout;
using std::endl;

int main()
{
  auto [value, name] = mathlib2::sum(10,20);
  cout << value << ", " << name << endl;

  auto [value1, name1] = mathlib2::sum(1.1,2.2);
  cout << value1 << ", " << name1 << endl;

  auto [value2, name2] = mathlib2::sum(1.1,false);
  cout << value2 << ", " << name2 << endl;

  return 0;
}