#include <iostream>

using namespace std;

int main()
{
  int nums[]{1, 2, 3};
  cout << "Value of nums: " << nums << endl;
  int *numsP{nums};
  cout << "Value of numsP: " << numsP << endl;

  cout << "Array subscript notation: " << endl;
  cout << nums[0] << endl;
  cout << nums[1] << endl;
  cout << nums[2] << endl;

  cout << "Pointer subscript notation: " << endl;
  cout << numsP[0] << endl;
  cout << numsP[1] << endl;
  cout << numsP[2] << endl;

  cout << "Array offset notation: " << endl;
  cout << *nums << endl;
  cout << *(nums + 1) << endl;
  cout << *(nums + 2) << endl;

  cout << "Pointer offset notation: " << endl;
  cout << *numsP << endl;
  cout << *(numsP + 1) << endl;
  cout << *(numsP + 2) << endl;

  return 0;
}