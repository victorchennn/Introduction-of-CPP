#include <iostream>
#include <string>

template <typename T, int N>
class Array
{
  int size{N};
  T values[N];

  friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &array)
  {
    os << "[";
    for (const auto &val : array.values)
    {
      os << val << " ";
    }
    os << "]" << std::endl;
    return os;
  }

public:
  Array() = default;
  Array(T init_value)
  {
    for (auto &value : values)
    {
      value = init_value;
    }
  }
  void fill(T val)
  {
    for (auto &value : values)
    {
      value = val;
    }
  }
  int getSize() const
  {
    return size;
  }
  T &operator[](int index)
  {
    return values[index];
  }
};

int main()
{
  Array<int, 5> nums;
  std::cout << "The size of nums is: " << nums.getSize() << std::endl;
  std::cout << nums << std::endl;

  nums.fill(0);
  std::cout << "The size of nums is: " << nums.getSize() << std::endl;
  std::cout << nums << std::endl;

  nums.fill(10);
  std::cout << nums << std::endl;

  nums[0] = 100;
  nums[3] = 1000;
  std::cout << nums << std::endl;

  Array<double, 10> nums2{1.1};
  std::cout << "The size of nums is: " << nums2.getSize() << std::endl;
  std::cout << nums2 << std::endl;

  return 0;
}