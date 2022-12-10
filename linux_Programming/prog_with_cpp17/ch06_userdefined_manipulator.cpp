#include <iostream>
#include <iomanip>

using namespace std;

namespace usr
{
  // define class hex_t, create an object hex in namespace usr
  class hex_t {} hex;
}

std::ostream& operator<<(std::ostream& os, const usr::hex_t &obj)
{
  os << std::hex << std::showbase << std::internal
     << std::setfill('0') << std::setw(18);
  return os;
}

int main()
{
  std::cout << "test value is " << usr::hex << 16 << '\n';
  return 0;
}
