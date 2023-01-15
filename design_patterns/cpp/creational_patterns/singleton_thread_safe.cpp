#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <syncstream>
#include <mutex>

using namespace std;
using namespace std::chrono_literals;

class Singleton
{
protected:
  Singleton(const string &val) : value_(val) {}
  std::string value_;
  static Singleton *singleton_;
  static std::mutex mutex_;

public:
  Singleton(const Singleton &) = delete;
  Singleton &operator=(const Singleton &) = delete;
  static Singleton *GetInstance(const string &val);
  static void DestroyInstance();

  void SomeBusinessLogic()
  {
  }

  std::string value() const
  {
    return value_;
  }
};

Singleton* Singleton::singleton_ = nullptr;
std::mutex Singleton::mutex_;

Singleton* Singleton::GetInstance(const string& val)
{
  std::lock_guard<std::mutex> lock(mutex_);
  if (singleton_ == nullptr)
  {
    singleton_ = new Singleton(val);
  }
  return singleton_;
}

void Singleton::DestroyInstance()
{
  if (singleton_ != nullptr)
  {
    delete singleton_;
    singleton_ = nullptr;
  }
}

void ThreadFoo()
{
  std::this_thread::sleep_for(1s);
  auto sig1 = Singleton::GetInstance("Foo");
  std::osyncstream {cout} << "singleton address: " << sig1 << ", value: "<< sig1->value() << endl;
}

void ThreadBar()
{
  std::this_thread::sleep_for(1s);
  auto sig2 = Singleton::GetInstance("Bar");
  std::osyncstream {cout} << "singleton address: " << sig2 << ", value: "<< sig2->value() << endl;
}

int main()
{
  std::thread t1(ThreadFoo);
  std::thread t2(ThreadBar);
  t1.join();
  t2.join();
  Singleton::DestroyInstance();
  return 0;
}
