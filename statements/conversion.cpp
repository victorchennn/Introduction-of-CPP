#include <iostream>

using namespace std;

int main()
{
  int sum{};
  int num1{}, num2{}, num3{};
  const int count{3};

  cout << "Enter 3 integers: " << endl;
  cin >> num1 >> num2 >> num3;

  sum = num1 + num2 + num3;
  double average{0.0};

  average = static_cast<double>(sum) / count; // don't use (double)sum
  cout << "sum is: " << sum << endl;
  cout << "average is: " << average << endl;

  return 0;
}