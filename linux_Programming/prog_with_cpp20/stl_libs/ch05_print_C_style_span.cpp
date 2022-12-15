// printSpan.cpp

#include <iostream>
#include <vector>
#include <array> // std::array
#include <span>

void printMe(std::span<int> container)
{    
  std::cout << "container.size(): " << container.size() << '\n';  // (4)
  for (auto e : container) std::cout << e << ' ';
  std::cout << "\n\n";
}

int main() {
    
  std::cout << '\n';
    
  int arr[]{1, 2, 3, 4}; // C style array        
  printMe(arr);
    
  std::vector vec{1, 2, 3, 4, 5};     
  printMe(vec);

  std::array arr2{1, 2, 3, 4, 5, 6}; // C++11 std::array
  printMe(arr2);
  return 0;
}
