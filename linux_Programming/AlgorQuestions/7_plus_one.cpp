#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

#include <algorithm>
#include <limits>
#include <cmath>
using namespace std;

vector<int> plusOne(const vector<int>& digits)
{
  std::vector<int> output;
  if (digits.size() == 0 || digits[0] == 0)
  {
    output.push_back(1);
    return output;
  }

  unsigned long long int sum = 0;
  for(int i = 0; i < digits.size(); ++i)
  {
    unsigned long long int powsize = digits.size()-1-i;
    unsigned long long int factor = 1;
    while(powsize> 0)
    {
      factor *= 10;
      powsize--;
    }
    sum += digits[i] * factor;
    printf("digits[i] %llu, factor %llu, sum %llu\n", digits[i], factor, sum);
  }
  sum += 1;

  string value = std::to_string(sum);
  for(int i = 0; i < value.size(); ++i)
  {
    std::cout << value[i] << ' ';
  }
  std::cout << '\n';

  for(int i = 0; i < value.size(); ++i)
  {
    //std::cout << value[i] << ' ';
    int v = int(value[i])-48;
    output.push_back(v);
  }
  return (output);
}


int main()
{
  std::vector<int> v1 = {0,1};
  std::vector<int> v2 = {4,3,2,1};
  std::vector<int> v3 = {6,1,4,5,3,9,0,1,9,5,1,8,6,7,0,5,5,4,3};
  std::vector<int> v4 = {7,2,8,5,0,9,1,2,9,5,3,6,6,7,3,2,8,4,3,7,9,5,7,7,4,7,4,9,4,7,0,1,1,1,7,4,0,0,6};
  std::vector<int> v5 = {3,3,9,0,7,4,1,6,1,9,1,5,4,4,7,6,6,6,3};

  // auto out1 = plusOne(v1);
  // auto out2 = plusOne(v2);
  // auto out3 = plusOne(v3);
  auto out4 = plusOne(v4);
  // auto out5 = plusOne(v5);
  auto display = [](const std::vector<int>& v){
    for(auto i : v)
      std::cout << i << ' ';
    std::cout << '\n';
  };
  // display(out1);
  // display(out2);
  // display(v3);
  // display(out3);
  printf("------------------------------------ v4\n");
  display(v4);
  display(out4);
  printf("------------------------------------ v5\n");
  // display(v5);
  // display(out5);
  return 0;
}


