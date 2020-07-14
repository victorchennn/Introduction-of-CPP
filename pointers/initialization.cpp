#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  int num{10};
  cout << "Value of num is: " << num << endl;
  cout << "sizeof of num is: " << sizeof num << endl;
  cout << "Address of num is: " << &num << endl;

  int *p;
  cout << "\nValue of p is: " << p << endl;
  cout << "Address of p is: " << &p << endl;
  cout << "sizeof of p is: " << sizeof p << endl;
  p = nullptr;
  cout << "Value of p is: " << p << endl;

  int *p1{nullptr};
  double *p2{nullptr};
  unsigned long long *p3{nullptr};
  string *p4{nullptr};
  vector<string> *p5{nullptr};

  cout << "\nsizeof of p1 is: " << sizeof p1 << endl;
  cout << "sizeof of p2 is: " << sizeof p2 << endl;
  cout << "sizeof of p3 is: " << sizeof p3 << endl;
  cout << "sizeof of p4 is: " << sizeof p4 << endl;
  cout << "sizeof of p5 is: " << sizeof p5 << endl;

  int score{10};
  double temp{100.7};
  int *score_p{nullptr};
  score_p = &score;
  // score_p = &temp; // compiler error
  cout << "\nValue of score is: " << score << endl;
  cout << "Address of score is: " << &score << endl;
  cout << "Value of score_p is: " << score_p << endl;

  return 0;
}