#include <iostream>

// C++17 debug approach
#ifdef DEBUG_LEVEL
  constexpr auto g_debug_level = DEBUG_LEVEL;
#else
  constexpr auto g_debug_level = 0;
#endif

#ifdef NDEBUG
constexpr auto g_ndebug = true;
#else
constexpr auto g_ndebug = false;
#endif

int main()
{
  if constexpr (!g_ndebug && (0 <= g_debug_level)) {
    std::cout << "The answer is: " << 42 << '\n';
  }
  if constexpr (!g_ndebug && (1 <= g_debug_level)) {
    std::cout << "The answer is not: " << 43 << '\n';
  }
 
  return 0;
}
