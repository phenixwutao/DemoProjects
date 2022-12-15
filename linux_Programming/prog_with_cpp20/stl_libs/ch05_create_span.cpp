// printSpan.cpp

#include <iostream>
#include <vector>
#include <array> // std::array
#include <span>
#include <algorithm>

using namespace std;

void printMe(std::span<int> container)
{    
  std::cout << "container.size(): " << container.size() << '\n';  // (4)
  for (auto e : container) std::cout << e << ' ';
  std::cout << "\n\n";
}

int main()
{
  cout << std::boolalpha;
  vector myvec1{1,2,3,4,5};

  std::span myspan1{myvec1};

  std::span myspan2{myvec1.data(), myvec1.size()};

  bool spansSame = std::equal(myspan1.begin(), myspan1.end(), myspan2.begin(), myspan2.end());
  cout << "myspan1 == myspan1: " << spansSame << endl;
  return 0;
}
