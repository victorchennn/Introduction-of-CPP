#include <iostream>
#include <set>
#include <algorithm>

class Person
{
  friend std::ostream &operator<<(std::ostream &os, const Person &p);
  std::string name;
  int age;

public:
  Person() = default;
  Person(std::string name, int age) : name{name}, age{age} {}
  bool operator<(const Person &rhs) const { return this->age < rhs.age; }
  bool operator==(const Person &rhs) const { return this->name == rhs.name && this->age == rhs.age; }
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
  os << p.name << ":" << p.age;
  return os;
}

template <typename T>
void print(const std::set<T> &s)
{
  std::cout << "[ ";
  std::for_each(s.begin(), s.end(), [](auto x) { std::cout << x << " "; });
  std::cout << "]" << std::endl;
}

// initialization, insert, count, find(pointer iterator), clear
void test1()
{
  std::set<int> s1{1, 4, 3, 5, 2};
  print(s1);
  s1 = {2, 1, 2, 4, 2, 1, 1, 3, 4, 5, 4, 2, 2, 3, 3};
  print(s1);

  s1.insert(0);
  s1.insert(10);
  print(s1);
  if (s1.count(10))
  {
    std::cout << "contains 10" << std::endl;
  }

  auto it = s1.find(3);
  if (it != s1.end())
  {
    std::cout << "Found: " << *it << std::endl;
  }
  s1.clear();
  print(s1);
}

// emplace, find, erase
void test2()
{
  std::set<Person> people{
      {"Victor", 12},
      {"Rina", 18},
      {"Chen", 20}};
  print(people);
  people.emplace("Luo", 16);
  print(people);
  people.emplace("Victor", 12);
  print(people);

  auto it = people.find(Person{"Victor", 12});
  if (it != people.end())
  {
    people.erase(it);
  }
  print(people);

  it = people.find(Person{"XXX", 20}); // will remove Chen:20, uses < operator
  if (it != people.end())
  {
    people.erase(it);
  }
  print(people);
}

// insert returns std::pair<iterator, bool>
// first is an iterator to the inserted element or to the duplicate
// second is a boolean indicating success or failure
void test3()
{
  std::set<std::string> s{"A", "B", "C"};
  print(s);
  auto it = s.insert("V");
  print(s);

  std::cout << std::boolalpha;
  std::cout << "first: " << *(it.first) << std::endl;
  std::cout << "second: " << it.second << std::endl;

  it = s.insert("A");
  print(s);
  std::cout << "first: " << *(it.first) << std::endl;
  std::cout << "second: " << it.second << std::endl;
}

int main()
{
  // test1();
  // test2();
  // test3();

  return 0;
}
