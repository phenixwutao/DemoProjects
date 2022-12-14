#include <concepts>

#include <string>
#include <forward_list>
#include <list>
#include <vector>
#include <unordered_set>

#include <iostream>

#include <type_traits>

#include <compare>
#include <cmath>

using namespace std;

struct Empty {};

struct NoUniqueAddress
{
  int d{};
  
  // empty struct member do not need to have a distinct address
  [[no_unique_address]] Empty e{}; 

};

struct UniqueAddress
{
  int d{};
  Empty e{};
};

int main()
{
  std::cout << std::boolalpha;

  std::cout << "sizeof(int) == sizeof(NoUniqueAddress): "<< sizeof(NoUniqueAddress) << '\n';
  std::cout << "sizeof(int) == sizeof(NoUniqueAddress): "
	    << (sizeof(int) == sizeof(NoUniqueAddress)) << '\n';

  std::cout << "sizeof(int) == sizeof(UniqueAddress): "<< sizeof(UniqueAddress) << '\n';
  std::cout << "sizeof(int) == sizeof(UniqueAddress): "
	    << (sizeof(int) == sizeof(UniqueAddress)) << '\n';

  std::cout << '\n';

  NoUniqueAddress NoUnique;

  std::cout << "&NoUnique.d: " << &NoUnique.d << '\n';
  std::cout << "&NoUnique.e: " << &NoUnique.e << '\n';

  std::cout << '\n';

  UniqueAddress unique;

  std::cout << "&unique.d: " << &unique.d << '\n';
  std::cout << "&unique.e: " << &unique.e << '\n';

  std::vector<double> v = {1,3,5,-10,6,-8};
  double sum = 0.0;
  for(size_t i=0; i < v.size(); ++i)
    {
      if (v[i] < 0) [[likely]] sum -= sqrt(-v[i]);
      else sum += sqrt(v[i]);
    }
  printf("sum = %f\n", sum);
  return 0;
}
