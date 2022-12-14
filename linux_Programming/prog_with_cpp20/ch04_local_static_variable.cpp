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


int square(int n)
{
  return n*n;
}

int staticA()
{
  static auto value = square(5);
  return value;
}
