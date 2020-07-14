#include <iostream>
#include <string>
#include <vector>

using namespace std;

void toDouble(int *numP)
{
  *numP *= 2;
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void print(const vector<string> *const vp)
{
  // (*vp).at(0) = "Error"; // due to const vector
  for (auto s : *vp)
  {
    cout << s << " ";
  }
  cout << endl;
  // vp = nullptr; // due to const pointer
}

void print(int *array, int target)
{
  while (*array != target)
  {
    cout << *array++ << " ";
  }
  cout << endl;
}

void display(const int *const array, size_t size)
{
  for (size_t i{0}; i < size; i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;
}

int *create_array(size_t size, int value = 0)
{
  int *nums{nullptr};
  nums = new int[size];
  for (size_t i{0}; i < size; i++)
  {
    *(nums + i) = value;
  }
  return nums;
}

int *combine(const int *const nums1, size_t len1, const int *const nums2, size_t len2)
{
  int *nums{nullptr};
  nums = new int[len1 * len2];
  int index{0};
  for (size_t i{0}; i < len1; i++)
  {
    for (size_t j{0}; j < len2; j++)
    {
      nums[index++] = nums1[i] * nums2[j];
    }
  }
  return nums;
}

int main()
{
  int value{10};
  int *valueP{nullptr};

  cout << "Value: " << value << endl; // 10
  toDouble(&value);
  cout << "Value: " << value << endl; // 20
  valueP = &value;
  toDouble(valueP);
  cout << "Value: " << value << endl; // 40

  cout << endl;
  int x{100}, y{200};
  cout << "x: " << x << endl;
  cout << "y: " << y << endl;
  swap(&x, &y);
  cout << "x: " << x << endl;
  cout << "y: " << y << endl;

  cout << endl;
  vector<string> names{"Victor", "Rina", "Chen"};
  print(&names);

  cout << endl;
  int nums[]{1, 2, 3, 4, 5, -1};
  print(nums, -1);

  cout << endl;
  int *numsP{nullptr};
  size_t size{5};
  numsP = create_array(size, 10);
  display(numsP, size);
  delete[] numsP;

  cout << endl;
  int nums1[]{1, 2, 3, 4, 5};
  int nums2[]{100, 200};
  const size_t len1{5}, len2{2};
  int *results = combine(nums1, len1, nums2, len2);
  constexpr size_t len{len1 * len2};
  display(results, len);

  return 0;
}