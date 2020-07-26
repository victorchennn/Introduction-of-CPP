/**
 * dynamic size, elements are stored in contiguous memory
 * constant time element access
 * constant time insertion and deletion at the back
 * linear time insertion and removal of elements
 * all iterators available and may invalidate
 */

#include <iostream>
#include <vector>
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
void print(const std::vector<T> &vec)
{
  std::cout << "[ ";
  // for (const auto &e : vec)
  // {
  //   std::cout << e << " ";
  // }
  std::for_each(vec.begin(), vec.end(), [](auto x) { std::cout << x << " "; });
  std::cout << "]" << std::endl;
}

// initialization
void test1()
{
  std::vector<int> vec1{1, 2, 3, 4, 5};
  print(vec1);
  std::vector<int> vec2(10, 100);
  print(vec2);
}

// size, max_size, capacity, shrink_to_fit, reserve
void test2()
{
  std::vector<int> vec{1, 2, 3, 4, 5};
  print(vec);
  std::cout << "size: " << vec.size() << std::endl;
  std::cout << "max size: " << vec.max_size() << std::endl;
  std::cout << "capacity: " << vec.capacity() << std::endl; // 5

  vec.push_back(6);
  print(vec);
  std::cout << "size: " << vec.size() << std::endl;
  std::cout << "max size: " << vec.max_size() << std::endl;
  std::cout << "capacity: " << vec.capacity() << std::endl; // 10

  vec.shrink_to_fit();
  print(vec);
  std::cout << "size: " << vec.size() << std::endl;
  std::cout << "max size: " << vec.max_size() << std::endl;
  std::cout << "capacity: " << vec.capacity() << std::endl; // 6

  vec.reserve(100);
  print(vec);
  std::cout << "size: " << vec.size() << std::endl;
  std::cout << "max size: " << vec.max_size() << std::endl;
  std::cout << "capacity: " << vec.capacity() << std::endl; // 100
}

// access
void test3()
{
  std::vector<int> vec{1, 2, 3, 4, 5};
  print(vec);
  vec[0] = 10;
  vec.at(1) = 200;
  print(vec);
}

// push_back, emplace_back
void test4()
{
  std::vector<Person> people;
  Person p1{"Victor", 10};
  people.push_back(p1);
  print(people);
  people.push_back(Person{"Chen", 11});
  print(people);
  people.emplace_back("Rina", 18);
  print(people);
}

// front, back, pop_back
void test5()
{
  std::vector<Person> names{
      {"Victor", 20},
      {"Chen", 21},
      {"Rina", 18}};
  print(names);
  std::cout << "Front: " << names.front() << std::endl;
  std::cout << "Back: " << names.back() << std::endl;
  names.pop_back();
  print(names);
  std::cout << "Front: " << names.front() << std::endl;
  std::cout << "Back: " << names.back() << std::endl;
}

// clear, begin/end iterator, erase
void test6()
{
  std::vector<int> vec{1, 2, 3, 4, 5};
  print(vec);
  vec.clear();
  print(vec);
  vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  auto it = vec.begin();
  while (it != vec.end())
  {
    if (*it % 2 == 0)
    {
      vec.erase(it);
    }
    else
    {
      it++;
    }
  }
  print(vec);
}

// swap
void test7()
{
  std::vector<int> vec1{1, 2, 3, 4};
  std::vector<int> vec2{6, 7, 8, 9, 10};
  print(vec1);
  print(vec2);
  std::cout << "swap: " << std::endl;
  vec1.swap(vec2);
  print(vec1);
  print(vec2);
}

// sort
void test8()
{
  std::vector<int> vec1{3, 4, 1, 2, 31, 44, 5, 100};
  print(vec1);
  std::sort(vec1.begin(), vec1.end());
  print(vec1);
}

// copy, copy_if, back_inserter(only back)
void test9()
{
  std::vector<int> vec1{1, 3, 5};
  std::vector<int> vec2{2, 4, 6};
  print(vec1);
  print(vec2);
  std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));
  print(vec1);
  print(vec2);
  std::cout << std::endl;

  vec1.push_back(8);
  vec2 = {2, 4, 6};
  print(vec1);
  print(vec2);
  std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2),
               [](int x) { return x % 2 == 0; });
  print(vec1);
  print(vec2);
}

// transfrom
void test10()
{
  std::vector<int> vec1{1, 3, 5};
  std::vector<int> vec2{10, 20};
  std::vector<int> vec3{10, 20, 30, 40};
  std::vector<int> vec4;

  std::transform(vec1.begin(), vec1.end(), vec2.begin(),
                 std::back_inserter(vec4),
                 [](int x, int y) { return x * y; });
  print(vec4); // [1*10, 3*20, 5*0]
  std::transform(vec1.begin(), vec1.end(), vec3.begin(),
                 std::back_inserter(vec4),
                 [](int x, int y) { return x * y; });
  print(vec4); // [10 60 0 10 60 150]
}

// find, insert
void test11()
{
  std::vector<int> vec1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> vec2{100, 200, 300};
  print(vec1);
  print(vec2);

  auto it = std::find(vec1.begin(), vec1.end(), 5);
  if (it != vec1.end())
  {
    std::cout << "inserting..." << std::endl;
    vec1.insert(it, vec2.begin(), vec2.end());
  }
  else
  {
    std::cout << "Not Found" << std::endl;
  }
  print(vec1);
}

int main()
{
  // test1();
  // test2();
  // test3();
  // test4();
  // test5();
  // test6();
  // test7();
  // test8();
  // test9();
  // test10();
  // test11();

  return 0;
}
