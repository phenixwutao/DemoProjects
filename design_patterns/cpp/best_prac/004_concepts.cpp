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

template <typename Numerator, typename Denominator>
auto divide(Numerator num, Denominator denom)
  requires(std::is_integral_v<Numerator>, std::is_integral_v<Denominator>)
{
  if (denom == 0)
    throw std::runtime_error("divided by zero");

  printf("int version\n");
  return num / denom;
}

template <typename Numerator, typename Denominator>
auto divide(Numerator num, Denominator denom)
{
  printf("other version\n");
  return num / denom;
}

[[nodiscard("Ignoring this result leaks resources")]] int getvalue()
{
  return 1;
}

double high_precision_thing(double r)
{
  return r * r;
}
double high_precision_thing(float) = delete;

int main()
{
  std::cout << "9/3= " << divide<int, int>(9.6, 3) << '\n';
  std::cout << "9.0/2.0= " << divide<double, double>(9.0F, 2.0F) << '\n';
  getvalue();
  // std::cout << high_precision_thing(3.3F) << '\n'; // compile error
  std::cout << high_precision_thing(3.3E0) << '\n';
  return 0;
}