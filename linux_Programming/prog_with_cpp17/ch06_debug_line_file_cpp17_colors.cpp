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
constexpr void debug(void(*func)())
{
  if constexpr (!g_ndebug && (LEVEL <= g_debug_level)) {
    std::cout << "\033[1;32mDEBUG\033[0m "; // display in green
    func();
  };
}

template <std::size_t LEVEL>
constexpr void warning(void(*func)()) {
  if constexpr (!g_ndebug && (LEVEL <= g_debug_level)) {
    std::cout << "\033[1;33mWARNING\033[0m "; // display in orange
    func();
  };
}


template <std::size_t LEVEL>
constexpr void fatal(void(*func)()) {
  if constexpr (!g_ndebug && (LEVEL <= g_debug_level)) {
    std::cout << "\033[1;31mFATAL ERROR\033[0m "; // display in red
    func();
    ::exit(-1);
  };
}

template <std::size_t LEVEL>
constexpr void fatal(int error_code, void(*func)()) {
  if constexpr (!g_ndebug && (LEVEL <= g_debug_level)) {
    std::cout << "\033[1;31mFATAL ERROR\033[0m "; // display in red
    func();
    ::exit(error_code);
  };
}

int main()
{
  debug<0>([] {
    console << "The answer is: " << 42 << '\n';
  });
  
  warning<0>([] {
    console << "The answer might be: " << 42 << '\n';
  });
  
  fatal<0>([] {
    console << "The answer was not: " << 42 << '\n';
  });

  return 0;
}
