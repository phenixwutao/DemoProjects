#include <concepts>
#include <compare>
#include <string>

#include <forward_list>
#include <list>
#include <vector>
#include <iostream>

using namespace std;

template<std::forward_iterator I>
void advance(I& iter, int n)
{
  std::cout << "forward_iterator" << endl;
}

template<std::bidirectional_iterator I>
void advance(I& iter, int n)
{
  std::cout << "bidirectional_iterator" << endl;
}

template<std::random_access_iterator I>
void advance(I& iter, int n)
{
  std::cout << "random_access_iterator" << endl;
}

int main()
{
  std::forward_list forwardlist {1,2,3};
  std::forward_list<int>::iterator itFor = forwardlist.begin();
  advance(itFor, 2);

  std::list li {1,2,3};
  std::list<int>::iterator itBi = li.begin();
  advance(itBi, 2);

  std::vector vec {1,2,3};
  std::vector<int>::iterator itRa = vec.begin();
  advance(itRa, 2);

  return 0;
}
