#include <iostream>
#include <deque>
#include <list>
#include <string>
#include <string_view>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <utility>

#include <numbers> // cpp20 math constants
#include <iomanip>

#include <cmath>   // lerp function
#include <numeric> // midpoint function

#include <bit> // std::endian

using namespace std;

 
int main()
{
  cout << std::boolalpha;
  if constexpr (std::endian::native == std::endian::big)
    {
      std::cout << "big-endian" << '\n';
    }
  else if constexpr (std::endian::native == std::endian::little)
    {
      std::cout << "little-endian" << '\n'; // little-endian
    }
  std::cout << '\n';
  return 0;
}
