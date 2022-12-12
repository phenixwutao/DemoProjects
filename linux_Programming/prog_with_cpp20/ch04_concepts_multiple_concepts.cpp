#include <concepts>
#include <compare>
#include <string>

#include <forward_list>
#include <list>
#include <vector>
#include <iostream>

using namespace std;

template<typename Iter, typename Val>
requires std::input_iterator<Iter> && std::equality_comparable<Value_type<Iter>, Val>
Iter find(Iter b, Iter e, Val v)

int main()
{

  return 0;
}
