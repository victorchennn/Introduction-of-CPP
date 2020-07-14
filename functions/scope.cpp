#include <iostream>

using namespace std;

void static_local();

void static_local()
{
  static int num{1}; // 'static' only initialized once
  cout << "num is: " << num << endl;
  num += 1;
  cout << "num is: " << num << endl;
}

int main()
{
  static_local();
  static_local();
  static_local();

  return 0;
}