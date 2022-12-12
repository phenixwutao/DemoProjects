#include <concepts>
#include <compare>
#include <string>

#include <forward_list>
#include <list>
#include <vector>
#include <unordered_set>
#include <iostream>

#include <type_traits>

using namespace std;

template<typename T>
struct isSemiRegular : 
  std::integral_constant<bool, 
    std::is_default_constructible<T>::value && 
    std::is_copy_constructible<T>::value &&
    std::is_copy_assignable<T>::value &&
    std::is_move_constructible<T>::value &&
    std::is_move_assignable<T>::value &&
    std::is_destructible<T>::value &&
    std::is_swappable<T>::value>
{
};


template<typename T>
concept SemiRegular = isSemiRegular<T>::value;

template<typename T>
concept Equal = requires (T a, T b)
{
  { a == b} -> std::convertible_to<bool>;
  { a != b} -> std::convertible_to<bool>;
};

template<typename T>
concept Regular = Equal<T> && SemiRegular<T>;

template<Regular T>
void behavesLikeInt(T a)
{
  cout << "Regular behavesLikeInt" << endl;
}

template<std::regular T>
void behavesLikeInt2(T a)
{
  cout << "regular behavesLikeInt2" << endl;
}

struct EqualityComparable {};
bool operator == (const EqualityComparable&, const EqualityComparable&)
{
  return true;
}

struct NotEqualityComparable {};

int main()
{
  int myInt {};
  behavesLikeInt(myInt);
  behavesLikeInt2(myInt);

  std::vector<int> myVec;
  behavesLikeInt(myVec);
  behavesLikeInt2(myVec);

  EqualityComparable equComp;
  behavesLikeInt(equComp);
  behavesLikeInt2(equComp);

  NotEqualityComparable notEquComp;
  //behavesLikeInt(notEquComp);  // compiler error
  //behavesLikeInt2(notEquComp); // compiler error

  return 0;
}
