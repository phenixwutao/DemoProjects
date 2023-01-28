#include <iostream>

#include <array>
#include <tuple>
#include <string>
#include <utility>

#include <map>

using namespace std;

int getValue()
{
  return 2;
}

int getID()
{
  return 90;
}

int main()
{
  if (auto x = getValue(), y = getID(); x == 2 && y == 90)
  {
    cout << "value " << x <<'\n';;
  }
  switch(auto y = getID(); y)
  {
    case 90:
    printf("ID 90\n");
    break;
  }

  return 0;
}

