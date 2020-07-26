#include <iostream>
#include <stack>
#include <vector>
#include <list>

template <typename T>
void print(std::stack<T> s) // pass by value, not reference
{
  std::cout << "[ ";
  while (!s.empty())
  {
    T elem = s.top();
    s.pop();
    std::cout << elem << " ";
  }
  std::cout << "]" << std::endl;
}

int main()
{
  std::stack<int> s; // default deque
  std::stack<int, std::vector<int>> s1;
  std::stack<int, std::list<int>> s2;

  for (int i : {1, 2, 3, 4, 5})
  {
    s.push(i);
  }
  print(s);
  s.push(6);
  print(s);
  s.pop();
  s.pop();
  print(s);

  while (!s.empty())
  {
    s.pop();
  }
  print(s);
  std::cout << "Size: " << s.size() << std::endl;

  s.push(10);
  print(s);
  s.top() = 100;
  print(s);

  return 0;
}