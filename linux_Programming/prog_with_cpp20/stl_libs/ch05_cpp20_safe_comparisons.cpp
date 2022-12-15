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

using namespace std;

 
int main()
{
  cout << std::boolalpha;
  int x = -3;
  unsigned int y = 7;

  // std::cmp_*** only works for integral numbers, does not work for float or double
  std::cout << "-3 == 7: " << std::cmp_equal(x, y) << '\n';
  std::cout << "-3 != 7: " << std::cmp_not_equal(x, y) << '\n';
  std::cout << "-3 < 7: " <<  std::cmp_less(x, y) << '\n';
  std::cout << "-3 <= 7: " << std::cmp_less_equal(x, y) << '\n';
  std::cout << "-3 > 7: " <<  std::cmp_greater(x, y) << '\n';
  std::cout << "-3 => 7: " << std::cmp_greater_equal(x, y) << '\n';
  return 0;
}
