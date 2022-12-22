#include <iostream>
#include <memory>
#include <type_traits>
#include <array>

using namespace std;

template<typename T>
constexpr T PI = T(3.1415926535897932385L);

template<typename T>
T sphere_volume(const T& r)
{
  return 4 * PI<T> * r * r *r / 3;
}

struct math_constants
{
  template<typename T>
  constexpr static T PI = T(3.1415926535897932385L);
};

template<typename T>
T sphere_vol(const T& radius)
{
  return 4 * math_constants::PI<T> * radius * radius * radius / 3 ;
}

struct math_Kconstants
{
  template<typename T>
  const static T PI;
};

// initialize const static variable outside of class
template<typename T>
const T math_Kconstants::PI = T(3.1415926535897932385L);

int main()
{
  auto vol = sphere_volume<int>(3);
  std::cout << "vol = " << vol << '\n';

  auto vol2 = sphere_volume<double>(3.0);
  std::cout << "vol2 = " << vol2 << '\n';
  std::cout <<'\n';
  return 0;
}
