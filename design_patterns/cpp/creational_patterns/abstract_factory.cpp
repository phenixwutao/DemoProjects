#include <iostream>
#include <string>
using namespace std;

class AbstractProductA
{
public:
  virtual ~AbstractProductA() = default;
  virtual string FunctionA() const = 0;
};

class ConcreteProductA1 : public AbstractProductA
{
public:
  string FunctionA() const override
  {
    return "FunctionA from ConcreteProductA1";
  }
};

class ConcreteProductA2 : public AbstractProductA
{
public:
  string FunctionA() const override
  {
    return "FunctionA from ConcreteProductA2";
  }
};

class AbstractProductB
{
public:
  virtual ~AbstractProductB() = default;
  virtual string FunctionB() const = 0;
  virtual std::string AnotherFunctionB(const AbstractProductA &collaborator) const = 0;
};

class ConcreteProductB1 : public AbstractProductB
{
public:
  string FunctionB() const override
  {
    return "FunctionB from ConcreteProductB1";
  }

  string AnotherFunctionB(const AbstractProductA &collaborator) const override
  {
    auto result = collaborator.FunctionA();
    return "B1 in collaborating with (" + result + ")";
  }
};

class ConcreteProductB2 : public AbstractProductB
{
public:
  string FunctionB() const override
  {
    return "FunctionB from ConcreteProductB2";
  }

  string AnotherFunctionB(const AbstractProductA &collaborator) const override
  {
    auto result = collaborator.FunctionA();
    return "B2 in collaborating with (" + result + ")";
  }
};

class AbstractFactory
{
public:
  virtual ~AbstractFactory() = default;
  virtual AbstractProductA *createfactoryA() const = 0;
  virtual AbstractProductB *createfactoryB() const = 0;
};

class ConcreteFactory1 : public AbstractFactory
{
public:
  AbstractProductA *createfactoryA() const override
  {
    return new ConcreteProductA1();
  }

  AbstractProductB *createfactoryB() const override
  {
    return new ConcreteProductB1();
  }
};

class ConcreteFactory2 : public AbstractFactory
{
public:
  AbstractProductA *createfactoryA() const override
  {
    return new ConcreteProductA2();
  }

  AbstractProductB *createfactoryB() const override
  {
    return new ConcreteProductB2();
  }
};

void ClientCode(const AbstractFactory &factory)
{
  const AbstractProductA *product_a = factory.createfactoryA();
  const AbstractProductB *product_b = factory.createfactoryB();
  cout << product_b->FunctionB() << '\n';
  cout << product_b->AnotherFunctionB(*product_a) << '\n';
  delete product_a;
  delete product_b;
}

int main()
{
  cout << "test ConcreteFactory1\n";
  ConcreteFactory1 *f1 = new ConcreteFactory1();
  ClientCode(*f1);
  delete f1;

  cout << "test ConcreteFactory2\n";
  ConcreteFactory2 *f2 = new ConcreteFactory2();
  ClientCode(*f2);
  delete f2;
  return 0;
}
