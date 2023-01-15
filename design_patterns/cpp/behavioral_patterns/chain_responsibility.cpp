#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Handler
{
public:
  virtual ~Handler() = default;
  virtual Handler *SetNext(Handler *) = 0;
  virtual std::string Handle(std::string request) = 0;
};

class AbstractHandler : public Handler
{
private:
  Handler *next_handler_;

public:
  AbstractHandler() : next_handler_(nullptr){}
  Handler* SetNext(Handler* handler) override
  {
    this->next_handler_ = handler;
    return handler;
  }

  string Handle(string request) override
  {
    if (this->next_handler_)
      return next_handler_->Handle(request);

    return {};
  }
};


class MonkeyHandler : public AbstractHandler
{
  string Handle(string request) override
  {
    if (request == "Banana")
    {
      return "Monkey: will eat the " + request + ".\n";
    }
    else
    {
      return AbstractHandler::Handle(request);
    }
  }
};

class SquirrelHandler : public AbstractHandler
{
  string Handle(string request) override
  {
    if (request == "Nut")
    {
      return "Squirrel: will eat the " + request + ".\n";
    }
    else
    {
      return AbstractHandler::Handle(request);
    }
  }
};

class DogHandler : public AbstractHandler
{
  string Handle(string request) override
  {
    if (request == "MeatBall")
    {
      return "Squirrel: will eat the " + request + ".\n";
    }
    else
    {
      return AbstractHandler::Handle(request);
    }
  }
};

void ClientCode(Handler* hnd)
{
  vector<string> food = {"Nut","Banana","Coffee"};
  for(const auto& item: food)
  {
    cout << "who wants " << item.c_str() << " ?\n";
    const string result = hnd->Handle(item);
    if (!result.empty())
    {
      cout << "\t" << result;
    }
    else
    {
      cout << "\t" << item << " was left untouched.\n";
    }
  }
}

int main()
{
  MonkeyHandler *monkey = new MonkeyHandler;
  SquirrelHandler *squirrel = new SquirrelHandler;
  DogHandler *dog = new DogHandler;
  monkey->SetNext(squirrel)->SetNext(dog);
  cout << "chain: Money -> Squirrel -> Dog\n";
  ClientCode(monkey);

  cout << "chain: Squirrel -> Dog\n";
  ClientCode(squirrel);

  delete monkey;
  delete squirrel;
  delete dog;

  return EXIT_SUCCESS;
}
