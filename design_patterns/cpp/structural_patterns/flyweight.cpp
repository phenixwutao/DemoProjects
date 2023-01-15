#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct SharedState
{
  string brand_;
  string model_;
  string color_;

  SharedState(string brand, string model, string color)
      : brand_(brand), model_(model), color_(color)
  {
  }

  friend ostream &operator<<(ostream &os, const SharedState &ss)
  {
    os << "[" << ss.brand_ << " , "
       << ss.model_ << " , "
       << ss.color_ << "]";
    return os;
  }
};

struct UniqueState
{
  string owner_;
  string plates_;
  UniqueState(string owner, string plates) : owner_(owner), plates_(plates)
  {
  }
  friend ostream &operator<<(ostream &os, const UniqueState &us)
  {
    os << "[" << us.owner_ << " , " << us.plates_ << "]";
    return os;
  }
};

class FlyWeight
{
private:
  SharedState *shared_state_ = nullptr;

public:
  // constructor with deep copy
  FlyWeight(const SharedState *ss) : shared_state_(new SharedState(*ss))
  {
  }

  // copy constructor with deep copy
  FlyWeight(const FlyWeight &rhs) : shared_state_(new SharedState(*rhs.shared_state_))
  {
  }

  ~FlyWeight()
  {
    delete shared_state_;
  }

  SharedState *shared_state() const
  {
    return shared_state_;
  }

  void Operation(const UniqueState &us) const
  {
    std::cout << "Flyweight: Displaying shared (" << *shared_state_ << ") and unique ("
              << us << ") state.\n";
  }
};

class FlyWeightFactory
{
private:
  std::unordered_map<string, FlyWeight> flyweights_;
  string GetKey(const SharedState &ss) const
  {
    return ss.brand_ + "_" + ss.model_ + "_" + ss.color_;
  }

public:
  FlyWeightFactory(std::initializer_list<SharedState> share_states)
  {
    for (const auto &ss : share_states)
    {
      this->flyweights_.insert(std::make_pair<string, FlyWeight>(this->GetKey(ss), FlyWeight(&ss)));
    }
  }

  FlyWeight GetFlyWeight(const SharedState &ss)
  {
    auto key = GetKey(ss);
    if (flyweights_.find(key) == flyweights_.end())
    {
      cout << "FlyWeightFactory Cannot find a flyweight, create a new one\n";
      flyweights_.insert(std::make_pair(key, FlyWeight(&ss)));
    }
    else
    {
      cout << "FlyWeightFactory: reuse existing flyweight\n";
    }
    return flyweights_.at(key);
  }

  void ListFliWeights() const
  {
    auto count = flyweights_.size();
    cout << "FlyWeightFactory has " << count << " flyweights";
    for (const auto &it : flyweights_)
    {
      cout << it.first << '\n';
    }
  }
};

void AddCarToPoliceDB(FlyWeightFactory &fac,
                      const string &plates,
                      const string &owner,
                      const string &brand,
                      const string &model,
                      const string &color)
{
  cout << "Client adding car to database\n";
  const auto &flyw = fac.GetFlyWeight({brand, model, color});
  flyw.Operation({owner, plates});
}

int main()
{
  FlyWeightFactory *factory = new FlyWeightFactory({{"Chevrolet", "Camaro2018", "pink"},
                                                    {"Mercedes Benz", "C300", "black"},
                                                    {"Mercedes Benz", "C500", "red"},
                                                    {"BMW", "M5", "red"},
                                                    {"BMW", "X6", "white"}});
  factory->ListFliWeights();

  AddCarToPoliceDB(*factory,
                         "CL234IR",
                         "James Doe",
                         "BMW",
                         "M5",
                         "red");

  AddCarToPoliceDB(*factory,
                         "CL234IR",
                         "James Doe",
                         "BMW",
                         "X1",
                         "red");
  factory->ListFliWeights();
  delete factory;
  return EXIT_SUCCESS;
}
