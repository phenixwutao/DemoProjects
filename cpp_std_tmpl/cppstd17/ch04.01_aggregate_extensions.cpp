#include <iostream>

#include <array>
#include <tuple>
#include <string>
#include <utility>
#include <type_traits>
#include <complex>

#include <map>

using namespace std;


struct Data{
  std::string name;
  double value {0.0};
};

struct MoreData : public Data
{
  bool Done {false};
};

template<typename T>
struct D : std::string, std::complex<T>
{
  std::string data;
};

int main()
{
  Data x{"hello", 1.1};
  MoreData x1{{"name", 2.2}, false};
  MoreData x2{"name", 2.2, false};
  MoreData x3 {};
  MoreData x4;
  MoreData x5 {{"test"}};
  MoreData x6 {{}, true};

  D<float> s{{"hello"}, {4.5,6.7}, "world"}; // OK since C++17
  std::cout << std::is_aggregate<decltype(s)>::value << '\n'; // outputs: 1 (true)

  return 0;
}

