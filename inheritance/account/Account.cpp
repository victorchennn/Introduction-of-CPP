#include <iostream>
#include "Account.h"
#include "IllegalBalanceException.h"

using namespace std;

Account::Account(string name, double balance) : name{name}, balance{balance}
{
  if (balance < 0.0)
  {
    throw IllegalBalanceException{};
  }
}

bool Account::deposit(double amount)
{
  if (amount < 0)
  {
    return false;
  }
  balance += amount;
  return true;
}

bool Account::withdraw(double amount)
{
  if (balance - amount < 0)
  {
    return false;
  }
  balance -= amount;
  return true;
}

double Account::get_balance() const
{
  return balance;
}

ostream &operator<<(ostream &os, const Account &account)
{
  os << "Account: " << account.name << ": " << account.balance << endl;
  return os;
}