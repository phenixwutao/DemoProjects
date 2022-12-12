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

template<typename T>
concept UnsignedIntegral = Integral<T> && !SignedIntegral<T>;

template<typename T>
concept Arithmetic = std::is_integral<T>::value || std::is_floating_point<T>::value;

template<typename T>
concept Addable = requires (T a, T b)
{
  a + b;
};
template<Addable T>
T add2(T a, T b)
{
  return a + b;
}


void func(SignedIntegral auto integ)
{
  cout << "SignedIntegral: "<< integ << endl;
}

void func(UnsignedIntegral auto integ)
{
  cout << "UnsignedIntegral: "<< integ << endl;
}

template<typename T>
concept AlwaysTrue = true;

template<typename>
struct other;

template<>
struct other<std::vector<int>> {};

template<typename T>
concept TypeRequirement = requires {
typename T::value_type;
typename other<T>;
};


int main()
{
  func(-5);
  func(5u);

  TypeRequirement auto myvec = std::vector<int>{1,2,3};
  return 0;
}
