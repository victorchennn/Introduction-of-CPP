#include <iostream>

using namespace std;

int main()
{
  int nums[]{1, 2, 3, -1};
  int *numsP{nums};
  while (*numsP != -1)
  {
    cout << *numsP++ << " ";
  }
  cout << endl;

  string s1{"Victor"}, s2{"Victor"}, s3{"Rina"};
  string *p1{&s1}, *p2{&s2}, *p3{&s1};

  cout << boolalpha;
  cout << p1 << " == " << p2 << ": " << (p1 == p2) << endl;
  cout << p1 << " == " << p3 << ": " << (p1 == p3) << endl;

  cout << *p1 << " == " << *p2 << ": " << (*p1 == *p2) << endl;
  cout << *p1 << " == " << *p3 << ": " << (*p1 == *p3) << endl;

  p3 = &s3;
  cout << *p1 << " == " << *p3 << ": " << (*p1 == *p3) << endl;

  char name[]("Victor");
  char *charP1{nullptr};
  char *charP2{nullptr};

  charP1 = &name[0];
  charP2 = &name[3];

  cout << "In the string \"" << name << "\", " << *charP1 << " is "
       << (charP2 - charP1) << " characters away from " << *charP2 << endl;

  return 0;
}