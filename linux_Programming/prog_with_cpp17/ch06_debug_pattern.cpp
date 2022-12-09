#include <iostream>

#ifndef NDEBUG
#define DEBUG(...) fprintf(stdout, __VA_ARGS__);
#else
#define DEBUG(...)
#endif

int main()
{
  {
    std::cout << "buffered" << '\n';
    std::cout << "buffer flushed" << std::endl;
    std::cerr << "buffer flushed" << '\n';
  }
  
  DEBUG("test number %d\n", 4);
  return 0;
}
