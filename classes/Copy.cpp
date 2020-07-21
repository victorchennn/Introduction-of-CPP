#include <iostream>

using namespace std;

class Copy
{
private:
  int *data;

public:
  void set_data(int d)
  {
    *data = d;
  }
  int get_data()
  {
    return *data;
  }
  Copy(int d);
  Copy(const Copy &source);
  ~Copy();
};

Copy::Copy(int d)
{
  cout << "Constructor called!" << endl;
  data = new int;
  *data = d;
}

// shallow copy
// Copy::Copy(const Copy &source) : data(source.data)
// {
//   cout << "Copy Constructor: shallow copy" << endl;
// }

// deep copy
Copy::Copy(const Copy &source) : Copy{*source.data}
{
  // same as below, just not calling the constructor
  // data = new int;
  // *data = *source.data;
  cout << "Copy Constructor: deep copy" << endl;
}

Copy::~Copy()
{
  delete data;
  cout << "Destructor called!" << endl;
}

// if implemented shallow copy, s is also pointing to the s1,
// after the function it deletes the original data
void display(Copy s)
{
  cout << s.get_data() << endl;
}

int main()
{
  Copy o1{100};
  display(o1); // cause the error

  Copy o2{o1};
  o2.set_data(1000);

  return 0;
}