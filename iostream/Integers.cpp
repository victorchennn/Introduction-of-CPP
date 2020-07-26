#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  int num{255};
  cout << dec << num << endl; // 255
  cout << hex << num << endl; // ff
  cout << oct << num << endl; // 377

  cout << showbase << endl;
  cout << dec << num << endl; // 255
  cout << hex << num << endl; // 0xff
  cout << oct << num << endl; // 0377

  cout << uppercase << endl;
  cout << hex << num << endl; // 0XFF

  cout << showpos << endl;
  cout << dec << num << endl; // +255
  cout << hex << num << endl; // 0XFF
  cout << oct << num << endl; // 0377

  cout.setf(ios::showbase);
  cout.setf(ios::uppercase);
  cout.setf(ios::showpos);

  cout << resetiosflags(ios::basefield);
  cout << resetiosflags(ios::showbase);
  cout << resetiosflags(ios::uppercase);
  cout << resetiosflags(ios::showpos);

  cout << endl;
  cout << dec << num << endl; // 255
  cout << hex << num << endl; // ff
  cout << oct << num << endl; // 377

  return 0;
}