#include <iostream>
#include <queue>

template <typename T>
void print(std::queue<T> q) // pass by value, not reference
{
  std::cout << "[ ";
  while (!q.empty())
  {
    T elem = q.front();
    q.pop();
    std::cout << elem << " ";
  }
  std::cout << "]" << std::endl;
}

int main()
{
  std::queue<int> q;
  for (int i : {1, 2, 3, 4, 5})
  {
    q.push(i);
  }
  print(q);
  std::cout << "Front: " << q.front() << std::endl;
  std::cout << "Back: " << q.back() << std::endl;

  q.front() = 10;
  q.back() = 50;
  print(q);
  std::cout << "Front: " << q.front() << std::endl;
  std::cout << "Back: " << q.back() << std::endl;

  return 0;
}