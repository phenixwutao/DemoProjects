#include <concepts>
#include <compare>
#include <string>

#include <forward_list>
#include <list>
#include <vector>
#include <iostream>

using namespace std;

auto AddLambda = [](auto fir, auto sec)
                { return fir + sec; };

template<typename T, typename T2>
auto AddTemplate(T fir, T2 sec)
{
  return fir + sec;
}

int main()
{
  std::cout << std::boolalpha;
  cout << AddLambda(1,5) << " " << AddTemplate(1,5) << endl;
  cout << AddLambda(true,5) << " " << AddTemplate(true,5) << endl;
  cout << AddLambda(1,5.5) << " " << AddTemplate(1,5.5) << endl;

  const std::string fir("ge");
  const std::string sec("neric");
  cout << AddLambda(fir,sec) << " " << AddTemplate(fir,sec) << endl;

  return 0;
}
