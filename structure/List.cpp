/**
 * dynamic size, bidirectional
 * direct element access is NOT provided
 * constant time insertion and deletion of elements anywhere
 * all iterators available and invalidate when corresponding element is deleted
 */

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

class Person
{
  friend std::ostream &operator<<(std::ostream &os, const Person &p);
  std::string name;
  int age;

public:
  Person() : name{"Unknown"}, age{0} {}
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
void print(const std::list<T> &l)
{
  std::cout << "[ ";
  std::for_each(l.begin(), l.end(), [](auto x) { std::cout << x << " "; });
  std::cout << "]" << std::endl;
}

// push back/front
void test1()
{
  std::list<int> l1{1, 2, 3, 4, 5};
  print(l1);
  std::list<std::string> l2;
  l2.push_back("Back");
  l2.push_front("Front");
  print(l2);
  std::list<int> l3;
  l3 = {1, 2, 3};
  print(l3);
  std::list<int> l4(10, 100);
  print(l4);
}

void test2()
{
  std::list<int> l1{1, 2, 3, 4, 5};
  print(l1);
  std::cout << "Size: " << l1.size() << std::endl;
  std::cout << "Front: " << l1.front() << std::endl;
  std::cout << "Back: " << l1.back() << std::endl;

  l1.clear();
  print(l1);
  std::cout << "Size: " << l1.size() << std::endl;
}

// resize
void test3()
{
  std::list<int> l{1, 2, 3, 4, 5};
  print(l);
  l.resize(3);
  print(l);
  l.resize(5);
  print(l);

  std::list<Person> people;
  people.resize(3);
  print(people);
}

// std::find(iterator), std::advance, insert, erase
void test4()
{
  std::list<int> l{1, 2, 3, 5, 6, 7, 8, 9, 10};
  print(l);
  auto it = std::find(l.begin(), l.end(), 5);
  if (it != l.end())
  {
    l.insert(it, 4); // insert front
  }
  print(l);

  std::list<int> l2{100, 200, 300};
  l.insert(it, l2.begin(), l2.end());
  print(l);

  std::advance(it, -3); // 4
  std::cout << *it << std::endl;

  l.erase(it);
  print(l);
}

// emplace_front/back, emplace(before iterator, ...)
void test5()
{
  std::list<Person> names{
      {"Victor", 20}};
  print(names);
  std::string name{};
  int age{};
  std::cout << "Enter the name: " << std::endl;
  getline(std::cin, name);
  std::cout << "Enter the age: " << std::endl;
  std::cin >> age;

  names.emplace_back(name, age);
  print(names);

  auto it = std::find(names.begin(), names.end(), Person{"Victor", 20});
  if (it != names.end())
  {
    names.emplace(it, "Frank", 18);
  }
  print(names);
}

// sort
void test6()
{
  std::list<Person> names{
      {"Victor", 20},
      {"Rina", 18},
      {"Chen", 22}};
  print(names);
  names.sort();
  print(names);
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