#include <concepts>
#include <compare>
#include <string>

#include <forward_list>
#include <list>
#include <vector>
#include <iostream>

using namespace std;

/*
* In C++20, you can use an unconstrained placeholder (auto) or 
* a constrained placeholder (concept) in a function declaration and this 
* function declaration automatically becomes a function template.
*/

template<typename T>
requires std::integral<T>
T gcd(T a, T b) {
  if( b == 0 ) return a;
  else return gcd(b, a % b);
}

template<typename T>
T gcd1(T a, T b) requires std::integral<T> {
  if( b == 0 ) return a;
  else return gcd1(b, a % b);
}

template<std::integral T>
T gcd2(T a, T b) {
  if( b == 0 ) return a;
  else return gcd2(b, a % b);
}

std::integral auto gcd3(std::integral auto a, std::integral auto b) {
  if( b == 0 ) return a;
  else return gcd3(b, a % b);
}

auto gcd4(auto a, auto b){
  if( b == 0 ) return a;
  return gcd4(b, a % b);
}


template<typename T, typename T2>
auto add(T first, T second)
{
  return first + second;
}

auto add(auto f, auto s)
{
  return f + s;
}

template<typename std::integral T, std::integral T2>
std::integral auto sub(T fir, T2 sec)
{
  return fir - sec;
}

std::integral auto sub(std::integral auto fir, std::integral auto sec)
{
  return fir - sec;
}

int main()
{
  std::cout << '\n';
  std::cout << "gcd(100, 10)= " << gcd(100, 10) << '\n';
  std::cout << "gcd1(100, 10)= " << gcd1(100, 10) << '\n';
  std::cout << "gcd2(100, 10)= " << gcd2(100, 10) << '\n';
  std::cout << "gcd3(100, 10)= " << gcd3(100, 10) << '\n';
  std::cout << "gcd4(100, 10)= " << gcd4(100, 10) << '\n';
  std::cout << '\n';
  return 0;
}
