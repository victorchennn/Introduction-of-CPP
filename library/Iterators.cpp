#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

void display(const std::vector<int> &vec)
{
  std::cout << "[ ";
  for (auto const &i : vec)
  {
    std::cout << i << " ";
  }
  std::cout << "]" << std::endl;
}

void test1()
{
  std::vector<int> num1{1, 2, 3, 4, 5};
  auto it = num1.begin();
  std::cout << *it << std::endl; // 1
  it++;
  std::cout << *it << std::endl; // 2
  it += 2;
  std::cout << *it << std::endl; // 4
  it -= 3;
  std::cout << *it << std::endl; // 1
  it = num1.end() - 1;
  std::cout << *it << std::endl; // 5
}

void test2()
{
  std::vector<int> num1{1, 2, 3, 4, 5};
  std::vector<int>::iterator it = num1.begin();
  while (it != num1.end())
  {
    std::cout << *it << std::endl;
    it++;
  }
  it = num1.begin();
  while (it != num1.end())
  {
    *it = 0;
    it++;
  }
  display(num1);
}

void test3()
{
  std::vector<int> num1{1, 2, 3, 4, 5};
  std::vector<int>::const_iterator it1 = num1.begin();
  // auto it1 = num1.cbegin();

  while (it1 != num1.end())
  {
    std::cout << *it1 << std::endl;
    // *it1 = 0; // error, read-only
    it1++;
  }
}

void test4()
{
  std::vector<int> vec{1, 2, 3, 4, 5};
  auto it1 = vec.rbegin();
  while (it1 != vec.rend())
  {
    std::cout << *it1 << std::endl;
    it1++;
  }

  std::list<std::string> names{"Victor", "Chen", "Rina"};
  auto it2 = names.crbegin();
  std::cout << *it2 << std::endl;
  it2++;
  std::cout << *it2 << std::endl;

  std::map<std::string, std::string> pairs{
      {"Victor", "Java"},
      {"Chen", "C++"},
      {"Rina", "Python"}};
  auto it3 = pairs.begin(); // not in order
  while (it3 != pairs.end())
  {
    std::cout << it3->first << ": " << it3->second << std::endl;
    it3++;
  }
}

void test5()
{
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto s = vec.begin() + 2;
  auto e = vec.end() - 3;
  while (s != e)
  {
    std::cout << *s << std::endl;
    s++;
  }
}

int main()
{
  // test1();
  // test2();
  // test3();
  // test4();
  // test5();

  return 0;
}