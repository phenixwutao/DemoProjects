#include <map>
#include <iostream>
#include <string>
using namespace std;

struct MyClass
{
  // inline variable
  inline static const int sValue = 777;
};

class MyClass2
{
  // inline variable (from function)
  static inline int seed = rand();
};

int main()
{
  const std::string myString = "My Hello World Wow";
  
  if (const auto pos = myString.find("Hello"); pos != std::string::npos)
    std::cout << pos << " Hello\n";
  
  return 0;
}

