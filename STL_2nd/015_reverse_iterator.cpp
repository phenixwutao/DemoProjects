#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
  vector<int> vv;
  for(int i = 1; i <= 9; ++i)
    vv.push_back(i);

  copy (vv.cbegin(), vv.cend(), ostream_iterator<int>(cout, " "));
  cout << endl;

  copy (vv.crbegin(), vv.crend(), ostream_iterator<int>(cout, " "));

  cout << endl;
  
  return EXIT_SUCCESS;
}
