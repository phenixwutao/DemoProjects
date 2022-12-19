// page 228
#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <set>
#include <algorithm>
#include <execution>
#include <exception>
#include <chrono>
#include <numeric> // for gcm, lcm
#include <cmath>
#include <string_view>

#include <random> // std::sample


using namespace std;

struct User
{
  std::string name;
  
  User(std::string s) : name(std::move(s))
  {
    std::cout << "User::User(" << name << ")\n";
  }

  ~User()
  {
    std::cout << "User::~User(" << name << ")\n";
  }
  
  User(const User& u) : name(u.name) {
    std::cout << "User::User(copy, " << name << ")\n";
  }
  
  friend bool operator<(const User& u1, const User& u2)
  {
    return u1.name < u2.name;
  }
};


template <class Container>
void PrintBasicInfo(const Container& cont) {
  std::cout << "PrintBasicInfo --------\n";
  std::cout << "typeid(cont).name() " << typeid(cont).name() << '\n';
  std::cout << "size " << std::size(cont) << '\n';
  std::cout << "std::empty " << std::empty(cont) << '\n';
  if (!std::empty(cont))
    std::cout << "*data() " << *std::data(cont) << '\n';
}

int main( int argc, char* argv[])
{
  std::cout << std::boolalpha;
  
  // test 1
  {
    std::set<User> setNames;
    setNames.emplace("John");
    setNames.emplace("Alex");
    setNames.emplace("Bartek");
    
    std::set<User> outSet;    
    std::cout << "move John...\n";
    // move John to the outSet
    auto handle = setNames.extract(User("John"));
    outSet.insert(std::move(handle));
    
    for (auto& elem : setNames)
      std::cout << elem.name << '\n';
    
    std::cout << "cleanup...\n";
  }


  // test 2
  {
    std::map<std::string, int> m;
    m["hello"] = 1;
    m["world"] = 2;
    
    // C++11 way:
    if (m.find("great") == std::end(m))
      m["great"] = 3;    
    // the lookup is performed twice if "great" is not in the map
    
    // C++17 way:
    m.try_emplace("super", 4);
    m.try_emplace("hello", 5); // won't emplace, as it's already in the map
    
    for (const auto& [key, value] : m)
      std::cout << key << " -> " << value << '\n';
  }

  // test 3
  {
    std::map<std::string, std::string> m;
    m["Hello"] = "World";
    
    std::string s = "C++";
    m.emplace(std::make_pair("Hello", std::move(s)));
    
    // what happens with the string 's'?
    std::cout << "s is: " << s << '\n';
    std::cout << m["Hello"] << '\n';

    // C++17 try_emplace does nothing if key already exist
    s = "C++";
    m.try_emplace("Hello", std::move(s));
    std::cout << "s is: " << s << '\n';
    std::cout << m["Hello"] << '\n';
  }


  // test 4 insert_or_assign
  {
    std::map<std::string, User> mapNicks;
    //mapNicks["John"] = User("John Doe"); // error: no default ctor for User()
    auto [iter, inserted] = mapNicks.insert_or_assign("John", User("John Doe"));
    if (inserted)
      std::cout << iter->first << " entry was inserted\n";
    else
      std::cout << iter->first << " entry was updated\n";
  }

  // test 5 emplace_back returns the reference type of the inserted object
  {
    std::vector<std::string> stringVector;
    // in C++11/14:
    stringVector.emplace_back("Hello");
    
    // emplace doesn't return anything, so back() needed
    stringVector.back().append(" World");
    
    // in C++17:
    stringVector.emplace_back("Hello").append(" World");
  }

  // test 6 std::sample
  {
    std::vector<int> v { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    std::vector<int> out;
    std::sample(v.begin(), // range start
		v.end(),   // range end
		std::back_inserter(out), // where to put it
		5,                       // number of elements to sample
		std::mt19937{std::random_device{}()});
    std::cout << "Sampled values: ";
    for (const auto &i : out)
      std::cout << i << ", ";
    cout << '\n';
  }

  // test 7 New Mathematical Functions
  {
    std::cout << std::gcd(24, 60) << '\n'; // std::gcd (Greatest Common Divisor)
    std::cout << std::lcm(15, 50) << '\n'; // std::lcm (Least Common Multiple)
  }

  // test 8 : size() data() empty()
  {
    std::vector<int> iv { 1, 2, 3, 4, 5 };
    PrintBasicInfo(iv);
    float arr[4] = { 1.1f, 2.2f, 3.3f, 4.4f };
    PrintBasicInfo(arr);
  }
  
  return 0;
}

