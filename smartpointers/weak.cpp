#include <iostream>
#include <memory>

using namespace std;

class B; // forward declaration

class A
{
  shared_ptr<B> b_ptr;

public:
  A()
  {
    cout << "A constructor" << endl;
  }
  ~A()
  {
    cout << "A destructor" << endl;
  }
  void setB(shared_ptr<B> &b)
  {
    b_ptr = b;
  }
};

class B
{
  weak_ptr<A> a_ptr; // make weak to break the strong circular reference

public:
  B()
  {
    cout << "B constructor" << endl;
  }
  ~B()
  {
    cout << "B destructor" << endl;
  }
  void setA(shared_ptr<A> &a)
  {
    a_ptr = a;
  }
};

int main()
{
  // if not setting weak_ptr, none of them will be deleted
  shared_ptr<A> a = make_shared<A>();
  shared_ptr<B> b = make_shared<B>();
  a->setB(b);
  b->setA(a);

  return 0;
}