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

template<typename Command, void(Command::*action)()>
struct smart_device : public device
{
public:
  smart_device(Command& cm) : cmd (cm) {}

  virtual void output() override
  {
    (cmd.*action)();
  }
private:
  Command& cmd;
};

struct smart_command
{
  void say_hello_in_english()
  {
    std::cout << "Hello, world!\n";
  }

  void say_hello_in_spanish()
  {
    std::cout << "Hola mundo!\n";
  }
};

int main()
{
  smart_command cmd;
  auto w1 = smart_device<smart_command, &smart_command::say_hello_in_english>(cmd);
  w1.output();

  auto w2 = smart_device<smart_command, &smart_command::say_hello_in_spanish>(cmd);
  w2.output();
  return 0;
}