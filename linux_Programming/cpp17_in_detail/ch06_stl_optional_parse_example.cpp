#include <optional>
#include <iostream>
#include <vector>
#include <complex>
#include <utility>
#include <string>

using namespace std;

std::optional<int> ParseInt(const char* arg)
{
  try
    {
      return { std::stoi(std::string(arg)) };
    }
  catch (...)
    {
      std::cerr << "cannot convert '" << arg << "' to int! exit\n";
    }
  return { };
}


int main(int argc, char* argv[])
{
  if (argc >= 3)
    {
      auto oFirst = ParseInt(argv[1]);
      auto oSecond = ParseInt(argv[2]);
      if (oFirst && oSecond)
	{
	  std::cout << "sum of " << *oFirst << " and " << *oSecond;
	  std::cout << " is " << *oFirst + *oSecond << '\n';
	}
    } 
  return 0;
}

