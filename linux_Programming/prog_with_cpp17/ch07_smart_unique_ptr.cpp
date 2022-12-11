#include <iostream>
#include <memory>
using namespace std;

class mydeleter
{
public:
  void operator()(int *ptr) const
  {
  std::cout << "my delete " << ptr << "\n";
  delete ptr;
  };
};

template<typename T>
std::ostream& operator<<(std::ostream& os, std::unique_ptr<T>& ptr)
{
  os << ptr.get();
  return os;
}

int main()
{
  auto ptr1 = std::make_unique<int>(3);
  int val1 = *ptr1;
  cout << "ptr1 " << ptr1.get() << ", val1 " << val1<< ", ptr1 is "<< *ptr1<< endl;

  // unique pointer array template
  auto ptr2 = std::make_unique<int[]>(5);
  for(int i = 0; i < 5; ++i)
  {
    ptr2[i] = i*2+1;
    cout << "ptr2[" << i << "]= "<< ptr2[i] << endl; // works fine for build-in type
  }

  // customised deleter for unique pointer
  auto ptr3 = std::unique_ptr<int, mydeleter>(new int, mydeleter());
  cout << "ptr3 address: " << ptr3.get() << ", value "<< *ptr3 << endl;

  ptr3.reset(); // tells the unique pointer to release its memory on demand
  cout << "ptr3 address after reset: " << ptr3.get() << endl;

  printf("--------------- test reset and null pointer check\n");  
  auto ptr4 = std::unique_ptr<int, mydeleter>(new int, mydeleter());
  *ptr4 = 9;
  cout << "ptr4 address: " << ptr4.get() << ", value "<< *ptr4<< endl;
  ptr4.reset();
  if (ptr4)
    std::cout << *ptr4 << std::endl;

  printf("---------- test ostream insertion operator\n");
  auto ptr5 = std::make_unique<int>();
  cout << ptr5 << endl;
  cout << ptr5.get() << endl;
  return 0;
}
