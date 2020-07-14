#include <iostream>

using namespace std;

int main()
{
  bool equal_result{false};
  bool not_equal_result{false};

  int num1{}, num2{};
  cout << "Enter two integers: " << endl;
  cin >> num1 >> num2;
  equal_result = (num1 == num2);
  not_equal_result = (num1 != num2);
  cout << "equal?: " << equal_result << endl;
  cout << "Noequal?: " << not_equal_result << endl;
  cout << boolalpha;
  cout << "equal?: " << equal_result << endl;
  cout << "Noequal?: " << not_equal_result << endl;

  double num3{};
  cout << "Enter an integer and a double: " << endl;
  cin >> num1 >> num3;
  equal_result = (num1 == num3);
  not_equal_result = (num1 != num3);
  cout << "equal?: " << equal_result << endl;
  cout << "Noequal?: " << not_equal_result << endl;
  cout << noboolalpha;
  cout << "equal?: " << equal_result << endl;
  cout << "Noequal?: " << not_equal_result << endl;

  return 0;
}