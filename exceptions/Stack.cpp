#include <iostream>

using namespace std;

void b();
void c();

void a() {
  cout << "Start function a" << endl;
  b();
  cout << "End function a" << endl;
}

void b() {
  cout << "Start function b" << endl;
  try {
    c();
  } catch(int &e) {
    cout << "caught error in b" << endl;
  }
  
  cout << "End function b" << endl;
}

void c() {
  cout << "Start function c" << endl;
  throw 0;
  cout << "End function c" << endl;
}

int main() {
  cout << "Start function main" << endl;
  try {
    a();
  } catch(int &e) {
    cout << "caught error in main" << endl;
  }
  cout << "End function main" << endl;
  return 0;
}
