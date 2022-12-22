#include <stdarg.h>
#include <iostream>
#include <array>
#include <functional>

using namespace std;
template <typename T>
T MinValue(T a, T b)
{
  std::cout << "Min2Value "<< __PRETTY_FUNCTION__ << "\n";
  return a < b ? a : b;
}

template <typename T, typename... Args> // template parameter pack
T MinValue(T a, Args... args)  // function parameter pack
{
  std::cout << "MinVarValue" << __PRETTY_FUNCTION__ << "\n";
  return MinValue(a, MinValue(args...));  // parameter pack expansion
}

template<typename T, typename... Args>
T MySum(T a, Args... args)
{
  if constexpr (sizeof...(args) == 0)
    return a;
  else
    return a + MySum(args...);
}


template<typename... Ts>
constexpr auto get_type_sizes()
{
  // sizeof...(Ts) : get the parameter pack size
  // sizeof(Ts)... : parameter pack expansion, sizeof(short), sizeof(int), ...
  return std::array<std::size_t, sizeof...(Ts)> {sizeof(Ts)...};
}


// two packs of parameters template
template<typename... Ts, typename... Us>
constexpr auto multipacks(Ts... args1, Us... args2)
{
  std::cout << "arg1: " << sizeof...(args1) << " , args2: " << sizeof...(args2) << '\n';
}

// class template variadic parameters
template<typename, typename>
struct func_pair;

template<typename R1, typename... A1, typename R2, typename... A2>
struct func_pair<R1(A1...), R2(A2...)>
{
  std::function<R1(A1...)> f;
  std::function<R2(A2...)> g;
};

bool twice_as(int a, int b)
{
  return a >= 2 * b;
}

double sum_div(int a, int b, double c)
{
  return (a+b)/c;
}

int main ()
{
  std::cout << std::boolalpha;
  auto val = MinValue(1,5,3,-4,-9);
  std::cout << "val " << val << '\n';

  auto val_sum = MySum(1,3,5,7,9);
  std::cout << "val_sum " << val_sum << '\n';

  auto sizes = get_type_sizes<short, int, long, long long>();
  for(const auto& i : sizes)
    cout << i << ' ';

  std::cout << '\n';

  multipacks<int>(1, 2, 3, 4, 5, 6);                          // 1,5
  multipacks<int, int, int>(1, 2, 3, 4, 5, 6);                // 3,3
  multipacks<int, int, int, int>(1, 2, 3, 4, 5, 6);           // 4,2
  multipacks<int, int, int, int, int, int>(1, 2, 3, 4, 5, 6); // 6,0
  multipacks<int, int>(1, 2, 4.0, 5.0, 6.0);                  // 2,3
  multipacks<int, int, int>(1, 2, 3, 4.0, 5.0, 6.0);          // 3,3
  multipacks<int,double,double>(1, 2, 3, 4.1, 5.1, 6.1);

  func_pair<bool(int,int), double(int,int,double)> funcs {twice_as, sum_div};
  auto valf = funcs.f(42,12);
  auto valg = funcs.g(42,12,10.0);
  std::cout << "valf= " << valf << ", valg= " << valg << '\n';

  std::cout << '\n';
  return 0;
}