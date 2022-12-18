#include <utility>
#include <iostream>
#include <string>
#include <array>
#include <mutex>
#include <shared_mutex>
#include <memory>
#include <tuple>

std::shared_timed_mutex mut;

class MyClass
{
public:
  int GetA() const { return a; }
  float GetB() const { return b; }
private:
  int a;
  float b;
};

template <std::size_t I>
auto get(MyClass& c)
{
  if constexpr (I == 0) return c.GetA();
  else if constexpr (I == 1) return c.GetB();
}

// specialisations to support tuple-like interface
namespace std
{
  template <> struct tuple_size<MyClass> : std::integral_constant<size_t, 2>
  {};
  
  template <> struct tuple_element<0,MyClass>
  { using type = int; };
  
  template <> struct tuple_element<1,MyClass>
  { using type = float; };
}

template <>
auto& get<0>(const MyClass &c) { return c.GetA(); }

template <>
auto& get<1>(const MyClass &c) { return c.GetB(); }

int main()
{
  MyClass s;
  auto [id, score] = s;
  
  return 0;
}

