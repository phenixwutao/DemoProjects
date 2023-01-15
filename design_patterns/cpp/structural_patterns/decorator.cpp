#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Component
{
public:
  virtual ~Component() = default;
  virtual string Operation() const = 0;
};

class ConcreteComponent : public Component
{
  virtual string Operation() const override
  {
    return "ConcreteComponent";
  }
};

class Decorator : public Component
{
protected:
  Component* component_ = nullptr;

public:
  Decorator(Component *p) : component_(p) {}

  string Operation() const override
  {
    return component_->Operation();
  }
};

class ConcreteDecoratorA : public Decorator
{
public:
  ConcreteDecoratorA(Component* p) : Decorator(p) {}

  string Operation() const override
  {
    return "ConcreteDecoratorA(" + Decorator::Operation() + ")";
  }
};

class ConcreteDecoratorB : public Decorator
{
public:
  ConcreteDecoratorB(Component* p) : Decorator(p) {}

  string Operation() const override
  {
    return "ConcreteDecoratorB(" + Decorator::Operation() + ")";
  }
};


void ClientCode(Component* p)
{
  cout << "Result: " << p->Operation() << '\n';
}

int main()
{
  Component *comp = new ConcreteComponent;
  cout << "simple component:\n";
  ClientCode(comp);

  Component *decorator1 = new ConcreteDecoratorA(comp);
  Component *decorator2 = new ConcreteDecoratorB(decorator1);
  cout << "decorated component:\n";
  ClientCode(decorator2);

  delete comp;
  delete decorator1;
  delete decorator2;
  
  return 0;
}