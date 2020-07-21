#include <iostream>

using namespace std;

class Base
{
public:
  virtual ~Base() {}
  virtual void hello() const
  {
    cout << "Hello from base class" << endl;
  }
};

class Derived : public Base
{
public:
  virtual ~Derived() {}
  virtual void hello() const override // signature has to be exactly same to override
  {
    cout << "Hello from derived class" << endl;
  }
};

int main()
{
  Base *p1 = new Base();
  p1->hello();

  Derived *p2 = new Derived();
  p2->hello();

  Base *p3 = new Derived();
  p3->hello();

  return 0;
}