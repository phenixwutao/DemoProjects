#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Subject
{
public:
  virtual ~Subject() = default;
  virtual void Request() const = 0;
};

class RealSubject : public Subject
{
public:
  virtual void Request() const
  {
    cout << "RealSubject handling request\n";
  }
};

class Proxy : public Subject
{
private:
  RealSubject* real_subject;

  bool CheckAccess() const
  {
    cout << "Proxy: check access prior to firing a real subject\n";
    return true;
  }

  void LogAccess() const
  {
    cout << "Proxy: logging the time of request\n";
  }

public:
  Proxy(RealSubject *sub) : real_subject(new RealSubject(*sub))
  {
  }

  ~Proxy()
  {
    delete this->real_subject;
  }

  void Request() const override
  {
    if (CheckAccess() == true)
    {
      real_subject->Request();
      LogAccess();
    }
  }
};

void ClientCode(const Subject& subject)
{
  subject.Request();
}

int main()
{
  cout << "Client: executing the client code with a real subject:\n";
  RealSubject *real_sub = new RealSubject;
  ClientCode(*real_sub);
  cout <<'\n';

  cout << "Client: executing the client code with a proxy:\n";
  Proxy* proxy = new Proxy(real_sub);
  ClientCode(*proxy);

  delete real_sub;
  delete proxy;

  return 0;
}