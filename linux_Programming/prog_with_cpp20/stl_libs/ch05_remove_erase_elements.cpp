#include <iostream>
#include <utility>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

int main()
{

  std::vector myVec{-2, 3, -5, 10, 3, 0, -5 };

  for (auto ele: myVec) std::cout << ele << " ";
  std::cout << "\n\n";

  auto newEnd = std::remove_if(myVec.begin(),
			       myVec.end(),        
			       [](int ele){ return ele < 0; });
  myVec.erase(newEnd, myVec.end());                              

  // myVec.erase(std::remove_if(myVec.begin(), myVec.end(),       
  // [](int ele){ return ele < 0; }), myVec.end());
  for (auto ele: myVec) std::cout << ele << " ";
  std::cout << "\n\n";
  return 0;
}
