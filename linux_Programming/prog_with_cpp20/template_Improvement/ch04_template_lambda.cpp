#include <concepts>

#include <string>
#include <forward_list>
#include <list>
#include <vector>
#include <unordered_set>

#include <iostream>

#include <type_traits>

#include <compare>

using namespace std;

// int type lambda
auto sumInt = [](int a, int b) { return a + b; };

// generic lambda
auto sumGen = [](auto a, auto b) { return a + b; };

// declare type lambda
auto sumDec = [](auto a, decltype(a) b) { return a + b; };

// template parameter lambda
auto sumTem = []<typename T>(T a, T b) { return a + b; };


// generic lambda
auto lambdaGeneric = [](const auto& container)
 {
   return container.size();
 };


// template vector lambda
auto lambdaVector = []<typename T>(const std::vector<T>& vec)
  {
    return vec.size();
  };

// concept template lambda
auto lambdaVectorIntegral = []<std::integral T>(const std::vector<T>& vec)
  {
    return vec.size();
  };


int main()
{
  cout <<std::boolalpha;
  cout << "sumInt(12, 13) " << sumInt(12, 13) << endl;
  cout << "sumGen(12, 13) " << sumGen(12, 13) << endl;
  cout << "sumDec(12, 13) " << sumDec(12, 13) << endl;
  cout << "sumTem(12, 13) " << sumTem(12, 13) << endl;

  string a = "hello ";
  string b = "world";
  cout << "sumGen(a, b) " << sumGen(a, b) << endl;
  cout << "sumDec(a, b) " << sumDec(a, b) << endl;
  cout << "sumTem(a, b) " << sumTem(a, b) << endl;

  cout << "sumInt(true, 13) " << sumInt(true, 13) << endl;
  cout << "sumGen(true, 13) " << sumGen(true, 13) << endl;
  cout << "sumDec(true, 13) " << sumDec(true, 13) << endl;
  
  return 0;
}
