#include <iostream>
#include <iomanip>

using namespace std;

template<typename FUNC>
void cout_transaction(FUNC f)
{
  auto flags = std::cout.flags();
  f();
  std::cout.flags(flags);
}

int main()
{
  cout_transaction([]{
    std::cout << std::hex << std::showbase;
    std::cout << "value is " << 16 << '\n';
  });
  
  std::cout << "test value is " << 2 << '\n';
  return 0;
}  
