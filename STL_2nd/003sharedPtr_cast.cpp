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

using namespace std;

int main()
{
  // static_pointer_cast<>
  // dynamic_pointer_cast<>
  // const_pointer_cast<>
  // reinterpret_pointer_cast<>
  
  shared_ptr<void> p1(new int);
  auto p2 = static_pointer_cast<int>(p1);
  cout << "p2=" << *p2 << endl;
  //auto p3 = std::dynamic_pointer_cast<int>(p1);
  //cout << "p3=" << *p3 << endl;

 return 0;  
}


