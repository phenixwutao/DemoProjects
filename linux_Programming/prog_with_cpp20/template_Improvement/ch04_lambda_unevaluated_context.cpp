#include <concepts>

#include <string>
#include <forward_list>
#include <list>
#include <vector>
#include <set>
#include <unordered_set>

#include <memory>

#include <iostream>

#include <cmath>

#include <type_traits>

#include <compare>

using namespace std;

template <typename Container>
void printContainer(const Container& cont)
{
  for (const auto& c: cont)
    std::cout << c << " ";
  std::cout << "\n";
}

int main()
{
  cout <<std::boolalpha;

  std::set<std::string> set1 = {"scott", "Bjarne", "Herb", "Dave", "michael"};
  printContainer(set1);

  using SetDecreasing = std::set<std::string,
				 decltype([](const auto& l, const auto& r)
				 {
				   return l > r;
				 })>;
  
  SetDecreasing set2 = {"scott", "Bjarne", "Herb", "Dave", "michael"};
  printContainer(set2);

  using SetLength = std::set<std::string,
			     decltype([](const auto& l, const auto& r)
			     {
                              return l.size() < r.size();
                             })>;

  SetLength set3 = {"scott", "Bjarne", "Herb", "Dave", "michael"};
  printContainer(set3);

  std::cout << '\n';

  std::set<int> set4 = {-10, 5, 3, 100, 0, -25};
  printContainer(set4);

  using setAbsolute = std::set<int,
			       decltype([](const auto& l, const auto& r)
			       {
                                 return std::abs(l) < std::abs(r);
                               })>;
  
  setAbsolute set5 = {-10, 5, 3, 100, 0, -25};
  printContainer(set5);

  /*
   * With C++20, lambdas can have template parameters. In addition,
   * lambdas detect when the this pointer is implicitly referenced.
   */
  
  return 0;
}
