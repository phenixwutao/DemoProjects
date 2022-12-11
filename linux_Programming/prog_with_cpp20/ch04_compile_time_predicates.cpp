#include <concepts>
#include <compare>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// page 56

struct Test {};

int main()
{
  cout << std::boolalpha;
  cout << "std::three_way_comparable<int> "
       << std::three_way_comparable<int> << endl;
  cout << "std::three_way_comparable<double> ";
  if (std::three_way_comparable<double>)
    cout << "True" << endl;
  else
    cout << "False" << endl;

  static_assert(std::three_way_comparable<std::string>);

  std::cout << "std::three_way_comparable<Test>: ";
  if constexpr(std::three_way_comparable<Test>)
    std::cout << "True";
  else
    std::cout << "False";

  std::cout << '\n';

  std::cout << "std::three_way_comparable<std::vector<int>>: ";
  if constexpr(std::three_way_comparable<std::vector<int>>)
    std::cout << "True";
  else
    std::cout << "False";

  std::cout << '\n';
  return 0;
}
