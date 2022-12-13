#include <concepts>
#include <string>

#include <forward_list>
#include <list>
#include <vector>
#include <unordered_set>
#include <iostream>

#include <type_traits>

#include <compare>
using namespace std;


int main()
{
  std::cout << std::boolalpha;
  constexpr int a = 2011;
  constexpr int b = 2014;
  constexpr auto res = a <=> b;

  if (res < 0)       std::cout << "a < b" << '\n';
  else if (res == 0) std::cout << "a == b" << '\n';
  else if (res > 0)  std::cout << "a > b" << '\n';

  std::string str1("2014");
  std::string str2("2011");
  auto res2 = str1 <=> str2;
  if (res2 < 0) std::cout << "str1 < str2" << '\n';
  else if (res2 == 0) std::cout << "str1 == str2" << '\n';
  else if (res2 > 0) std::cout << "str1 > str2" << '\n';

  std::vector<int> vec1{1, 2, 3};
  std::vector<int> vec2{1, 2, 3};
  auto res3 = vec1 <=> vec2;
  if (res3 < 0) std::cout << "vec1 < vec2" << '\n';
  else if (res3 == 0) std::cout << "vec1 == vec2" << '\n';
  else if (res3 > 0) std::cout << "vec1 > vec2" << '\n';

  return 0;
}
