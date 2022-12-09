#include <iostream>

#ifndef DEBUG_LEVEL
#define DEBUG_LEVEL 0
#endif
#ifndef NDEBUG
#define DEBUG(level,...)					\
  if(level <= DEBUG_LEVEL) fprintf(stdout, __VA_ARGS__);
#else
#define DEBUG(...)
#endif


int main()
{
  DEBUG(0, "The answer is: %d\n", 42);
  DEBUG(1, "The answer no is: %d\n", 43);
  return 0;
}
