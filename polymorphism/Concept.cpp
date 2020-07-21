#include <iostream>

using namespace std;

class Base
{
public:
  void hello() const
  {
    cout << "Hello from base class" << endl;
  }
};

class Derived : public Base
{
public:
  void hello() const
  {
    cout << "Hello from derived class" << endl;
  }
};

void greetings(const Base &obj)
{
  cout << "Greetings: ";
  obj.hello();
}

int main()
{
  Base b;
  b.hello();

  Derived d;
  d.hello();

  greetings(b);
  greetings(d);

  Base *p = new Derived();
  p->hello(); // base hello

  return 0;
}