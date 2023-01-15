#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Subsystem1
{
public:
  string operation1() const
  {
    return "Subsystem1 ready\n";
  }

  string operationN() const
  {
    return "Subsystem1 GO\n";
  }
};

class Subsystem2
{
public:
  string operation1() const
  {
    return "Subsystem2 Get ready\n";
  }

  string operationZ() const
  {
    return "Subsystem2 Fire\n";
  }
};

class Facade
{
protected:
  Subsystem1 *subsystem1;
  Subsystem2 *subsystem2;

public:
  Facade(Subsystem1 *sub1 = nullptr, Subsystem2 *sub2 = nullptr)
  {
    subsystem1 = sub1 ? sub1 : new Subsystem1;
    subsystem2 = sub2 ? sub2 : new Subsystem2;
  }

  ~Facade()
  {
    delete subsystem1;
    delete subsystem2;
  }

  string Operation()
  {
    std::string result = "Facade initializes subsystems:\n";
    result += this->subsystem1->operation1();
    result += this->subsystem2->operation1();
    result += "Facade orders subsystems to perform the action:\n";
    result += this->subsystem1->operationN();
    result += this->subsystem2->operationZ();
    return result;
  }
};

void ClientCode(Facade *fac)
{
  cout << fac->Operation() << '\n';
}

int main()
{
  Subsystem1* sub1 = new Subsystem1;
  Subsystem2* sub2 = new Subsystem2;
  Facade *fac = new Facade(sub1, sub2);
  ClientCode(fac);
  delete fac;

  return EXIT_SUCCESS;
}