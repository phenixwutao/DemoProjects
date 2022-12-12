#include <concepts>
#include <compare>
#include <string>

#include <forward_list>
#include <list>
#include <vector>
#include <unordered_set>
#include <iostream>

#include <type_traits>

using namespace std;

template<typename T>
concept Equal =
requires (T a, T b)
{
  { a == b } -> std::convertible_to<bool>;
  { a != b } -> std::convertible_to<bool>;
};

template<typename T>
concept Ordering = Equal<T> &&
requires (T a, T b)
{
  { a <= b } -> std::convertible_to<bool>;
  { a <  b } -> std::convertible_to<bool>;
  { a >  b } -> std::convertible_to<bool>;
  { a >= b } -> std::convertible_to<bool>;
};


template<Equal T>
bool areEqual(const T& a, const T& b)
{
  return a == b;
}

template<Ordering T>
T getSmaller(const T& a, const T& b)
{
  return (a < b) ? a : b;  
}

int main()
{
  std::cout << std::boolalpha;

  cout << "areEqual(1,5) " << areEqual(1,5) << endl;

  cout << "getSmaller(1,5) " << getSmaller(1,5) << endl;

  std::unordered_set<int> firSet {1,2,3,4,5};

  std::unordered_set<int> secSet {5,4,3,2,1};

  cout << "areEqual(firSet, secSet) " << areEqual(firSet, secSet) << endl;

  return 0;
}
