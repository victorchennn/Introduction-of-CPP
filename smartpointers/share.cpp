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

void count(shared_ptr<Test> p)
{
  cout << "Use count: " << p.use_count() << endl;
}

int main()
{
  shared_ptr<int> p1{new int{10}};
  cout << *p1 << endl;
  cout << p1 << endl;
  cout << p1.get() << endl;

  cout << "Use count: " << p1.use_count() << endl; // 1
  shared_ptr<int> p2{p1};
  cout << "Use count: " << p1.use_count() << endl; // 2
  cout << "Use count: " << p2.use_count() << endl; // 2
  p1.reset();                                      // p1 is nullptr
  cout << "Use count: " << p1.use_count() << endl; // 0
  cout << "Use count: " << p2.use_count() << endl; // 1
  cout << endl;

  shared_ptr<Test> ptr = make_shared<Test>(10);
  count(ptr);                                       // 2, due to copy
  cout << "Use count: " << ptr.use_count() << endl; // 1
  {
    shared_ptr<Test> ptr1 = ptr;
    cout << "Use count: " << ptr.use_count() << endl;  // 2
    cout << "Use count: " << ptr1.use_count() << endl; // 2
    ptr.reset();
    cout << "Use count: " << ptr.use_count() << endl;  // 0
    cout << "Use count: " << ptr1.use_count() << endl; // 1
  }
  cout << "Use count: " << ptr.use_count() << endl; // 0
  cout << endl;

  vector<shared_ptr<int>> nums;
  shared_ptr<int> p3 = make_shared<int>(3);
  shared_ptr<int> p4 = make_shared<int>(4);
  nums.push_back(p3);
  nums.push_back(p4);
  nums.push_back(make_shared<int>(5));
  for (auto const &num : nums)
  {
    cout << "num: " << *num;
    cout << ", count: " << num.use_count() << endl;
  }

  return 0;
}