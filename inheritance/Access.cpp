#include <iostream>

using namespace std;

class Base
{
private:
  int value;

public:
  int a{0};
  Base() : value{0}
  {
    cout << "base no-arg constructor" << endl;
  }
  Base(int x) : value{x}
  {
    cout << "base constructor" << endl;
  }
  ~Base()
  {
    cout << "base destructor" << endl;
  }

  void display()
  {
    cout << a << ", " << b << ", " << c << endl;
  }

protected:
  int b{1};

private:
  int c{2};
};

// if inheritance is protected or private, then a and b
// would also be protected or private
class Derived : public Base
{
  // using Base::Base; // inherit base constructor

private:
  int doubledValue;

public:
  // explicitly provide the base constructor to be called
  Derived() : Base{}, doubledValue{0}
  {
    cout << "derived no-arg constructor" << endl;
  }
  Derived(int x) : Base{x}, doubledValue{x * 2}
  {
    cout << "derived constructor" << endl;
  }
  ~Derived()
  {
    cout << "derived destructor" << endl;
  }

  void access()
  {
    a = 1;
    b = 2;
    // c = 3; // inaccessible
  }
};

int main()
{
  Base base;
  base.a = 1;
  // base.b = 2; // inaccessible
  // base.c = 3; // inaccessible

  Derived derived;
  derived.a = 2;
  // derived.b = 3; // inaccessible
  // derived.c = 4; // inaccessible

  Base b{100};

  // given its own constructor provided or not, it will always
  // call base default constructor at first, initialize value to 0
  Derived d;

  // error if no derived constructor provided, since derived class
  // does NOT inherit the base constructor
  // it will still call the base no-arg constructor if no
  // explicitly the base constructor is provided
  Derived dd{1000};

  return 0;
}