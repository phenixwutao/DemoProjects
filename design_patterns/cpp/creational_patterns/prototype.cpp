// prototype
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
enum Type
{
  PROTOTYPE1 = 0,
  PROTOTYPE2
};

class Prototype
{
protected:
  std::string prototype_name;
  float prototype_field;

public:
  Prototype() {}
  Prototype(string name) : prototype_name(name) {}

  virtual ~Prototype() {}
  virtual Prototype *Clone() const = 0;
  virtual void Method(float val)
  {
    prototype_field = val;
    std::cout << "Method from " << prototype_name << " with field " << prototype_field << '\n';
  }
};

class ConcretePrototype1 : public Prototype
{
private:
  float prototype_field1;

public:
  ConcretePrototype1(string name, float field)
      : Prototype(name), prototype_field1(field)
  {
  }

  Prototype *Clone() const override
  {
    return new ConcretePrototype1(*this);
  }
};

class ConcretePrototype2 : public Prototype
{
private:
  float prototype_field2;

public:
  ConcretePrototype2(string name, float field)
      : Prototype(name), prototype_field2(field)
  {
  }

  Prototype *Clone() const override
  {
    return new ConcretePrototype2(*this);
  }
};

class PrototypeFactory
{
private:
  std::unordered_map<Type, Prototype *, std::hash<int>> prototypes;

public:
  PrototypeFactory()
  {
    prototypes[Type::PROTOTYPE1] = new ConcretePrototype1("Prototype 1", 50.0f);
    prototypes[Type::PROTOTYPE2] = new ConcretePrototype2("Prototype 2", 60.0f);
  }

  ~PrototypeFactory()
  {
    delete prototypes[Type::PROTOTYPE1];
    delete prototypes[Type::PROTOTYPE2];
  }

  Prototype* CreatePrototype(Type type)
  {
    return prototypes[type]->Clone();
  }
};

void ClientCode(PrototypeFactory& factory)
{
  cout << "prototype 1\n";
  Prototype *pro1 = factory.CreatePrototype(Type::PROTOTYPE1);
  pro1->Method(90);
  delete pro1;

  cout << "prototype 2\n";
  Prototype *pro2 = factory.CreatePrototype(Type::PROTOTYPE2);
  pro2->Method(10);
  delete pro2;
}

int main()
{
  PrototypeFactory *factory = new PrototypeFactory();
  ClientCode(*factory);
  delete factory;
  return 0;
}