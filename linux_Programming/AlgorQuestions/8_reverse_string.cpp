#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>

#include <algorithm>
#include <limits>
#include <cmath>
using namespace std;


void reverseString(vector<char>& s)
{
  int j = s.size()-1;
  for(int i = 0; i < s.size(), (j!=i && j > s.size()/2-1); ++i, --j)
  {
    //if(s[i] != s[j])
    {
      char t = s[i];
      s[i] = s[j];
      s[j] = t;
    }
  }
}

void reverseString2(vector<char>& s)
{
  reverse(s.begin(), s.end());
}

int main()
{
  //std::vector<char> v1 = {'H','a','n','n','a','h'};
  //std::vector<char> v1 = {'H','e','l','l','o'};
  
  std::vector<char> v1 = {'A',' ','m','a','n',',',' ','a',' ','p','l','a','n',',',' ','a',' ','c','a','n','a','l',':',' ','P','a','n','a','m','a'};
  std::cout << v1.size() << endl;
  auto display = [](const vector<char>& v){
    for(auto c : v)
      printf("'%c' ", c);
    std::cout << '\n';
  };
  display(v1);
  reverseString2(v1);
  display(v1);
  return 0;
}


