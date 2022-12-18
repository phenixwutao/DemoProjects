#include <map>
#include <iostream>
#include <string>
using namespace std;

class UserEntry
{
public:
  void Load() { }
  
  std::string GetName() const { return name; }
  
  unsigned GetAge() const { return age; }

private:
  std::string name;
  unsigned age { 0 };
  size_t cacheEntry { 0 }; // not exposed
};

template <size_t I> auto get(const UserEntry& u)
{
  if constexpr (I == 0)
    return u.GetName();
  else if constexpr (I == 1)
    return u.GetAge();
}

namespace std
{
  template <> struct tuple_size<UserEntry> : std::integral_constant<size_t, 2> { };
  
  template <> struct tuple_element<0,UserEntry> { using type = std::string; };
  
  template <> struct tuple_element<1,UserEntry> { using type = unsigned; };
}

template<> string get<0>(const UserEntry &u) { return u.GetName(); }

template<> unsigned get<1>(const UserEntry &u) { return u.GetAge(); }


int main()
{
  UserEntry u;
  u.Load();
  auto [name, age] = u; // read access
  std:: cout << name << ", " << age << '\n';
 
  return 0;
}

