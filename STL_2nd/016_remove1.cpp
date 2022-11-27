#include <iostream>

#include <array>
#include <vector>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <forward_list>

#include <iterator>

#include <memory> // smart pointers

#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <future>

#include <climits> // old number limit
#include <cfloat>  // old float limit
#include <limits> // C++11 limit header

#include <functional> // ref wrapper std::ref()

#include <algorithm> // utility function min, max

#include <utility> // relation operations rel_ops

#include <chrono> // time and clocks

using namespace std;

int main()
{
  // example 1
  list<int> coll;
  for(int i=1; i <=6; ++i)
    {
      coll.push_front(i);
      coll.push_back(i);
    }
  
  printf("1 before remove\n");

  copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  remove(coll.begin(), coll.end(), 3);
  printf("1 after remove\n");
  copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  
  // example 2
  list<int> coll2;
  for(int i=1; i <=6; ++i)
    {
      coll2.push_front(i);
      coll2.push_back(i);
    }
  
  printf("2 before remove\n");

  copy(coll2.begin(), coll2.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  // get the new end iterator
  list<int>::iterator itend = remove(coll2.begin(), coll2.end(), 3);
  printf("2 after remove\n");
  copy(coll2.begin(), itend, ostream_iterator<int>(cout, " "));
  cout << endl;

  cout << "check distance " <<distance(itend, coll2.end()) << endl;
  coll2.erase(itend, coll2.end());

  printf("2 after erase\n");
  copy(coll2.begin(), coll2.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  
  // example 3
  list<int> coll3;
  for(int i=1; i <=6; ++i)
    {
      coll3.push_front(i);
      coll3.push_back(i);
    }
  
  printf("3 before remove\n");
  copy(coll3.begin(), coll3.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  coll3.erase(remove(coll3.begin(), coll3.end(), 3), coll3.end());

  printf("3 after remove\n");
  copy(coll3.begin(), coll3.end(), ostream_iterator<int>(cout, " "));
  cout << endl;

  return 0;
}


