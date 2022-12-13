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

struct Basics
{
  int i;
  char c;
  float f;
  double d;
  auto operator<=>(const Basics&) const = default;
};

struct Arrays
{
  int ai[1];
  char ac[2];
  float af[3];
  double ad[2][2];
  auto operator<=>(const Arrays&) const = default;
};

struct Bases : Basics, Arrays
{
  auto operator<=>(const Bases&) const = default;  
};

int main()
{
  cout <<std::boolalpha ;
 constexpr Bases a = {
 { 0, 'c', 1.f, 1. }, // Basics
 { { 1 }, { 'a', 'b' }, { 1.f, 2.f, 3.f },  // Arrays
 { { 1., 2. }, { 3., 4. } } } };

 constexpr Bases b = {
 { 0, 'c', 1.f, 1. }, // Basics
 { { 1 }, { 'a', 'b' }, { 1.f, 2.f, 3.f },  // Arrays
 { { 1., 2. }, { 3., 4. } } } };  


  static_assert(a == b,     "error");
  static_assert(!(a != b),  "error");
  static_assert(!(a < b),   "error");
  static_assert(a <= b,     "error");
  static_assert(!(a > b),   "error");
  static_assert(a >= b,     "error");

  return 0;
}
