#include <iostream>
using namespace std;

int main()
{
  []() constexpr -> void{};

  auto i = [](){ printf();}();
  return 0;
}