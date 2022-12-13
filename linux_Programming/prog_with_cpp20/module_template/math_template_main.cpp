#include <iostream>
import math_template;

using std::cout;
using std::endl;

int main()
{
  cout << mathlib::sum(2,3) << endl;
  cout << mathlib::sum(1.1,3) << endl;
  cout << mathlib::sum(12.45,false) << endl;

  // cout << mathlib::mod(10,3) << endl; // compile error
  // cout << mathlib::cube(3.3) << endl; // compile error
  cout << cube2(3.1) << endl;
  return 0;
}