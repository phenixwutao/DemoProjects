#include <iostream>
#include <iomanip>
#include <string>

#include <vector>
#include <map>

#include <memory> // smart pointers

#include <thread>
#include <mutex>
#include <shared_mutex>
#include <utility> // Date and time utilities
#include <atomic>

#include <chrono>

#include <cassert>
#include <csignal>

#include <condition_variable>

using namespace std;
using namespace std::chrono_literals;

std::map<string, int> telebook{{"Dijkastra", 1972},{"Scott", 1976},{"Ritchie", 1986}};
std::shared_timed_mutex teleBookMutex;

void addToTeleBook(const string& na, int tele)
{
  // write operation uses exclusive lock guard
  std::lock_guard<std::shared_timed_mutex> writerLock(teleBookMutex);
  cout << "Start update: " << na << '\n';
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  telebook[na] = tele;
  std::cout << "End update: " << na << '\n';
}

void PrintNumber(const string& na)
{
  // read operation uses shared mutex
  std::shared_lock<std::shared_timed_mutex> readerLock(teleBookMutex);
  auto search_it = telebook.find(na);
  if (search_it != telebook.end())
  {
    std::cout << search_it->first << " => " << search_it->second << '\n';
  }
  else
  {
    std::cout << na << " not found\n";
  }
}

int main(int argc, char *argv[])
{
  std::cout << std::boolalpha;
  std::thread reader1([]()
                      { PrintNumber("Scott"); });

  std::thread reader2([]()
                      { PrintNumber("Ritchie"); });

  std::thread reader3([]()
                      { PrintNumber("John"); });

  std::thread w1([]()
                 { addToTeleBook("Adam", 1980); });

  std::thread w2([]()
                 { addToTeleBook("Bjarne", 1965); });
  reader1.join();
  reader2.join();
  reader3.join();
  w1.join();
  w2.join();

  std::cout << "===> The new telebook:\n";
  for(auto& it : telebook)
    cout << it.first << " : " << it.second << '\n';
  cout << '\n';

  return 0;
}

