module;
#include <iostream>
#include <typeinfo>
#include <utility>

// import <iostream>;
// import <typeinfo>;
// import <utility>;

// declare a module
export module math_template;

template<typename T>
auto showType(T&& t)
{
  return typeid(std::forward<T>(t)).name();
}

export namespace mathlib2
{
  template<typename T, typename T2>
  auto sum(T a, T2 b)
  {
    auto value = a+b;
    return std::make_pair(value, showType(value));
  }
}