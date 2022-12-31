#include <iostream>
#include <iomanip>

#include <thread>
#include <utility>
#include <atomic>

#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <functional>  // std::invoke
#include <chrono>
#include <variant>

using namespace std;
// https://timur.audio/talks

struct Person{
  string name;
  int Age;
};

struct __lambda__1 {
  inline bool operator()(const Person& lhs, const Person& rhs) const
  {
    return lhs.name < rhs.name;
  }

  // compiler deleted functions
  __lambda__1() = delete;                               // delete default constructor
  __lambda__1& operator=(const __lambda__1&) = delete;  // delete assigment operator
};


void legacy_call(int(*f)(int val))
{
  std::cout << f(7) << '\n';
}

using ms = std::chrono::milliseconds;
using us = std::chrono::microseconds;
using ns = std::chrono::nanoseconds;

struct Time
{
  std::variant<ms,ns> time;
  auto convert(const auto& converter)
  {
    return std::visit(converter, time);
  }
};

template<typename T>
constexpr auto duration_cast = [](auto d){
      return std::chrono::duration_cast<T>(d);
    };


template<typename T>
constexpr auto my_cast = [](auto x){ return (T)x; };


template<typename ... Ts>
struct overload : Ts...
{
  using Ts::operator()...;
};


class Widget {
public:
  // lambda as class member
  decltype([]{}) f; // compile ok with C++20
  int x;
};

template<typename T>
using MyPtr = std::unique_ptr<T, decltype([](T* t){MyDeletor(t);})>;

using WidgetSet = std::set<Widget, decltype([](Widget& lhs, Widget& rhs){
  return lhs.x < rhs.x;
})>;

int main(int argc, char *argv[])
{
  // lambda sort
  {
    vector<Person> people = {
      {"John", 23}, {"David", 35}, {"Rob", 28}, {"Mathew", 31}
    };

    // call __lambda__1();
    std::sort(people.begin(), people.end(), 
      [](const Person& lhs, const Person& rhs) {
        return lhs.name < rhs.name;
      });


    for (const auto& p : people)
      cout << p.name << ' ';
    cout << '\n';
  }

  {
    vector<Person> people = {
      {"John", 23}, {"David", 35}, {"Rob", 28}, {"Mathew", 31}
    };

    // call __lambda__1();
    std::sort(people.begin(), people.end(), 
      [](const Person& lhs, const Person& rhs) mutable // default is const
      {
        return lhs.name < rhs.name;
      });


    for (const auto& p : people)
      cout << p.name << ' ';
    cout << '\n';
  }

  {
    vector<Person> people = {
      {"John", 23}, {"David", 35}, {"Rob", 28}, {"Mathew", 31}
    };

    // lambda return type is deduced by the compiler
    std::sort(people.begin(), people.end(), 
      [](const Person& lhs, const Person& rhs) -> bool // return type bool
      {
        return lhs.name < rhs.name;
      });


    for (const auto& p : people)
      cout << p.name << ' ';
    cout << '\n';
  }

  {
    vector<Person> people = {
      {"John", 23}, {"David", 35}, {"Rob", 28}, {"Mathew", 31}
    };

    // call __lambda__1();
    std::sort(people.begin(), people.end(), 
      [](const Person& lhs, const Person& rhs) noexcept // const noexcept
      {
        return lhs.name < rhs.name;
      });


    for (const auto& p : people)
      cout << p.name << ' ';
    cout << '\n';
  }

  {
    // stateless lambda: implicitly conversion to function pointer
    legacy_call( [](int i){ return i*i; } );
  }

  {
    // unary plus trick
    auto* fptr = static_cast<int(*)(int)>( [](int i) {return i*i; } );
    auto* fptr2 = + [](int i) {return i*i; } ; // + will convert it into function pointer
  }

  {
    // lambda does not capture static/global variable by value, it access/changes its value
    static int i = 3;
    auto f = [](){ ++i; };
    f();
    cout << "sttaic i = " << i << '\n';
  }

  {
    constexpr int i =5;
    const int j = 5;
    // auto f = [](){ ++i; }; // compiler error
    // f();

    auto g = []{cout << j << '\n'; }; // constexpr int j
    g();
  }

  {
    // lambda immediately invoke
    [](){ cout << "hello lambda 1\n"; } () ; // call lambda function immediately
    std::invoke( [](){ cout << "hello lambda 2\n"; } );
  }

  {
    // call once lambda: static object is created only once
  }

  {
    // generic lambda with template: auto
    std::map<string,int> people = {{"John", 23}, {"David", 35}, {"Rob", 28}, {"Mathew", 31}};
    std::for_each (people.begin(), people.end(),
      [](const auto& item){
        cout << "Name: " << item.first << ", Age: " << item.second << ' ';
      });
    cout <<'\n';
  }

  {
    // forward
    std::vector<string> v;
    auto f = [&v](auto && item) {
      // Forward as lvalue or as rvalue
      v.push_back(std::forward<decltype(item)>(item));
    };
    f("John");
    f("Bob");
    f("Ken");
    for(auto& i : v)
      cout << i << ' ';
    cout << '\n';
  }

  {
    cout << "my_cast<int> " << my_cast<int>(3.14159) << '\n';
  }

  {
    Time t(ns(3000));
    // cout << t.convert(std::chrono::duration_cast<us>).count();
    cout << "duration_cast" << t.convert(duration_cast<us>).count()  << '\n';
  }

  {
  }

  {
    auto ptr = std::make_unique<Person>();

    // initialize capture: init capture optimisation
    auto f = [ptr=std::move(ptr)](){
      cout << ptr.get() << '\n';
    };
    f();
  }

  {
    // initialize capture: init capture optimisation, do not generate temp object in memory
    const std::vector<string> vs = {"Apple","Orange","Kiwi"};
    const std::string prefix = "Or";
    auto result = std::find_if(vs.begin(), vs.end(),
      [str = prefix + "ange" ](const string& s){
        return s == str;
      });
    if (result != vs.end())
      cout << prefix << " is found\n";
  }

  {
    auto f = []() constexpr { cout <<"constexpr lambda\n";};
    f();
  }

  {
    std::vector vec = {1,3,5,8,4};
  }

  {
    overload f = {
      [](int i)   { cout << "i= "<< i << '\n';},
      [](float f) { cout << "f= " <<f << '\n';}
    };
    f(1);
    f(2.3f);

    std::variant<int, float> v = 1.368f; // C++17 union
    std::visit(f, v);
  }

  {
    auto f1 = []{};
    auto f2 = []{};
    auto f3 = f1;
    decltype(f1) f4;
    decltype([]{}) f5;
    decltype([]{}) f6;
  }

  {
    // recursive lambda by using this : it does not compile?
    auto f = [](auto&& self, int i){
      if (i ==0)
        return 1;
      return i * self (self, i-1);
    };
    cout << "recursive lambda: " << f(f,5) << '\n';
  }

  {
  }

  return 0;
}

