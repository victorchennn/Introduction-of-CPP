#include <iostream>
#include <memory>

using namespace std;

class Test
{
private:
  int data;

public:
  Test() : data{0}
  {
    cout << "Test constructor (" << data << ")" << endl;
  }
  Test(int data) : data{data}
  {
    cout << "Test constructor (" << data << ")" << endl;
  }
  ~Test()
  {
    cout << "Test destructor (" << data << ")" << endl;
  }
  int getData() const
  {
    return data;
  }
};

void myDeleter(Test *p)
{
  cout << "Using custom deleter" << endl;
  delete p;
}

int main()
{
  {
    shared_ptr<Test> p1{new Test{1}, myDeleter}; // using a function
  }
  cout << endl;
  {
    shared_ptr<Test> p2{new Test{2},
                        [](Test *p) {
                          cout << "Using lambda deleter" << endl; // using a lambda expression
                          delete p;
                        }};
  }

  return 0;
}