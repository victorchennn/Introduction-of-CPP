#include <iostream>

using namespace std;

int width{10}; // global automatically initialized is 0

int main()
{
  int width{0};
  int length{0};
  cout << "The width is " << width << " and length is " << length << endl;
  cout << "Enter the width and length of the room: ";
  cin >> width >> length;
  cout << "The area of the room is " << width * length << endl;

  return 0;
}