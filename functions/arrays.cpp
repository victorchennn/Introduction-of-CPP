#include <iostream>

using namespace std;

void print_array(const int nums[], size_t size);        // 'const' can not be modified
void set_array(int nums[], size_t size, int value = 0); // default set value 0

void print_array(const int nums[], size_t size)
{
  for (size_t i{0}; i < size; i++)
  {
    cout << nums[i] << " ";
  }
  cout << endl;
}

void set_array(int nums[], size_t size, int value)
{
  for (size_t i{0}; i < size; i++)
  {
    nums[i] = value;
  }
}

int main()
{
  int scores[]{100, 99, 98, 97, 96};
  print_array(scores, 5);
  set_array(scores, 5);
  print_array(scores, 5);
  set_array(scores, 5, 100);
  print_array(scores, 5);

  return 0;
}