/**
 * fixed size
 * direct element access
 * access to and use the underlying raw array
 * all iterators available and do NOT invalidate
 */

#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

void display(const std::array<int, 5> &arr)
{
  std::cout << "[ ";
  for (const auto &i : arr)
  {
    std::cout << i << " ";
  }
  std::cout << "]" << std::endl;
}

// access, size, front, back
void test1()
{
  std::array<int, 5> arr1{1, 2, 3, 4, 5};
  std::array<int, 5> arr2;
  display(arr1);
  display(arr2);
  arr2 = {10, 20, 30, 40, 50};
  display(arr1);
  display(arr2);
  std::cout << "Size of arr1: " << arr1.size() << std::endl;
  arr2[0] = 1000;
  arr2.at(1) = 2000;
  display(arr2);
  std::cout << "Front of arr2: " << arr2.front() << std::endl;
  std::cout << "Back of arr2: " << arr2.back() << std::endl;
}

// fill, swap
void test2()
{
  std::array<int, 5> arr1{1, 2, 3, 4, 5};
  std::array<int, 5> arr2{10, 20, 30, 40, 50};
  display(arr1);
  display(arr2);
  arr1.fill(0);
  display(arr1);
  arr1.swap(arr2);
  display(arr1);
  display(arr2);
}

// pointer
void test3()
{
  std::array<int, 5> arr1{1, 2, 3, 4, 5};
  int *p = arr1.data();
  std::cout << p << std::endl;
  std::cout << *p << std::endl;
  std::cout << *p + 1 << std::endl;
  *p = 10;
  display(arr1);
}

// sort
void test4()
{
  std::array<int, 5> arr1{2, 3, 1, 5, 4};
  display(arr1);
  std::sort(arr1.begin(), arr1.end());
  display(arr1);
}

// min, max iterator
void test5()
{
  std::array<int, 5> arr1{2, 3, 1, 4, 5};
  std::array<int, 5>::iterator min = std::min_element(arr1.begin(), arr1.end());
  auto max = std::max_element(arr1.begin(), arr1.end());
  std::cout << "min: " << min << std::endl;
  std::cout << "min: " << *min << std::endl;
  std::cout << "max: " << max << std::endl;
  std::cout << "max: " << *max << std::endl;
}

// adjacent_find equal iterator
void test6()
{
  std::array<int, 5> arr1{2, 3, 4, 4, 5};
  auto adj = std::adjacent_find(arr1.begin(), arr1.end());
  if (adj != arr1.end())
  {
    std::cout << "Found adjacent of " << *adj << std::endl;
  }
  else
  {
    std::cout << "Not Found" << std::endl;
  }
}

// accumulate sum
void test7()
{
  std::array<int, 5> arr1{2, 3, 4, 1, 5};
  int sum1 = std::accumulate(arr1.begin(), arr1.end(), 0); // start from 0;
  std::cout << "Sum of element: " << sum1 << std::endl;
  int sum2 = std::accumulate(arr1.begin(), arr1.end(), 10); // start from 10;
  std::cout << "Sum of element: " << sum2 << std::endl;
}

// count
void test8()
{
  std::array<int, 8> arr1{4, 4, 1, 2, 2, 3, 4, 5};
  int count1 = std::count(arr1.begin(), arr1.end(), 1);
  std::cout << "Count of 1: " << count1 << std::endl;
  int count2 = std::count(arr1.begin(), arr1.end(), 2);
  std::cout << "Count of 2: " << count2 << std::endl;
  int count4 = std::count(arr1.begin(), arr1.end(), 4);
  std::cout << "Count of 4: " << count4 << std::endl;
}

// count_if
void test9()
{
  std::array<int, 8> arr1{10, 40, 50, 2000, 1, 3, 1000, 5};
  int count = std::count_if(arr1.begin(), arr1.end(), [](int x) { return x > 10 && x < 1000; });
  std::cout << "Found " << count << std::endl;
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

  return 0;
}