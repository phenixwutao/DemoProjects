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
  std::optional<int> oEmpty;
  std::optional<int> oTwo(2);
  std::optional<int> oTen(10);
  std::cout << std::boolalpha;
  std::cout << (oTen > oTwo) << '\n';
  std::cout << (oTen < oTwo) << '\n';
  std::cout << (oEmpty < oTwo) << '\n';
  std::cout << (oEmpty == std::nullopt) << '\n';
  std::cout << (oTen == 10) << '\n';
  return 0;
}

