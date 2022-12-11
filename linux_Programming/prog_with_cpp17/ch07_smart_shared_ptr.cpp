#include <thread>
#include <iostream>
#include <memory>

class myclass
{
  int m_data{0};
public:
  ~myclass()
  {
    std::cout << "myclass deleted\n";
  }
  void inc()
  { m_data++; }
};

std::thread t1;
std::thread t2;

void thread2(const std::shared_ptr<myclass> ptr)
{
  for (auto i = 0; i < 100000; i++) {
    ptr->inc();
  }
  std::cout << "thread2: complete\n";
}

void thread1()
{
  auto ptr = std::make_shared<myclass>();
  t2 = std::thread(thread2, ptr);
  for (auto i = 0; i < 10; i++) {
    ptr->inc();
  }
  std::cout << "thread1: complete\n";
}

int main()
{
  t1 = std::thread(thread1);
  t1.join();
  t2.join();

  {
    auto ptr1 = std::make_shared<int>();
    auto ptr2 = ptr1;
    std::cout << ptr1.get() << '\n';
    std::cout << ptr2.get() << '\n';
    ptr2.reset();
    std::cout << ptr1.get() << '\n';
    std::cout << ptr2.get() << '\n';
  }

  {
    auto ptr1 = std::make_shared<int>();
    auto ptr2 = ptr1;
    std::cout << ptr1.get() << '\n';
    std::cout << ptr2.get() << '\n';
    std::cout << ptr1.use_count() << '\n';
    ptr2.reset();
    std::cout << ptr1.get() << '\n';
    std::cout << ptr2.get() << '\n';
    std::cout << ptr1.use_count() << '\n';
  }

  {
    auto ptr = std::make_shared<int>();
    if (ptr) {
      std::cout << "before: " << ptr.get() << '\n';
    }
    ptr.reset();
    if (ptr) {
      std::cout << "after: "<< ptr.get() << '\n';
    }
  }

  {
    // shared pointer array in C++20
    auto ptr = std::make_shared<int[]>(5);
    for(int i = 0; i < 5; ++i)
      {
	ptr[i] = (i+1)*2;
	printf("ptr[%d]=%d\n", i , ptr[i]);
      }
  }

  return 0;
}
