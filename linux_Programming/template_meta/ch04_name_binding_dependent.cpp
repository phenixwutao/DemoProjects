#include <stdarg.h>
#include <iostream>
#include <array>
#include <functional>
#include <type_traits>

using namespace std;

template <typename T>
struct base_parser
{
  void init()
  {
    std::cout << "init\n";
  }
};

template <typename T>
struct parser : base_parser<T>
{
  void parse()
  {
    this->init();
    std::cout << "parse\n";
  }
};

template <>
struct base_parser<int>
{
  void init()
  {
    std::cout << "specialized init\n";
  }
};



template <typename T>
struct base_parser2
{
  using value_type = T;
};

template <typename T>
struct parser2 : base_parser2<T>
{
  void parse2()
  {
    // value_type v{}; // [1] error
    // or
    // base_parser<T>::value_type v{}; // [2] error

    typename base_parser<T>::value_type v{};
    std::cout << "parse\n";
  }
};

int main()
{
  parser<int> p1;
  p1.parse();

  parser<double> p2;
  p2.parse();

  return 0;
}
