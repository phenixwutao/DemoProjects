#include <iostream>

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

#define console std::cout << __FILE__ << " [" << __LINE__ << "]: "

template <std::size_t LEVEL>
constexpr void debug(void(*func)()) {
  if constexpr (!g_ndebug && (LEVEL <= g_debug_level))
		 func();
}

int main()
{
  debug<0>([] {
    console << " the answer is " << 45 << std::endl;
  }) ;
  
  debug<1>([] {
    console << " the answer is " << 45 << std::endl;
  }) ;
  return 0;
}
