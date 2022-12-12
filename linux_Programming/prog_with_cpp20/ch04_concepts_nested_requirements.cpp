#include <concepts>
#include <compare>
#include <string>

#include <forward_list>
#include <list>
#include <vector>
#include <iostream>

#include <type_traits>

using namespace std;

template<typename T>
concept Integral = std::is_integral<T>::value;

template<typename T>
concept SignedIntegral = Integral<T> && std::is_signed<T>::value;

// demo nested requirement:
template<typename T>
concept UnsignedIntegral = Integral<T> &&
requires (T) {
  requires !SignedIntegral<T>;
};

int main()
{
  UnsignedIntegral auto n = 5u;

  // UnsignedIntegral auto n = 5; // compile error: 5 is signed
  return 0;
}
