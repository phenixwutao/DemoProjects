#include <optional>
#include <iostream>
#include <vector>
#include <complex>
#include <utility>
#include <string>

using namespace std;

class UserRecord
{
public:
  UserRecord (string name, optional<string> nick, optional<int> age)
    : mName{move(name)}, mNick{move(nick)}, mAge{age}
  {
  }
  
  friend ostream& operator << (ostream& stream, const UserRecord& user);

private:
  string mName;
  optional<string> mNick;
  optional<int> mAge;
};

ostream& operator << (ostream& os, const UserRecord& user)
{
  os << user.mName;
  if (user.mNick)
    os << ' ' << *user.mNick;
  if (user.mAge)
    os << ' ' << "age of " << *user.mAge;
  return os;
}

int main()
{
  UserRecord tim { "Tim", "SuperTim", 16 };
  UserRecord nano { "Nathan", nullopt, nullopt };
  cout << tim << '\n';
  cout << nano << '\n';
  return 0;
}

