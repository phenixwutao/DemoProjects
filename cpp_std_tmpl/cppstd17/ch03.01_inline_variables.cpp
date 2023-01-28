#include <iostream>

#include <array>
#include <tuple>
#include <string>
#include <utility>

#include <map>

#include <atomic>
#include <thread>
using namespace std;

class MyClass
{
  public:
  inline static std::string message {"OK"}; // C++ 17
  static constexpr bool trace = false;
  static const bool fDone = false;
  inline static constexpr int Max = 5;
};

struct MyData
{
  inline static string gName = "global";
  inline static thread_local string tName = "thread_local";
  std::string lName = "local";
  void print(const string& msg) const
  {
    cout << msg << '\n';
    cout << "- gName " << gName << '\n';
    cout << "- tName " << tName << '\n';
    cout << "- lName " << lName << '\n';
  }
};
inline thread_local MyData myThreadData;

void foo()
{
  myThreadData.print("foo() begin:");
  myThreadData.gName = "thread2 name";
  myThreadData.tName = "thread2 name";
  myThreadData.lName = "thread2 name";
  myThreadData.print("foo() end:");
}

int main()
{
  myThreadData.print("main() begin:");
  myThreadData.gName = "thread1 name";
  myThreadData.tName = "thread1 name";
  myThreadData.lName = "thread1 name";
  myThreadData.print("main() later:");

  std::thread t1(foo);
  t1.join();
  myThreadData.print("main() end:");
  return 0;
}

