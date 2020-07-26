/**
 * dynamic size, elements are NOT stored in contiguous memory
 * constant time element access
 * constant time insertion and deletion at the front and back
 * linear time insertion and removal of elements
 * all iterators available and may invalidate
 */

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

template <typename T>
void print(const std::deque<T> &dq)
{
  std::cout << "[ ";
  std::for_each(dq.begin(), dq.end(), [](auto x) { std::cout << x << " "; });
  std::cout << "]" << std::endl;
}

// initialization, access
void test1()
{
  std::deque<int> d{1, 2, 3, 4, 5};
  print(d);
  d = {2, 3, 4, 5, 6};
  print(d);

  std::deque<int> dd(10, 100); // 10*100
  print(dd);
  dd[0] = 1000;
  dd.at(1) = 10000;
  print(dd);
}

// front, back
void test2()
{
  std::deque<int> d{0};
  print(d);
  d.push_back(10);
  d.push_back(20);
  d.push_front(-10);
  d.push_front(-20);
  print(d);

  std::cout << "Front: " << d.front() << std::endl;
  std::cout << "Back: " << d.back() << std::endl;
  std::cout << "Size: " << d.size() << std::endl;

  d.pop_back();
  d.pop_front();
  print(d);
}

// push
void test3()
{
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::deque<int> d;

  for (const auto &e : vec)
  {
    if (e % 2 == 0)
    {
      d.push_back(e);
    }
    else
    {
      d.push_front(e);
    }
  }
  print(d);
}

// std::copy, front, back_inserter
void test4()
{
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::deque<int> d;

  std::copy(vec.begin(), vec.end(), std::front_inserter(d));
  print(d);
  d.clear();
  std::copy(vec.begin(), vec.end(), std::back_inserter(d));
  print(d);
}

int main()
{
  // test1();
  // test2();
  // test3();
  // test4();

  return 0;
}
