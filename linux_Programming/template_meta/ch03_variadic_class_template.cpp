#include <stdarg.h>
#include <iostream>
#include <array>
#include <functional>

using namespace std;

template <typename T, typename... Ts>
struct tuple
{
  tuple(T const& t, Ts const &... ts) : value(t), rest(ts...)
  {
  }

  constexpr int size() const { return 1 + rest.size(); }

  T value;

  tuple<Ts...> rest;
};


template <typename T>
struct tuple<T>
{
  tuple(const T& t) : value(t)
  {
  }

  constexpr int size() const { return 1; }

  T value;
};

int main ()
{

  std::cout << '\n';
  return 0;
}