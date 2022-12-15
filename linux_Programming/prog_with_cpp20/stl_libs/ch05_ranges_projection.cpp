#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

#include <ranges> // range filter P233

using namespace std;

struct PhoneBookEntry
{
  std::string name;
  int number;
};

void printPhoneBook(const std::vector<PhoneBookEntry>& phoneBook)
{
  for (const auto& entry: phoneBook)
    std::cout << "(" << entry.name << ", " << entry.number << ")";
  std::cout << "\n\n";
}

int main()
{
  std::cout << '\n';
  std::vector<PhoneBookEntry> phoneBook{
    {"Brown", 111}, {"Smith", 444},
    {"Grimm", 666}, {"Butcher", 222},
    {"Taylor", 555}, {"Wilson", 333}};
 
  std::ranges::sort(phoneBook, {}, &PhoneBookEntry::name); // ascending by name
  printPhoneBook(phoneBook);
  
  std::ranges::sort(phoneBook, std::ranges::greater() ,
		    &PhoneBookEntry::name); // descending by name
  printPhoneBook(phoneBook);

  std::ranges::sort(phoneBook, {}, &PhoneBookEntry::number); // ascending by number
  printPhoneBook(phoneBook);
  
  std::ranges::sort(phoneBook, std::ranges::greater(),
		    &PhoneBookEntry::number); // descending by number
  printPhoneBook(phoneBook);
  std::cout << '\n';   
  return 0;
}
