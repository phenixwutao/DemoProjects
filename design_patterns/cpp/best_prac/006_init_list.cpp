#include <iostream>
#include <vector>
#include <array>
#include <memory>
using namespace std;

/*
Resources
 Professional CMake: A Practical Guide⁵
 C++Now 2017: Daniel Pfeiffer “Effective CMake”⁷
*/
int main()
{
  std::vector<std::shared_ptr<int>> vec1{std::make_shared<int>(40), std::make_shared<int>(2)};

  std::array<std::shared_ptr<int>, 2> vec2{std::make_shared<int>(40), std::make_shared<int>(2)};

  // compile error
  //std::vector<std::unique_ptr<int>> vec3{std::make_unique<int>(40), std::make_unique<int>(2)};
  //std::vector<std::unique_ptr<int>> data{std::make_unique<int>(40), std::make_unique<int>(2)};
  return 0;
}