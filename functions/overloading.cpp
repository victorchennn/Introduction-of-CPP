#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(int = 0);
void print(int);
void print(double);
void print(string);
void print(string, string);
void print(vector<string>);

void print(int num)
{
  cout << "Printing int: " << num << endl;
}

void print(double num)
{
  cout << "Printing double: " << num << endl;
}

void print(string s)
{
  cout << "Printing string: " << s << endl;
}

void print(string s1, string s2)
{
  cout << "Printing strings: " << s1 << " AND " << s2 << endl;
}

void print(vector<string> v)
{
  cout << "Printing vector: " << endl;
  for (auto s : v)
  {
    cout << s + " ";
  }
  cout << endl;
}

int main()
{
  print();
  print(100);
  print('A'); // char is promoted to int

  print(7.12);
  print(7.12F); // float is promoted to double

  print("Hello");
  string s{"C++"};
  print(s);
  print("Hello", s);

  vector<string> names{"Victor", "Rina"};
  print(names);

  return 0;
}