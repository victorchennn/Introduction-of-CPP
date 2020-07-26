/**
 * insertions and removal of elements in order from the front
 * stored internally as a vector by default
 * inserted in priority order, default largest at the front
 * No iterators are supported
 */

#include <iostream>
#include <queue>

template <typename T>
void print(T pq)
{
  std::cout << "[ ";
  while (!pq.empty())
  {
    std::cout << pq.top() << " ";
    pq.pop();
  }
  std::cout << "]" << std::endl;
}

// push, pop, top, size
void test1()
{
  std::priority_queue<int> pq;
  for (int i : {4, 2, 3, 5, 7, 1, 6, 7, 9, 8})
  {
    pq.push(i);
  }
  print(pq);
  std::cout << "Size: " << pq.size() << std::endl;
  std::cout << "Top: " << pq.top() << std::endl;

  pq.pop();
  print(pq);
  std::cout << "Size: " << pq.size() << std::endl;
  std::cout << "Top: " << pq.top() << std::endl;
}

// override comparator
void test2()
{
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq1; // default less
  for (int i : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
    pq1.push(i);
  print(pq1);

  auto compare = [](int lhs, int rhs) { return lhs > rhs; };
  std::priority_queue<int, std::vector<int>, decltype(compare)> pq2(compare); // use lambda func
  for (int i : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
    pq2.push(i);
  print(pq2);

  struct customCompare
  {
    bool operator()(const int &lhs, const int &rhs) { return lhs > rhs; };
  };
  std::priority_queue<int, std::vector<int>, customCompare> pq3; // use struct
  for (int i : {1, 8, 5, 6, 3, 4, 0, 9, 7, 2})
    pq3.push(i);
  print(pq3);
}

int main()
{
  // test1();
  // test2();

  return 0;
}