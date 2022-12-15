// spanTransform.cpp

#include <algorithm>
#include <iostream>
#include <vector>
#include <span>

void printMe(std::span<int> container, const std::string& msg) {
    
  std::cout << msg << " container.size(): " << container.size() << '\n';
  for (auto e : container) std::cout << e << ' ';
  std::cout << "\n\n";
}

int main()
{    
  std::cout << '\n';
    
  std::vector vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};    
  printMe(vec, "original vec");
    
  std::span span1(vec); // reference to all vec objects
  std::span span2{span1.subspan(1, span1.size() - 2)}; // reference to part of vec objects

  // transform span2 objects
  std::transform(span2.begin(), span2.end(),            
		 span2.begin(), 
		 [](int i){ return i * i; });
        
  printMe(vec, "after vec");
  printMe(span1, "span1");
  printMe(span2, "span2");
  return 0;
}
