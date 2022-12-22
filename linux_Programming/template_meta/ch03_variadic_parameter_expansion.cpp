#include <stdarg.h>
#include <iostream>
#include <array>
#include <functional>
#include <type_traits>

using namespace std;

template<typename... T>
struct outer
{
  template<T...args>
  struct inner {};
};


template<typename... T>
struct tag {};

template<typename T, typename U, typename... Args>
void tagger()
{
  tag<T, U, Args...> t1;
  tag<T, Args..., U> t2;
  tag<Args..., T, U> t3;
  tag<U, T, Args...> t4;
}

template <typename... Args>
void make_it(Args... /*args*/ )
{
}


template <typename T>
T step_it(T value)
{
  std::cout << "step_it: " << __PRETTY_FUNCTION__ << "\n";
  return value +1;
}


template<typename... T>
int sum(T... args)
{
  std::cout << "sum: " << __PRETTY_FUNCTION__ << "\n";
  return (... + args);
}

template<typename... T>
void do_sum(T... args)
{
  auto s1 = sum( args... );
  auto s2 = sum( 42, args... );
  auto s3 = sum( step_it(args)... );
  std::cout << "s1= " << s1 << ", s2= " << s2 << ", s3= " << s3 << '\n';
}


template<typename... T>
struct sum_wrapper
{
  sum_wrapper(T... args)
  {
    value = (... + args);
  }

  std::common_type_t<T...> value;
};

template<typename... T>
void parenthesized(T... args)
{
  std::array<std::common_type_t<T...>, sizeof...(T)> arr {args...};
  
  sum_wrapper sw1(args...);

  sum_wrapper sw2(++args...);
}


template<typename... T>
void brace_enclosed(T... args)
{
  int arr1[sizeof...(args)+1] = {args..., 0};
  for(auto i : arr1)
    std::cout << i << ' ';
  std::cout << '\n';

  int arr2[sizeof...(args)] = { step_it(args)... }; // expansion to call step_it
  for(auto i : arr2)
    std::cout << i << ' ';
  std::cout << '\n';
}

template<typename... T>
void captures(T... args)
{
  auto lam = [args...](){
    return sum( step_it(args)... );
  };
  auto sum = lam();
  std::cout << "sum of lam is: "<< sum << '\n';
}


template<typename... T>
int foldSum(T... args)
{
  return (... + args);
}

template<typename... T>
auto make_array(T... args)
{
  return std::array<std::common_type_t<T...>, sizeof...(T)> {args...};
}

int main ()
{
  make_it(12);
  make_it(12, 'a');

  do_sum(1,2,3,4);

  parenthesized(1, 2, 3, 4);

  brace_enclosed(1,2,3,4);

  captures(1,2,3,4);

  auto arr3 = make_array(2,3,4,5);
  for(auto i : arr3)
    std::cout << i << ' ';
  std::cout << '\n';
  std::cout << '\n';
  return 0;
}