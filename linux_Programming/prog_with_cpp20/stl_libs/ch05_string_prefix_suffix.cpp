#include <iostream>
#include <numeric>
#include <deque>
#include <list>
#include <string>
#include <string_view>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

template <typename PrefixType>
void startsWith(const std::string& str, PrefixType prefix)
{
  std::cout << "            starts with " << prefix << ": " 
	    << str.starts_with(prefix) << '\n';
}

template <typename SuffixType>
void endsWith(const std::string& str, SuffixType suffix)
{
  std::cout << "            ends with " << suffix << ": " 
	    << str.ends_with(suffix) << '\n';
}
 
int main()
{
  std::cout << '\n';
    
  std::cout << std::boolalpha;    
    
  std::string helloWorld("Hello World");
    
  std::cout << helloWorld << '\n';
 
  startsWith(helloWorld, helloWorld);                 
 
  startsWith(helloWorld, std::string_view("Hello"));  
 
  startsWith(helloWorld, 'H');                        
    
  std::cout << "\n\n"; 
    
  std::cout << helloWorld << '\n';
 
  endsWith(helloWorld, helloWorld);
 
  endsWith(helloWorld, std::string_view("World"));
 
  endsWith(helloWorld, 'd');

  std::string test("This is a test");
  cout << test.starts_with("this") << endl;
  cout << test.starts_with("This") << endl;
  return 0;
}
