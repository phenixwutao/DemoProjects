#include <iostream>
#include <numeric>
#include <deque>
#include <list>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

template<typename AssocContainer>
bool Contains5(const AssocContainer& cont)
{
  return cont.contains(5);
}

int main()
{
  {
    std::set mySet {3,2,1};
    if (mySet.find(2) != mySet.end())
      cout << "find 2 inside" << '\n';

    std::multiset mymultiset{1,2,3,2};
    if (mymultiset.count(2) > 0)
      cout << "find 2 inside" << '\n';
    cout << '\n';
  }
  
  std::cout << std::boolalpha;
    
  std::cout << '\n';
    
  std::set<int> mySet{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << "Contains5(mySet): " << Contains5(mySet);
    
  std::cout << '\n';
    
  std::unordered_set<int> myUnordSet{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << "Contains5(myUnordSet): " << Contains5(myUnordSet);
    
  std::cout << '\n';
    
  std::map<int, std::string> myMap{ {1, "red"}, {2, "blue"}, {3, "green"} };
  std::cout << "Contains5(myMap): " << Contains5(myMap);
  std::cout << '\n';
  cout << "find 2: " << myMap.contains(2) << endl;
    
  std::cout << '\n';
    
  std::unordered_map<int, std::string> myUnordMap{ {1, "red"}, 
						   {2, "blue"}, {3, "green"} };
  std::cout << "Contains5(myUnordMap): " << Contains5(myUnordMap);
    
  std::cout << '\n';  
  return 0;
}
