#include <optional>
#include <iostream>
#include <vector>
#include <complex>
#include <utility>
#include <string>

using namespace std;

class UserName
{
public:
  explicit UserName(std::string str) : mName(std::move(str))
  {
    std::cout << "UserName::UserName('" << mName << "')\n";
  }
  
  ~UserName()
  {
    std::cout << "UserName::~UserName('" << mName << "')\n";
  }

private:
  std::string mName;
};

int main()
{
  // by operator* : if there’s no value the behaviour is undefined!
  std::optional<int> oint = 10;
  std::cout<< "oint " << *oint << '\n';

  
  // by value(): returns the value, or throws std::bad_optional_access
  std::optional<std::string> ostr("hello");
  try
    {
      std::cout << "ostr " << ostr.value() << '\n';
    }
  catch (const std::bad_optional_access& e)
    {
      std::cout << e.what() << '\n';
    }

  
  // by value_or() : returns the value if available, or defaultVal otherwise
  std::optional<double> odouble; // empty
  std::cout<< "odouble " << odouble.value_or(10.0) << '\n';

  // change optional value
  std::optional<UserName> oEmpty;
  
  // emplace:
  oEmpty.emplace("Steve");
  
  // calls ~Steve and creates new Mark:
  oEmpty.emplace("Mark");
  
  // reset so it's empty again
  oEmpty.reset(); // calls ~Mark
  
  // same as:
  oEmpty.emplace("Mark2");
  oEmpty = std::nullopt;
  
  // assign a new value:
  oEmpty.emplace("Fred");
  oEmpty = UserName("Joe");
  
  return 0;
}

