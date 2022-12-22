#include <iostream>
#include <memory>
#include <type_traits>
#include <vector>
#include <map>
#include <numeric> // std::accumulate
#include <array>
#include <algorithm> // std::count_if
#include <functional> // std::function

using namespace std;

int main()
{
  int arr[] = { 1,6,3,8,4,2,9 };
  std::sort(std::begin(arr), std::end(arr),
            [](int const a, int const b) {return a > b; });

  int pivot = 5;
  auto count = std::count_if(std::begin(arr), std::end(arr),
                            [pivot](int const a) {return a > pivot; });

  {
    auto l1 = [](int a) {return a + a; }; // C++11, regular

    // lambda
    auto l2 = [](auto a) {return a + a; }; // C++14, generic

    // lambda
    auto l3 = []<typename T>(T a) { return a + a; }; // C++20, template lambda

    auto v1 = l1(42); // OK
    auto v2 = l1(42.0); // warning
    //auto v3 = l1(std::string{ "42" }); // error

    auto v5 = l2(42); // OK
    auto v6 = l2(42.0); // OK
    auto v7 = l2(std::string{"42"}); // OK

    auto v8 = l3(42); // OK
    auto v9 = l3(42.0); // OK
    auto v10 = l3(std::string{ "42" }); // OK
  }

  // C++20 lambda
  {
    auto l1 = [](int a, int b) {return a + b; };
    auto l2 = [](auto a, auto b) {return a + b; };
    auto l3 = []<typename T, typename U>(T a, U b) { return a + b; };
    auto l4 = [](auto a, decltype(a) (b) ){ return a + b ; };

    auto v1 = l1(42, 1); // OK
    auto v2 = l1(42.0, 1.0); // warning
    //auto v3 = l1(std::string{ "42" }, '1'); // error

    auto v4 = l2(42, 1); // OK
    auto v5 = l2(42.0, 1); // OK
    auto v6 = l2(std::string{ "42" }, '1'); // OK
    auto v7 = l2(std::string{ "42" }, std::string{ "1" }); // OK
    
    auto v8 = l3(42, 1); // OK
    auto v9 = l3(42.0, 1); // OK
    auto v10 = l3(std::string{ "42" }, '1'); // OK
    auto v11 = l3(std::string{ "42" }, std::string{ "42" }); // OK
  }

  {
    auto lam = []<typename T, size_t N>(const std::array<T,N> & array)
    {
      return std::accumulate(array.begin(), array.end(), static_cast<T>(0) );
    };
    auto v1 = lam(std::array<int,1>{1});
    auto v2 = lam( std::array<int,3>{1,2,3} );
    printf("v1 %d v2 %d\n", v1, v2);
  }

  // recursive generic function
  {
    std::function<int(int)> factorial;
    factorial = [&factorial](const int n){
      if (n<2) return 1;
      else
        return n * factorial(n-1);
    };
    auto ff = factorial(5);
    printf("std::function factorial(5) is: %d\n", ff);

    auto fact = [](auto f, const int n){
      if (n < 2) return 1;
      else
        return n * f (f, n - 1);
    };
    printf("lambda factorial(5) is: %d\n", fact(fact, 5));
  }

  return 0;
}
