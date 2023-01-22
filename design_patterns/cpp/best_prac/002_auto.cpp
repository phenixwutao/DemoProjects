#include <iostream>
#include <vector>
#include <array>
#include <atomic>
#include <algorithm>
#include <utility>
#include <functional>
#include <type_traits>
#include <stdexcept>
using namespace std;

// C++11 std
template <typename Numerator, typename Denominator>
auto divide(Numerator num, Denominator denom) -> decltype(num / denom)
{
  return num / denom;
}

// C++14 std
template <typename Numerator, typename Denominator>
auto divide2(Numerator num, Denominator denom)
{
  return num / denom;
}

// best version
template<typename Arithmetic>
Arithmetic divide3(Arithmetic numerator, Arithmetic denominator) {
return numerator / denominator;
}

template <typename Numerator, typename Denominator>
auto divide4(Numerator num, Denominator denom)
{
  if constexpr (std::is_integral_v<Numerator> && std::is_integral_v<Denominator>)
  {
    if (denom == 0)
      throw std::runtime_error("divide by zero");
  }
  return num / denom;
}

int main()
{
  cout << "10/5= " << divide<int, int>(10, 5) << '\n';
  cout << "10/5= " << divide2<int, int>(10, 5) << '\n';
  cout << "10/5= " << divide3<int>(10, 5) << '\n';
  try{
  cout << "10/0= " << divide4<int,int>(10, 0) << '\n';
  }
  catch(exception& e)
  {
  std::cout << "Exception Error: " << e.what() << '\n';
  }
  catch(...)
  {
  std::cout << "catch exception\n";
  }

  std::vector<int> vec1 = {1, 3, 8, 15, 29, 23, 9, 56};
  const auto has_value1 = std::any_of(vec1.begin(), vec1.end(), [](int i)
                                      { return i > 12; });
  return 0;
}