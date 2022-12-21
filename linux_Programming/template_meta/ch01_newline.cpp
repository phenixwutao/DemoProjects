#include <iostream>

using namespace std;

template<typename T>
constexpr T NewLine = T('\n');

int main()
{
  std::wstring test = L"demo";
  test += NewLine<wchar_t>;
  wcout << test << endl;
  return 0;
}