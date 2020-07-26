#include "Account.h"
#include "AccountSavings.h"
#include "IllegalBalanceException.h"

#include <iostream>
#include <memory>

using namespace std;

int main()
{
  cout << "Account class: " << endl;
  Account a{"a", 100.0};
  cout << a << endl;

  a.deposit(50.0);
  cout << a << endl;

  a.withdraw(100.0);
  cout << a << endl;

  a.withdraw(500.0);
  cout << a << endl;

  cout << "\nSavings Account class: " << endl;
  AccountSavings s{"s", 100.0, 5.0};
  cout << s << endl;

  s.deposit(100.0);
  cout << s << endl;

  s.withdraw(100.0);
  cout << s << endl;

  s.withdraw(500.0);
  cout << s << endl;

  try
  {
    unique_ptr<AccountSavings> p = make_unique<AccountSavings>("savings", -10.0, 5.0);
    cout << *p << endl;
  }
  catch (const IllegalBalanceException &e)
  {
    cerr << e.what() << endl;
  }

  return 0;
}