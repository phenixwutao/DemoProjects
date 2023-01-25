#include <iostream>
using namespace std;
consteval int get_value(const int input)
{
  return input * 42;
}

struct Data
{
  std::string first;
  std::string second;
};

int main(const int argc, const char *[])
{
  Data a {.first="hello", .second="world"};

	// will this code compile?  NO, error: ‘argc’ is not a constant expression
	const auto value = get_value(argc);
  return 0;
}
