#include <iostream>
#include <memory>
#include <vector>

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

int main()
{
  Test *t1 = new Test{1}; // raw pointer
  delete t1;

  unique_ptr<int> p1{new int{1}};
  cout << *p1 << endl;
  *p1 = 11;
  cout << *p1 << endl;

  unique_ptr<Test> t2{new Test{2}};           // auto delete
  unique_ptr<Test> t3 = make_unique<Test>(3); // auto delete
  unique_ptr<Test> t4;
  // unique_ptr<Test> t4{t2}; // error
  // t4 = t2;                 // error
  t4 = move(t2);
  if (!t2) // move t2 to t4
  {
    cout << "t2 is nullptr" << endl;
  }
  vector<unique_ptr<Test>> tests;
  // tests.push_back(t3);     // error, can't copy
  tests.push_back(move(t3));
  tests.push_back(make_unique<Test>(10));
  tests.push_back(make_unique<Test>(20));
  tests.push_back(make_unique<Test>(30));

  for (const auto &test : tests) // by reference, since can't copy
  {
    cout << test.get() << endl;
  }

  return 0;
}