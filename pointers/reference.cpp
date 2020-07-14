#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  int num{100};
  int &ref{num};
  // int &ref = 100; // error, 100 is an r-value

  cout << num << endl;
  cout << ref << endl;
  num = 200;
  cout << num << endl;
  cout << ref << endl;
  ref = 300;
  cout << num << endl;
  cout << ref << endl;

  cout << endl;
  vector<string> names{"Victor", "Chen", "Rina"};
  for (auto name : names)
  {
    name = "Changed";
  }
  for (auto name : names)
  {
    cout << name << " ";
  }

  cout << endl;
  for (auto &name : names)
  {
    name = "Changed";
  }
  for (auto const &name : names)
  {
    cout << name << " ";
  }

  return 0;
}