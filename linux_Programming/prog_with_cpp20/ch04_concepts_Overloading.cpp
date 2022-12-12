#include <concepts>
#include <compare>
#include <string>

#include <forward_list>
#include <list>
#include <vector>
#include <iostream>

using namespace std;

void calculate(auto t)
{
  cout << "auto: " << t << endl;
}

void calculate(std::integral auto t)
{
  cout << "std::integral auto: " << t << endl;  
}
void calculate(long t)
{
  cout << "long: " << t << endl;  
}

int main()
{
  calculate(3.14);  
  calculate(2022);  
  calculate(2022L);  
  return 0;
}
