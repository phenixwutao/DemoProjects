#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

template<typename T>
class DynamicArray
{
private:
  T* data = nullptr;
  size_t n = 0;

public:
  DynamicArray()
  {
    data = nullptr;
    n = 0;
  }

  DynamicArray(int num) : n (num)
  {
    data = new T[n];
  }

  ~DynamicArray()
  {
    delete[] data;
    data = 0;
    n = 0;
  }

  DynamicArray(const DynamicArray<T>& rhs)
  {
    if (this == &rhs)
      return;

    if(data != nullptr) {
      delete[] data;
      data = nullptr;
      n = 0;
    }

    n = rhs.n;
    data = new T[n];
    for(int i = 0; i < n; ++i)
      { data[i] = rhs.data[i]; }
  }

  T& operator[](int index)
  {
    if (index >= 0 && index < n)
      return data[index];
    else
      throw "Index out of range";
  }

  const T& operator[](int index) const
  {
    if (index >= 0 && index < n)
      return data[index];
    else
      throw "Index out of range";
  }

  T& at(int index)
  {
    if (index >= 0 && index < n)
      return data[index];
    else
      throw "Index out of range";
  }

  size_t size() const
  {
    return n;
  }

  T* begin()
  { return data; }

  T* begin() const
  { return data; }

  T* end()
  { return data+n; }

  T* end() const
  { return data+n; }

  friend DynamicArray<T> operator+(const DynamicArray<T>& arr1, const DynamicArray<T>& arr2)
  {
    DynamicArray<T> results(arr1.size() + arr2.size());
    std::copy(arr1.begin(), arr1.end(), results.begin());
    std::copy(arr2.begin(), arr2.end(), results.begin()+arr1.size());
    return results;
  }

  std::string ToString(const std::string& sep = ",")
  {
    if ( n== 0) return "";

    std::ostringstream os;
    for(int i = 0; i < n; ++i)
    {
      if (i == 0 || i == n-1)
        os << data[i];
      else
        os << data[i] << sep;
    }
    return os.str();
  }
};

struct Student
{
  std::string name;
  int standard;
};

std::ostream& operator<<(std::ostream& os, const Student& s)
{
  os << "[Name: " << s.name <<", Standard: " << s.standard << "]";
  return os;
}

int main()
{
  const int num = 5;
  DynamicArray<Student> class1(num);
  for(int i=0; i < num; ++i)
  {
    std::string name = "class";
    name += to_string(i);
    class1[i] = Student{name, i+1};
  }

  DynamicArray<Student> class2 = class1;
  std::cout << class2.ToString() << '\n';

  auto class3 = class1 + class2;
  std::cout << class3.ToString() << '\n';
  return 0;
}
