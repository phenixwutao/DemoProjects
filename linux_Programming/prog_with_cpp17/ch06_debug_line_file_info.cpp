#include <iostream>

#ifndef NDEBUG
#define DEBUG(fmt, args...) \
  fprintf(stdout, "%s [%d]: " fmt, __FILE__, __LINE__, args);
#else
#define DEBUG(...)
#endif

int main()
{
  DEBUG("the answer is: %d\n", 4);
  return 0;
}
