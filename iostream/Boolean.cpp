#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  cout << "noboolalpha - default (10 == 10) : " << (10 == 10) << endl;
  cout << "noboolalpha - default (10 == 20) : " << (10 == 20) << endl;

  cout << boolalpha;
  cout << "boolalpha - default (10 == 10) : " << (10 == 10) << endl;
  cout << "boolalpha - default (10 == 20) : " << (10 == 20) << endl;

  cout << noboolalpha;
  cout << "noboolalpha - default (10 == 10) : " << (10 == 10) << endl;
  cout << "noboolalpha - default (10 == 20) : " << (10 == 20) << endl;

  cout.setf(ios::boolalpha);
  cout << "boolalpha - default (10 == 10) : " << (10 == 10) << endl;
  cout << "boolalpha - default (10 == 20) : " << (10 == 20) << endl;

  cout << resetiosflags(ios::boolalpha);
  cout << "default (10 == 10) : " << (10 == 10) << endl;
  cout << "default (10 == 20) : " << (10 == 20) << endl;

  return 0;
}