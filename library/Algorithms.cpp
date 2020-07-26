#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>

class Person
{
  std::string name;
  int age;

public:
  Person() = default;
  Person(std::string name, int age) : name{name}, age{age} {}
  bool operator<(const Person &rhs) const
  {
    return this->age < rhs.age;
  }
  bool operator==(const Person &rhs) const
  {
    return (this->name == rhs.name && this->age == rhs.age);
  }
};

// find
void test1()
{
  std::vector<int> vec{3, 2, 1, 4, 5};
  auto loc = std::find(std::begin(vec), std::end(vec), 1);
  if (loc != std::end(vec))
  {
    std::cout << "Found the number: " << *loc << std::endl;
  }
  else
  {
    std::cout << "Not Found" << std::endl;
  }

  std::list<Person> players{
      {"Victor", 18},
      {"Chen", 20},
      {"Rina", 18}};
  auto lo = std::find(players.begin(), players.end(), Person{"Chen", 20});
  if (lo != players.end())
  {
    std::cout << "Found Chen" << std::endl;
  }
  else
  {
    std::cout << "Not Found" << std::endl;
  }
}

// count
void test2()
{
  std::vector<int> vec{1, 2, 3, 2, 2, 1, 2, 4, 4};
  int count1 = std::count(vec.begin(), vec.end(), 1);
  int count1_1 = std::count(vec.begin() + 1, vec.end(), 1);
  int count2 = std::count(vec.begin(), vec.end(), 2);
  int count4 = std::count(vec.begin(), vec.end(), 4);
  std::cout << "Occurrences found 1: " << count1 << std::endl;
  std::cout << "Occurrences found 1 after first index: " << count1_1 << std::endl;
  std::cout << "Occurrences found 2: " << count2 << std::endl;
  std::cout << "Occurrences found 4: " << count4 << std::endl;
}

// count_if
void test3()
{
  std::vector<int> vec{1, 2, 3, 4, 10, 8};
  int countEven = std::count_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
  std::cout << "even numbers found: " << countEven << std::endl;
  int countOdd = std::count_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 1; });
  std::cout << "odd numbers found: " << countOdd << std::endl;
}

// replace
void test4()
{
  std::vector<int> vec{1, 2, 3, 4, 5, 1, 2, 2};
  for (auto &i : vec)
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  std::replace(vec.begin(), vec.end(), 1, 100);
  for (auto &i : vec)
  {
    std::cout << i << " ";
  }
  std::cout << std::endl;
}

// all_of
void test5()
{
  std::vector<int> vec{1, 3, 5, 7, 9, 1, 3, 13, 19, 5};
  if (std::all_of(vec.begin(), vec.end(), [](int x) { return x > 10; }))
  {
    std::cout << "All the elements are > 10" << std::endl;
  }
  else
  {
    std::cout << "Not all the elements are > 10" << std::endl;
  }

  if (std::all_of(vec.begin(), vec.end(), [](int x) { return x < 20; }))
  {
    std::cout << "All the elements are < 20" << std::endl;
  }
  else
  {
    std::cout << "Not all the elements are < 20" << std::endl;
  }
}

// transform
void test6()
{
  std::string str{"This is a test"};
  std::cout << "Before transform: " << str << std::endl;
  std::transform(str.begin(), str.end(), str.begin(), ::toupper);
  std::cout << "After transform: " << str << std::endl;
}

int main()
{
  // test1();
  // test2();
  // test3();
  // test4();
  // test5();
  // test6();

  return 0;
}