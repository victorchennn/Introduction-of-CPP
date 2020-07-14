#include <iostream>

using namespace std;

int main()
{
  int *intP{nullptr};
  intP = new int;
  cout << intP << endl;
  cout << *intP << endl;
  *intP = 100;
  cout << *intP << endl;
  delete intP;

  size_t size{0};
  double *tempP{nullptr};
  cin >> size;

  tempP = new double[size];
  cout << tempP << endl;
  cout << *tempP << endl;
  delete[] tempP;

  return 0;
}