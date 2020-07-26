#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  double num1{123456789.987654321};
  double num2{1234.5678};
  double num3{1234.0};

  cout << num1 << endl;
  cout << num2 << endl;
  cout << num3 << endl;

  cout << setprecision(2) << endl;
  cout << num1 << endl;
  cout << num2 << endl;
  cout << num3 << endl;

  cout << setprecision(5) << endl;
  cout << num1 << endl;
  cout << num2 << endl;
  cout << num3 << endl;

  cout << setprecision(9) << endl;
  cout << num1 << endl;
  cout << num2 << endl;
  cout << num3 << endl;

  cout << setprecision(3) << fixed << endl; // after decimal point
  cout << num1 << endl;
  cout << num2 << endl;
  cout << num3 << endl;

  cout << setprecision(3) << fixed << showpos << endl; // after decimal point
  cout << num1 << endl;
  cout << num2 << endl;
  cout << num3 << endl;

  cout << setprecision(3) << scientific << uppercase << endl;
  cout << num1 << endl;
  cout << num2 << endl;
  cout << num3 << endl;

  cout.unsetf(ios::scientific | ios::fixed);
  cout << resetiosflags(ios::showpos);

  cout << setprecision(10) << showpoint << endl;
  cout << num1 << endl;
  cout << num2 << endl;
  cout << num3 << endl;

  return 0;
}