/**
 * @see paramaters.cpp
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void pass_by_ref1(int &);
void pass_by_ref2(string &);
void pass_by_ref3(vector<string> &);
void print_vector(const vector<string> &);

void pass_by_ref1(int &num)
{
  num = 1000;
}

void pass_by_ref2(string &s)
{
  s = "Changed";
}

void pass_by_ref3(vector<string> &v)
{
  v.clear();
}

void print_vector(const vector<string> &v)
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
  pass_by_ref1(num); // changed
  cout << "After: " << num << endl;

  string s{"initial"};
  cout << "Before: " << s << endl;
  pass_by_ref2(s); // changed
  cout << "After: " << s << endl;

  vector<string> names{"Victor", "Rina"};
  cout << "Before: " << endl;
  print_vector(names);
  pass_by_ref3(names); // changed
  cout << "After: " << endl;
  print_vector(names);

  return 0;
}