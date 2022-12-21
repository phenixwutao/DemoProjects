#include <iostream>
#include <memory>

using namespace std;

template<typename T, size_t Size>
class buffer
{
public:
  constexpr const T* data()
  { return data_; }

  constexpr T& operator[](const size_t index)
  {
    return data_[index];
  }

  constexpr const T& operator[](const size_t index) const
  {
    return data_[index];
  }

private:
  T data_[Size];
};


struct device
{
  virtual void output() = 0;
  virtual ~device() {}
};

using action_fn = void(*)();

template<action_fn actionfunc>
// template <void (*action)()>  // old style syntax
struct smart_device : public device
{
  virtual void output() override
  {
    //(*action)();
     actionfunc(); // call action function
  }
};


void say_hello_in_english()
{
  std::cout << "Hello, world!\n";
}
void say_hello_in_spanish()
{
  std::cout << "Hola mundo!\n";
}

int main()
{
  buffer<int, 10> b1;
  buffer<int, 2*5> b2;
  buffer<int, 15> b3;
  static_assert(std::is_same_v<decltype(b1), decltype(b2)>);
  static_assert(!std::is_same_v<decltype(b1), decltype(b3)>);

  auto w1 = std::make_unique<smart_device<say_hello_in_english>>();
  w1->output();

  auto w2 = std::make_unique<smart_device<say_hello_in_spanish>>();
  w2->output();

  smart_device<say_hello_in_english> w3;
  w3.output();
  smart_device<say_hello_in_spanish> w4;
  w4.output();
  return 0;
}