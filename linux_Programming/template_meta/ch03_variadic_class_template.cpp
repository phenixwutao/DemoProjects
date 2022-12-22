#include <stdarg.h>
#include <iostream>
#include <array>
#include <vector>
#include <functional>

//using namespace std;

template <typename T, typename... Ts>
struct mytuple
{
  mytuple(T const& t, Ts const &... ts) : value(t), rest(ts...)
  {
  }

  constexpr int size() const { return 1 + rest.size(); }

  T value;

  mytuple<Ts...> rest;
};


template <typename T>
struct mytuple<T>
{
  mytuple(const T& t) : value(t)
  {
  }

  constexpr int size() const { return 1; }

  T value;
};

template<typename T>
T mysum(T a)
{
  return a;
}

template<typename T, typename... Args>
T mysum(T a, Args...args)
{
  return a + sum(args...);
}

// combined into one implementation by using fold expression
template<typename... T>
int mysum2(T... args)
{
  std::cout << "mysum2: " << __PRETTY_FUNCTION__ << "\n";
  //return (... + args);
  return (args + ...);
}


template<typename...T>
int sum_from_zero(T... args)
{
  return (0 + ... + args);
}


template <typename... T>
void printleft(T... args)
{
  (..., (std::cout << args)) << '\n'; // left fold
}


template <typename... T>
void printright(T... args)
{
  ((std::cout << args), ...) << '\n'; // right fold
}


template<typename T, typename... Args>
void push_back_many(std::vector<T>& v, Args&&... args)
{
  (v.push_back(args), ...);
}


template<typename T, typename... Args>
struct foo1{};

template<typename... Args>
using int_foo1 = foo1<int,Args...>;


int main ()
{
  {
    mytuple<int,double> two(42,4.2);
    mytuple<int,double,char> three(42,4.2,'a');
  }

  {
    std::cout << mysum2<int>(1,2,3,4) << '\n';
    printleft('d', 'o', 'g'); // dog
    printright('d', 'o', 'f'); // dog

    std::vector<int> v;
    push_back_many(v, 1, 2, 3, 4, 5);
  }

  {
    foo1<double, char, int> f1;
    foo1<int, char, double> f2;
    int_foo1<char, double> f3;
  }

  std::cout << '\n';
  return 0;
}