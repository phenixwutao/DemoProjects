#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
  std::stringstream stream;
  stream << "the answer is " << 42 << '\n';
  std::cout << stream.str() << std::flush;

  std::clog << "The answer is: " << 43 << '\n';
  std::cout << "The answer is: " << 44 << std::endl;
  std::cout << "The answer is: " << 45 << '\n' << std::flush;

  std::cout << std::boolalpha;
  std::cout << "The answer is: " << true << '\n';
  std::cout << "The answer is: " << false << '\n';
  std::cout << std::noboolalpha;
  std::cout << "The answer is: " << true << '\n';
  std::cout << "The answer is: " << false << '\n';

  std::cout << "The answer is: " << 42 << '\n' << std::hex
	    << "The answer is: " << 42 << '\n';
  std::cout << "The answer is: " << 42 << '\n' << std::dec
	    << "The answer is: " << 42 << '\n';
  std::cout << "The answer is: " << 42 << '\n' << std::oct
	    << "The answer is: " << 42 << '\n';

  std::cout << std::hex << std::uppercase << "The answer is: "
	    << 42 << '\n';

  printf("show base\n");
  std::cout << std::showbase;
  std::cout << std::hex << "The answer is: " << 42 << '\n';
  std::cout << std::dec << "The answer is: " << 42 << '\n';
  std::cout << std::oct << "The answer is: " << 42 << '\n';

  {
    int i = 0;
    std::cout << &i << '\n';
    std::cout << std::hex << std::showbase << std::uppercase
	      << reinterpret_cast<uintptr_t>(&i) << '\n';
  }

  std::cout << "The answer is: " << std::setw(18) << 42 << '\n';

  // set fill
  std::cout << "The answer is: " << std::setw(18) << std::setfill('0')
	    << 42 << '\n';

  std::cout << "The answer is: "
	    << std::setw(18) << std::left << std::setfill('0')
	    << 42 << '\n';
  std::cout << "The answer is: "
	    << std::setw(18) << std::right << std::setfill('0')
	    << 42 << '\n';

  {
    printf("std::internal\n");
    int i = 0;
    std::cout << std::hex
	      << std::showbase;
    std::cout << "The answer is: "
	      << std::setw(18) << std::internal << std::setfill('0')
	      << 42 << '\n';
    std::cout << "The answer is: "
	      << std::setw(18) << std::internal << std::setfill('0')
	      << &i << '\n'; 
  }
  
  return 0;
}
