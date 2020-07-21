#include <iostream>

using namespace std;

class Base
{
private:
  int value;

public:
  Base() : value{0}
  {
    cout << "base no-arg constructor" << endl;
  }
  Base(int x) : value{x}
  {
    cout << "base constructor" << endl;
  }
  Base(const Base &other) : value{other.value}
  {
    cout << "base copy constructor" << endl;
  }
  Base &operator=(const Base &rhs)
  {
    cout << "base operator=" << endl;
    if (this == &rhs)
    {
      return *this;
    }
    value = rhs.value;
    return *this;
  }
  ~Base()
  {
    cout << "base destructor" << endl;
  }
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
  Derived(const Derived &other) : Base(other), doubledValue{other.doubledValue}
  {
    cout << "derived copy constructor" << endl;
  }
  Derived &operator=(const Derived &rhs)
  {
    cout << "derived operator=" << endl;
    if (this == &rhs)
    {
      return *this;
    }
    Base::operator=(rhs); // !!!
    doubledValue = rhs.doubledValue;
    return *this;
  }
  ~Derived()
  {
    cout << "derived destructor" << endl;
  }
};

int main()
{
  Base b{100};
  Base b1{b}; // copy constructor
  b = b1;     // copy assignment

  Derived d{100};
  Derived d1{d};
  d = d1;

  return 0;
}