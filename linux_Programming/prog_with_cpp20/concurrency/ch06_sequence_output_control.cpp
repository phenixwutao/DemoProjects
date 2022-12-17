#include <chrono>
#include <iostream>
#include <thread>
#include <syncstream> // synchronized stream std::basic_osyncstream

using namespace std;

int main()
{
  std::osyncstream bout1(std::cout);
  bout1 << "Hello, ";
  {
    std::osyncstream(bout1.get_wrapped()) << "Goodbye!\n" ;
  } // emits the contents of the temporary buffer

  bout1 << "World\n";
  return 0;
} // emits the contents of the bout1 buffer

