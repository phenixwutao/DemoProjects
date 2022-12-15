#include <iostream>
#include <utility>
#include <array>
#include <memory>
using namespace std;

struct MyObject {
  short ID;
  MyObject() : ID(0) {}
  MyObject(short id): ID (id) {}
  
  ~MyObject()
  {
    cout << "destructing MyObject " << ID << endl;
  }
};
int main() {

    std::cout << '\n';

    auto arr1 = std::to_array("A simple test");
    for (auto a: arr1) std::cout << a;
    std::cout << "\n\n";

    auto arr2 = std::to_array({1, 2, 3, 4, 5});
    for (auto a: arr2) std::cout << a;
    std::cout << "\n\n";

    auto arr3 = std::to_array<double>({0, 1, 3});
    for (auto a: arr3) std::cout << a;
    std::cout << '\n';
    std::cout << "typeid(arr3[0]).name(): " << typeid(arr3[0]).name() << '\n';
    std::cout << '\n';

    auto arr4 = std::to_array<std::pair<int, double>>({ {1, 0.0}, {2, 5.1}, {3, 5.1} });
    for (auto p: arr4) { 
        std::cout << "(" << p.first << ", " << p.second << ")" << '\n';
    }
    std::cout << "\n\n";

    // create 5 objects
    std::shared_ptr<MyObject[]> pobj1 = std::make_shared<MyObject[]>(5);
    
    // create 5 objects with initial value 1
    std::shared_ptr<MyObject[]> pobj2 = std::make_shared<MyObject[]>(5, 1.0);
    return 0;
}
