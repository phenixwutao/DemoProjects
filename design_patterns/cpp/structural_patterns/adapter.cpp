#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Target
{
public:
  virtual ~Target() = default;
  virtual std::string Request() const
  {
    return "Target: the default target's behavior.";
  }
};

class Adaptee
{
public:
  std::string SpecificRequest() const
  {
    return ".eetpadA eht fo roivaheb laicepS";
  }
};

class Adapter : public Target
{
private:
  Adaptee* adaptee_ = nullptr;

public:
  Adapter(Adaptee *tee) : adaptee_(tee){}
  std::string Request() const
  {
    string to_reverse = adaptee_->SpecificRequest();
    std::reverse(to_reverse.begin(), to_reverse.end());
    return "Adapter: (Translated) " + to_reverse;
  }
};

void ClientCode(const Target* target)
{
  cout << target->Request() << '\n';
}

int main()
{
  Target *target = new Target();
  ClientCode(target);

  Adaptee *adaptee = new Adaptee();
  cout << "Adaptee: " << adaptee->SpecificRequest() << '\n';

  Adapter *adapter = new Adapter(adaptee);
  ClientCode(adapter);
  
  delete target;
  delete adaptee;
  delete adapter;

  return 0;
}