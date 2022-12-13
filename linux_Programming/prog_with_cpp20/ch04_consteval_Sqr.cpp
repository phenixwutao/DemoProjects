#include <concepts>

#include <string>
#include <forward_list>
#include <list>
#include <vector>
#include <unordered_set>

#include <iostream>

#include <type_traits>

#include <compare>

using namespace std;

consteval int sqr(int n)
{
  return n*n;
}

int main()
{
  cout <<std::boolalpha;
  cout << sqr(5) << endl;
  const int a = 5;
  cout << sqr(a) << endl;
  
  int b = 5;
  // cout << sqr(b) << endl; // compile error: 'int b' is not const
  return 0;
}
