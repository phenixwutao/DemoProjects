#include <iostream>

class demo
{
public:
  demo()
  {
    // throw exception in user-defined class
    throw std::runtime_error("the answer is wrong");
  }
};
int main()
{
  // the code will call std::terminate() then abort()
  auto ptr = new (std::nothrow) demo;
  std::cout << ptr << std::endl;
  delete ptr;

  return 0;
}
