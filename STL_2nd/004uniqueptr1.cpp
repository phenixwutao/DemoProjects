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

  std::unique_ptr<string> up1(new string("hello1"));
  unique_ptr<string> up2;
  up2 = std::move(up1);
  cout << "up2 is: " << *up2 << endl;

  // unique ptr with customised deleter: raw function pointer
  std::unique_ptr<int[],void(*)(int*) > up3(new int[10],
					 [](int* p) {
					   delete[] p;
					 });

  // unique ptr with customised deleter: use std::function<>
  std::unique_ptr<int[],std::function<void(int*)> > up4(new int[10],
						     [](int* p) {
						       delete[] p;
						     });
  up4[0] = 1;
  cout << up4[0] << endl;
  cout << up4[1] << endl;
  cout << up4[2] << endl;

  auto del = [](int* p) {delete[] p; }; // use lambda as deleter
  std:unique_ptr<int[], decltype(del)> up5(new int[10], del);
  cout << up5[0] << endl;
  cout << up5[1] << endl;
  cout << up5[2] << endl;
  
  return 0;  
}


