#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Implementation
{
public:
  virtual ~Implementation() = default;
  virtual std::string OperationImpl() const = 0;
};

class ConcreteImplementationA : public Implementation
{
  std::string OperationImpl() const override
  {
    return "ConcreteImplemntationA on platform A";
  }
};

class ConcreteImplementationB : public Implementation
{
  std::string OperationImpl() const override
  {
    return "ConcreteImplemntationB on platform B";
  }
};

class Abstraction
{
protected:
  Implementation *impl_;

public:
  Abstraction(Implementation *imp) : impl_(imp) {}
  virtual ~Abstraction() {}

  virtual std::string Operation() const
  {
    return "Abstraction: base operation with:\n" + this->impl_->OperationImpl();
  }
};

class ExtendedAbstraction : public Abstraction
{
  public:
  ExtendedAbstraction(Implementation* imp) : Abstraction(imp)
  {}

  std::string Operation() const override
  {
    return "ExtendedAbstraction: Extended operation with:\n" + this->impl_->OperationImpl();
  }
};

void ClientCode(const Abstraction* abs)
{
  std::cout << abs->Operation() << '\n';
}

int main()
{
  Implementation *imp = new ConcreteImplementationA();
  Abstraction *abs = new Abstraction(imp);
  ClientCode(const_cast<const Abstraction*>(abs));
  delete imp;
  delete abs;

  imp = new ConcreteImplementationB();
  abs = new ExtendedAbstraction(imp);
  ClientCode(const_cast<const Abstraction*>(abs));
  delete imp;
  delete abs;
  
  return 0;
}