#include <iostream>
#include <memory>
#include <type_traits>

using namespace std;

template <typename T>
struct is_floatingpoint
{
  constexpr static bool value = false;
};

template <>
struct is_floatingpoint<float>
{
  constexpr static bool value = true;
};

template <>
struct is_floatingpoint<double>
{
  constexpr static bool value = true;
};

template <>
struct is_floatingpoint<long double>
{
  constexpr static bool value = true;
};

template<typename T>
struct DemoStatic
{
  static T value;
};

template<typename T>
T DemoStatic<T>::value = 0; // initialise static member

template<>
int DemoStatic<int>::value = 42; // specialization static member


// primary template declaration, not definition
template<typename T>
struct is_integralnumber;

// specialization can be done after primary template declaration
template<>
struct is_integralnumber<int>
{
  constexpr static bool value = true;
};

// primary template definition
template<typename T>
struct is_integralnumber
{
  constexpr static bool value = false;
};


template <typename>
struct SpecializationDecl {}; // primary template

template <>
struct SpecializationDecl<int>; // explicit specialization declaration

template <>
struct SpecializationDecl<int>
{};


template<typename T>
struct TemplateArg {};

template <typename T>
void func(TemplateArg<T>)
{
  std::cout << "func primary template\n";
}

template<>
void func<int>(TemplateArg<int>)
{
  std::cout << "func int specialization\n";  
}

template<typename T, typename U>
void func2arg(T a, U b)
{
  std::cout << "func2arg primary template\n";  
}

template<>
void func2arg<int,int>(int,int)
{
  std::cout << "func2arg int-int specialization\n";    
}

template<>
void func2arg<int,int>(int,double)
{
  std::cout << "func2arg int-double specialization\n";    
}

int main()
{
  std::cout << std::boolalpha;
  std::cout << is_floating_point<int>::value << '\n';
  std::cout << is_floating_point<float>::value << '\n';
  std::cout << is_floating_point<double>::value << '\n';
  std::cout << is_floating_point<long double>::value << '\n';
  std::cout << is_floating_point<std::string>::value << '\n';

  DemoStatic<double> a, b;
  DemoStatic<int> c;
  cout << a.value << endl;
  cout << b.value << endl;
  cout << c.value << endl;

  SpecializationDecl<double> sa; // OK
  SpecializationDecl<int>* sb; // OK
  SpecializationDecl<int> sc; // 

  return 0;
}
