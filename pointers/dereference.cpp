#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  int num{100};
  int *numP{&num};
  cout << *numP << endl; // 100
  *numP = 200;
  cout << *numP << endl; // 200
  cout << num << endl;   // 200

  cout << endl;
  double high{100.7}, low{37.4};
  double *p{&high};
  cout << *p << endl;
  p = &low;
  cout << *p << endl;

  cout << endl;
  string name{"Victor"};
  string *nameP{&name};
  cout << *nameP << endl;
  name = "Rina";
  cout << *nameP << endl;

  cout << endl;
  vector<string> names{"Victor", "Rina", "Chen"};
  vector<string> *namesP{&names};
  cout << (*namesP).at(0) << endl;
  for (auto n : *namesP)
  {
    cout << n << " ";
  }
  cout << endl;

  return 0;
}