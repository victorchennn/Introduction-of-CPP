/**
 * @see reference.cpp
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void pass_by_value1(int);
void pass_by_value2(string);
void pass_by_value3(vector<string>);
void print_vector(vector<string>);

void pass_by_value1(int num)
{
  num = 1000;
}

void pass_by_value2(string s)
{
  s = "Changed";
}

void pass_by_value3(vector<string> v)
{
  v.clear();
}

void print_vector(vector<string> v)
{
  for (auto s : v)
  {
    cout << s << " ";
  }
  cout << endl;
}

int main()
{
  int num{10};
  cout << "Before: " << num << endl;
  pass_by_value1(num); // no change
  cout << "After: " << num << endl;

  string s{"initial"};
  cout << "Before: " << s << endl;
  pass_by_value2(s); // no change
  cout << "After: " << s << endl;

  vector<string> names{"Victor", "Rina"};
  cout << "Before: " << endl;
  print_vector(names);
  pass_by_value3(names); // no change
  cout << "After: " << endl;
  print_vector(names);

  return 0;
}