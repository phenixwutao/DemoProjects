#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

bool validParenthese(const std::string& value)
{
  std::map<char,int> brackets;
  for(auto c : value)
  {
    //printf("char %c\n", c);
    brackets[c]++;
  }

  // for (auto [c, count]: brackets)
  // {
  //   printf("  check ====> %c, count %d\n", c, count);
  // }

  auto  valid_pair = [&](const string& value)
  {
    return brackets.count(value[0]) == brackets.count(value[1]);
  };

  return (valid_pair("()") && valid_pair("[]") && valid_pair("{}"));
}

int main()
{

  std::cout << boolalpha;
  std::cout << validParenthese("()") << '\n';
  std::cout << validParenthese("()[]{}") << '\n';
  std::cout << validParenthese("(]") << '\n';
  return 0;
}


