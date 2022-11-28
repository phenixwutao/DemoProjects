#include <iostream>

#include <vector>
#include <deque>
#include <list>
#include <map>
#include <set>

#include <memory> // smart pointers

#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <future>

#include <limits>

using namespace std;

int main()
{

  cout << boolalpha;
  cout << "max(short) " <<numeric_limits<short>::max() << endl;
  cout << "max(short) " <<numeric_limits<unsigned short>::max() << endl;
  cout << "max(short) " <<numeric_limits<int>::max() << endl;
  cout << "max(short) " <<numeric_limits<long>::max() << endl;
  cout << "is_signed(char) " <<numeric_limits<char>::is_signed << endl;
  cout << "is_specialized(string) " <<numeric_limits<std::string>::is_specialized << endl;
  
  return 0;
}


