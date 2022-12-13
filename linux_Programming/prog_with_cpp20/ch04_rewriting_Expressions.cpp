#include <concepts>
#include <string>

#include <forward_list>
#include <list>
#include <vector>
#include <unordered_set>
#include <iostream>

#include <type_traits>

#include <compare>
using namespace std;

class MyInt {
public:
  constexpr MyInt(int v) : value (v) {}
  auto operator <=> (const MyInt& rhs) const = default;
private:
  int value;
};

int main()
{
  cout <<std::boolalpha ;
  constexpr MyInt myint1(2011);
  constexpr MyInt myint2(2014);
  constexpr int i1(2011);
  constexpr int i2(2014);
  printf("debug 1: i1 versus i2\n");
  if (i1 < i2) cout << "raw: i1 < i2 " << endl;
  if ((i1 <=> i2) < 0) cout << "3way: i1 < i2 " << endl;

  printf("debug 2: myint1 vs myint2\n");
  if (myint1 < myint2) cout << "raw: myint1 < myint2 " << endl;
  if ((myint1 <=> myint2) < 0) cout << "3way: myint1 < myint2 " << endl;

  printf("debug 3: i1 vs myint2\n");
  if (i1 < myint2) cout << "raw: i1 < myint2 " << endl;
  if ((i1 <=> myint2) < 0) cout << "3way: i1 < myint2 " << endl;

  printf("debug 4: myint1 vs i2\n");
  if (myint1 < i2) cout << "raw: myint1 < i2 " << endl;
  if ((myint1 <=> i2) < 0) cout << "3way: myint1 < i2 " << endl;

  printf("debug 5: myint1 vs i2\n");
  if (myint1 < i2) cout << "raw: myint1 < i2 " << endl;
  if (0 < (i2 <=> myint1)) cout << "3way: myint1 < i2 " << endl;
  return 0;
}
