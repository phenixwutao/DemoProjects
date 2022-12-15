#include <iostream>
#include <string_view>
#include <source_location> // std::source_location function

using namespace std;

void log(std::string_view message,
         const std::source_location& location = std::source_location::current())
{
  // replace C++11 macros __LINE__  __FILE__
  std::cout << "info:"
	    << location.file_name() << ':'
	    << location.line() << ' '
	    << message << '\n';
}
 
int main()
{
  log("Hello world!");
  return 0;
}
