#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
  string s0;
  string s1{"Apple"};
  string s2{"Banana"};
  string s3{"Kiwi"};
  string s4{"Apple"};
  string s5{s1};       // "Apple"
  string s6{s1, 0, 3}; // "App"
  string s7(5, 'X');   // "XXXXX"

  cout << s0 << endl;
  cout << s0.length() << endl;
  cout << (s1 == s4) << endl; // true

  s2.swap(s3);
  cout << s2 << endl;
  cout << s3 << endl;

  s1[0] = 'C';
  s1.at(1) = 'P';
  cout << s1 << endl;

  s4 = s2 + " and " + s3 + " juice";
  cout << s4 << endl;
  // s4 = "apple" + "banana"; // compile error

  s1 = "Apple";
  for (size_t i{0}; i < s1.size(); i++)
  {
    cout << s1.at(i);
  }
  cout << endl;

  s1 = "This is a test";
  cout << s1.substr(0, 4) << endl; // This
  cout << s1.substr(5, 2) << endl; // is
  cout << s1.substr(5) << endl;    // is a test

  s1.erase(1, 5);
  cout << s1 << endl; // Ts a test

  string name{};
  cout << "Enter a name: " << endl;
  getline(cin, name);
  cout << "Your name is: " << name << endl;

  s1 = "Hello C++";
  string word{};
  cout << "Enter the word to find: " << endl;
  cin >> word;

  size_t pos = s1.find(word);
  if (pos != string::npos)
  {
    cout << "Found at position: " << pos << endl;
  }
  else
  {
    cout << "Not Found" << endl;
  }

  return 0;
}