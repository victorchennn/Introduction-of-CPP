#include "Account.h"
#include <iostream>

using namespace std;

void Account::set_name(string n)
{
  name = n;
}

string Account::get_name()
{
  return name;
}

bool Account::deposit(double amount)
{
  balance += amount;
  cout << "balance: " << balance << endl;
  return true;
}

bool Account::withdraw(double amount)
{
  if (balance - amount >= 0)
  {
    balance -= amount;
    cout << "balance: " << balance << endl;
    return true;
  }
  else
  {
    cout << "invalid withdraw" << endl;
    return false;
  }
}

int main()
{
  Account ac;
  ac.set_name("Victor's account");
  ac.set_balance(1000);

  ac.deposit(200.0);
  ac.withdraw(500.0);
  ac.withdraw(1500);

  return 0;
}