#include <iostream>
#include <memory>
#include <type_traits>
#include <array>

using namespace std;


template<typename T, int S>
struct collection
{
  void operator()()
  {
    std::cout << "primary template";
  }
};

template<typename T>
struct collection<T, 10>
{
  void operator()()
  {
    std::cout << "partial specialization <T, 10>";
  }
};

template<int S>
struct collection<int, S>
{
  void operator()()
  {
    std::cout << "partial specialization <int, S>";
  }
};

template<typename T, int S>
struct collection<T*, S>
{
  void operator()()
  {
    std::cout << "partial specialization <T*, S>";
  }
};


template <typename T, size_t S>
std::ostream& pretty_print(std::ostream& os, const std::array<T, S>& arr)
{
  os << '[';
  if (S > 0)
  {
    size_t i = 0;
    for (; i < S - 1; ++i)
      os << arr[i] << ',';
    os << arr[S-1];
  }
  os << ']';
  return os;
}

template <size_t S>
std::ostream& pretty_print(std::ostream& os, const std::array<char, S>& arr)
{
  os << '[';
  for(const auto& e : arr)
    os << e;
  os << ']';
  return os;
}


int main()
{
  collection<char, 42> a; // primary template
  collection<int, 42> b; // partial specialization <int, S>
  collection<char, 10> c; // partial specialization <T, 10>
  collection<int*, 20> d; // partial specialization <T*, S>

  std::array<int, 9> arr {1, 1, 2, 3, 5, 8, 13, 21};
  pretty_print(std::cout, arr); // [1,1,2,3,5,8,13,21]
  std::cout <<'\n';

  std::array<char, 9> str = {"template"};
  //std::strcpy(str.data(), "template");
  pretty_print(std::cout, str); // [template]

  std::cout <<'\n';
  return 0;
}
