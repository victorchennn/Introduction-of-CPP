#include <iostream>

using namespace std;

int main()
{
  // Character types
  char ch{'V'};

  // Integer types
  unsigned short int num1{16}; // same as unsigned short num1{16}
  cout << "num1: " << num1 << endl;
  int num2{42};
  cout << "num2: " << num2 << endl;
  long num3{100000000};
  cout << "num3: " << num3 << endl;
  long long num4{7'600'000'000};
  cout << "num4: " << num4 << endl;

  // Floating point types
  float num5{2.17};
  cout << "num5: " << num5 << endl;
  double num6{3.1415926};
  cout << "num6: " << num6 << endl;
  long double num7{2.7e120};
  cout << "num7: " << num7 << endl;

  // Boolean types
  bool game_over{false};
  cout << "The value of game_over is: " << game_over << endl; // 0

  // Overflow example
  // short v1{30000};
  // short v2{1000};
  // short product{v1 * v2};
  // cout << "The product is: " << product << endl;

  return 0;
}