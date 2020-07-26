#include <iostream>
#include <map>
#include <set>
#include <algorithm>

void print(const std::map<std::string, std::set<int>> &m)
{
  std::cout << "[ ";
  for (const auto &ele : m)
  {
    std::cout << ele.first << ":[ ";
    for (const auto &se : ele.second)
      std::cout << se << " ";
    std::cout << "] ";
  }
  std::cout << "]" << std::endl;
}

template <typename T1, typename T2>
void print(const std::map<T1, T2> &m)
{
  std::cout << "[ ";
  std::for_each(m.begin(), m.end(),
                [](auto x) { std::cout << x.first << ":" << x.second << " "; });
  std::cout << "]" << std::endl;
}

// initilization, insert(pair), access, count, find(pair iterator), cleart
void test1()
{
  std::map<std::string, int> m{
      {"Victor", 1},
      {"Chen", 2}};
  print(m);

  m.insert(std::pair<std::string, int>("Rina", 3));
  print(m);
  m.insert(std::make_pair("Luo", 4));
  print(m);

  m["Che"] = 18;
  print(m);
  m["Che"] += 10;
  print(m);
  m.erase("Che");
  print(m);

  std::cout << "Count for Chen: " << m.count("Chen") << std::endl;
  std::cout << "Count for Che: " << m.count("Che") << std::endl;

  auto it = m.find("Victor");
  if (it != m.end())
  {
    std::cout << "Found: " << it->first << ":" << it->second << std::endl;
  }
  m.clear();
  print(m);
}

void test2()
{
  std::map<std::string, std::set<int>> grades{
      {"Victor", {95, 90}},
      {"Rina", {100, 98}},
      {"Chen", {99}}};
  print(grades);
  grades["Victor"].insert(97);
  print(grades);

  auto it = grades.find("Chen");
  if (it != grades.end())
  {
    it->second.insert(100);
  }
  print(grades);
}

int main()
{
  // test1();
  // test2();

  return 0;
}