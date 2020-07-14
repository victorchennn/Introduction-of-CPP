#include <iostream>
#include <climits>

using namespace std;

int main()
{
  // sizeof info
  cout << "char: " << sizeof(char) << " bytes." << endl;
  cout << "int: " << sizeof(int) << " bytes." << endl;
  cout << "unsigned int: " << sizeof(unsigned int) << " bytes." << endl;
  cout << "short: " << sizeof(short) << " bytes." << endl;
  cout << "long: " << sizeof(long) << " bytes." << endl;
  cout << "long long: " << sizeof(long long) << " bytes." << endl;

  cout << "=====================" << endl;

  cout << "float: " << sizeof(float) << " bytes." << endl;
  cout << "double: " << sizeof(double) << " bytes." << endl;
  cout << "long double: " << sizeof(long double) << " bytes." << endl;

  cout << "=====================" << endl;

  cout << "Minimum values:" << endl;
  cout << "char: " << CHAR_MIN << endl;
  cout << "int: " << INT_MIN << endl;
  cout << "short: " << SHRT_MIN << endl;
  cout << "long: " << LONG_MIN << endl;
  cout << "long long: " << LLONG_MIN << endl;

  cout << "=====================" << endl;

  cout << "sizeof using variable names:" << endl;
  int age{18};
  cout << "age is " << sizeof age << " bytes" << endl; // no need ()
  double wage{22.22};
  cout << "wage is " << sizeof wage << " bytes" << endl;

  return 0;
}