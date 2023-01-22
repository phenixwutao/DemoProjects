#include <iostream>
#include <functional>

using namespace std;

double divide(double num, double denom)
{
  return num / denom;
}

//C++ 14 std
auto inverted_divide = std::bind(divide, std::placeholders::_2, std::placeholders::_1);

// C++17 std and above
auto inverted_divide2 = [](const auto num, const auto denom)
{
  return divide(denom / num);
};

template<typename Func>
std::function<int(int)> bind_3(Func func)
{
  return std::bind(func, std::placeholders::_1, 3);
}

template<typename Func>
auto bind_4(Func func)
{
  return std::bind(func, std::placeholders::_1, 3);
}

// use lambda
template<typename Func>
auto bind_5(Func func)
{
  return [func](const int value)
          { return func(value, 3); };
}

int main()
{
  auto val3 = bind_3(std::plus<>{})(3);
  cout << "val3 = " << val3 << '\n';

  auto val4 = bind_4(std::plus<>{})(3);
  cout << "val4 = " << val4 << '\n';

  auto val5 = bind_5(std::plus<>{})(3);
  cout << "val5 = " << val5 << '\n';
  return 0;
}