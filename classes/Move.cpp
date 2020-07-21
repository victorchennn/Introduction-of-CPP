#include <iostream>
#include <vector>

using namespace std;

class Move
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
  Move(int d);
  Move(const Move &source);
  Move(Move &&source) noexcept;
  ~Move();
};

Move::Move(int d)
{
  cout << "Constructor called!" << endl;
  data = new int;
  *data = d;
}

Move::Move(const Move &source) : Move{*source.data}
{
  cout << "Copy Constructor" << endl;
}

Move::Move(Move &&source) noexcept : data{source.data}
{
  source.data = nullptr;
  cout << "Move Constructor" << endl;
}

Move::~Move()
{
  delete data;
  cout << "Destructor called!" << endl;
}

int main()
{
  vector<Move> vec;
  vec.push_back(Move{10});
  vec.push_back(Move{20});
  vec.push_back(Move{30});

  return 0;
}