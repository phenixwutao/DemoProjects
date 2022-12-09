#include <iostream>

// C++17 debug approach
#ifndef NDEBUG
  constexpr auto g_ndebug = true;
#else
  constexpr auto g_ndebug = false;
#endif


int main()
{
  if constexpr (g_ndebug == true) {
    std::cout << "answer is: " << 42 << std::endl;
    }
  else {
    std::cout << "answer is: " << 0 << std::endl;
  }
  
  return 0;
}
