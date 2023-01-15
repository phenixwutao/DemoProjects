#include <iostream>
#include <string>
using namespace std;

class IProduct
{
public:
  virtual ~IProduct() = default;
  virtual std::string Operation() const = 0;
};

class ConcreteProduct1 : public IProduct
{
  std::string Operation() const override
  {
    return "{results of ConcreteProduct1}";
  }
};

class ConcreteProduct2 : public IProduct
{
  std::string Operation() const override
  {
    return "{results of ConcreteProduct2}";
  }
};

class Creator
{
  public:
    virtual ~Creator() = default;
    virtual IProduct *factoryMethod() const = 0;

    std::string SomeOperation() const 
    {
    auto product = this->factoryMethod();
    auto result = "Creator: The same creator's code has just worked with " + product->Operation();
    delete product;
    return result;
    }
};

class ConcreteCreator1 : public Creator
{
  public:
  IProduct* factoryMethod() const override
  {
    return new ConcreteProduct1();
  }
};

class ConcreteCreator2 : public Creator
{
  public:
  IProduct* factoryMethod() const override
  {
    return new ConcreteProduct2();
  }
};

void ClientCode(const Creator& creator)
{
  std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
            << creator.SomeOperation() << std::endl;
}

int main()
{
  std::cout << "App: Launched with the ConcreteCreator1.\n";
  Creator *creator = new ConcreteCreator1();
  ClientCode(*creator);
  std::cout << std::endl;

  std::cout << "App: Launched with the ConcreteCreator2.\n";
  Creator *creator2 = new ConcreteCreator2();
  ClientCode(*creator2);

  delete creator;
  delete creator2;
  return 0;
}