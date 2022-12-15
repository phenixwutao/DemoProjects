#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

#include <ranges> // range filter P233

using namespace std;

int main()
{
  std::map<std::string, int> freqWord{ {"witch", 25}, {"wizard", 33},
				       {"tale", 45}, {"dog", 4},
				       {"cat", 34}, {"fish", 23} };
  std::cout << "All words: ";
  for (const auto& name : std::views::keys(freqWord)) { std::cout << name << " "; }
  std::cout << '\n';

  
  std::cout << "All words, reverses: ";
  for (const auto& name : std::views::keys(freqWord) | std::views::reverse)
    { std::cout << name << " "; }
  std::cout << '\n';

  
  std::cout << "The first 4 words: ";
  for (const auto& name : std::views::keys(freqWord) | std::views::take(4))
    { std::cout << name << " "; }
  std::cout << '\n';

  std::cout << "All words starting with w: ";
  auto firstw = [](const std::string& name){ return name[0] == 'w'; };
  for (const auto& name : std::views::keys(freqWord) | std::views::filter(firstw))
    { std::cout << name << " "; }
  std::cout << '\n';
  
  return 0;
}
