#include <iostream>

#include <array>
#include <tuple>
#include <string>
#include <utility>

#include <map>
#include <thread>
#include <chrono>
using namespace std;

class Data {
private:
  string name;

public:
  Data(const string &s) : name(s)
  {}

  auto startThreadWithCopyThis() const
  {
    using namespace std::literals;
    std::thread t([*this](){
      std::this_thread::sleep_for(3s);
      cout << name << '\n';
    });
    return t;
  }
};

int main()
{
  std::thread t;
  {
    Data d{"c1"};
    t = d.startThreadWithCopyThis();
  }
  t.join();
  
  return 0;
}

