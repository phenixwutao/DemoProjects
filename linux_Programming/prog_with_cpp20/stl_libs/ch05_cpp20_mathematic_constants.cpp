#include <iostream>
#include <numeric>
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

using namespace std;

 
int main()
{
  cout << std::boolalpha;
  std::cout<< std::setprecision(10);
  std::cout << "std::numbers::e: " << std::numbers::e << '\n';
  std::cout << "std::numbers::log2e: " << std::numbers::log2e << '\n';
  std::cout << "std::numbers::log10e: " << std::numbers::log10e << '\n';
  std::cout << "std::numbers::pi: " << std::numbers::pi << '\n';
  std::cout << "std::numbers::inv_pi: " << std::numbers::inv_pi << '\n';
  std::cout << "std::numbers::inv_sqrtpi: " << std::numbers::inv_sqrtpi << '\n';
  std::cout << "std::numbers::ln2: " << std::numbers::ln2 << '\n';
  std::cout << "std::numbers::sqrt2: " << std::numbers::sqrt2 << '\n';
  std::cout << "std::numbers::sqrt3: " << std::numbers::sqrt3 << '\n';
  std::cout << "std::numbers::inv_sqrt3: " << std::numbers::inv_sqrt3 << '\n';
  std::cout << "std::numbers::egamma: " << std::numbers::egamma << '\n';
  std::cout << "std::numbers::phi: " << std::numbers::phi << '\n';
  return 0;
}
