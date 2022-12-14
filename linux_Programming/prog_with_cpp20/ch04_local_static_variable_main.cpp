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

int staticA();
auto staticB = staticA();

int main()
{
  cout << "staticB = " << staticB << endl;
  return 0;
}