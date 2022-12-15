#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

constexpr int maxElement()
{
  std::vector myVec = {1, 2, 4, 3};
  std::sort(myVec.begin(), myVec.end());
  return myVec.back();
}
int main()
{
  std::cout <<  '\n';

  constexpr int maxValue = maxElement();
  std::cout << "maxValue: " << maxValue << '\n';

  // define and invoke lambda function immediately:
  constexpr int maxValue2 = [] {
    std::vector myVec = {1, 2, 4, 3};
    std::sort(myVec.begin(), myVec.end()) ;
    return myVec.back();
  }(); 

  std::cout << "maxValue2: " << maxValue2 << '\n';

  std::cout << '\n';
  return 0;
}
