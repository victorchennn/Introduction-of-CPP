#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Item
{
private:
  std::string name;
  T value;

public:
  Item(std::string name, T value) : name{name}, value{value} {}
  std::string getName() const { return name; }
  T getValue() const { return value; }
};

template <typename T1, typename T2>
struct Pair
{
  T1 first;
  T2 second;
};

int main()
{
  Item<int> item1{"Victor", 100};
  std::cout << item1.getName() << " " << item1.getValue() << std::endl;
  Item<std::string> item2{"Rina", "Hi"};
  std::cout << item2.getName() << " " << item2.getValue() << std::endl;
  Item<Item<std::string>> item3{"Chen", {"C++", "Hello"}};
  std::cout << item3.getName() << " " << item3.getValue().getName() << " " << item3.getValue().getValue() << std::endl;

  std::vector<Item<double>> items{};
  items.push_back(Item<double>{"A", 1.1});
  items.push_back(Item<double>{"B", 2.1});
  items.push_back(Item<double>{"C", 3.1});
  for (const auto &item : items)
  {
    std::cout << item.getName() << " " << item.getValue() << std::endl;
  }

  Pair<std::string, int> p1{"V", 10};
  Pair<int, double> p2{1, 2.2};
  std::cout << p1.first << " " << p1.second << std::endl;
  std::cout << p2.first << " " << p2.second << std::endl;

  return 0;
}
