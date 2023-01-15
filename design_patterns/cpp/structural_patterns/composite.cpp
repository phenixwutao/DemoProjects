#include <iostream>
#include <string>
#include <algorithm>
#include <list>
using namespace std;

class Component
{
protected:
  Component *parent_;

public:
  virtual ~Component() = default;

  void SetParent(Component *p)
  {
    this->parent_ = p;
  }
  Component *GetParent() const
  {
    return parent_;
  }

  virtual void Add(Component*) {}
  virtual void Remove(Component*) {}
  virtual bool IsComposite() const { return false; }
  virtual string Operation() const = 0;
};

class Leaf : public Component
{
public:
  string Operation() const override
  {
    return "Leaf";
  }
};

class Composite : public Component
{
protected:
  std::list<Component *> children_;

public:
  virtual void Add(Component *p) override
  {
    this->children_.push_back(p);
    p->SetParent(this);
  }

  virtual void Remove(Component* p) override
  {
    children_.remove(p);
    p->SetParent(nullptr);
  }

  virtual bool IsComposite() const override
  {
    return true;
  }

  string Operation() const override
  {
    std::string result;
    for(const auto* p : children_)
    {
      if (p == children_.back())
      {
        result += p->Operation();
      }
      else
      {
        result += p->Operation() + "+";
      }
    }
    return "Branch(" + result + ")";
  }
};

void ClientCode(Component* p)
{
  cout << p->Operation() << '\n';
}

void ClientCode2(Component* c1, Component* c2)
{
  if (c1->IsComposite())
  {
    c1->Add(c2);
  }
  cout << "Result: " << c1->Operation() << '\n';
}

int main()
{
  Component *simple = new Leaf;
  cout << "Simple component\n";
  ClientCode(simple);

  Component* tree = new Composite;
  Component* branch1 = new Composite;
  Component* leaf1 = new Leaf;
  Component* leaf2 = new Leaf;
  Component* leaf3 = new Leaf;

  branch1->Add(leaf1);
  branch1->Add(leaf2);

  Component *branch2 = new Composite;
  branch2->Add(leaf3);

  tree->Add(branch1);
  tree->Add(branch2);
  cout << "Now we have a compiste tree:\n";
  ClientCode(tree);
  cout << "\n\n";

  cout << "Client: I don't need to check the components classes even when managing the tree:\n";
  ClientCode2(tree, simple);

  // free resources
  delete simple;
  delete tree;
  delete branch1;
  delete branch2;
  delete leaf1;
  delete leaf2;
  delete leaf3;

  return 0;
}