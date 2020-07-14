#include <iostream>

using namespace std;

int main()
{
  int rooms{0};
  cout << "number of rooms: " << endl;
  cin >> rooms;

  const double price{30.0};
  const double tax{0.06};
  const int expiry{30};

  cout << "number of rooms: " << rooms << endl;
  cout << "price per room: " << price << endl;
  cout << "cost: " << price * rooms << endl;
  cout << "tax: " << price * rooms * tax << endl;
  cout << "=========================" << endl;
  cout << "total estimate: " << expiry * rooms + expiry * rooms * tax << endl;
  cout << "valid for " << expiry << " days" << endl;

  return 0;
}