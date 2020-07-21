#include <iostream>
#include "AccountSavings.h"

using namespace std;

AccountSavings::AccountSavings(string name, double balance, double rate) : Account{name, balance}, rate{rate} {}

bool AccountSavings::deposit(double amount)
{
  amount += (amount * rate / 100);
  return Account::deposit(amount);
}

ostream &operator<<(ostream &os, const AccountSavings &account)
{
  os << "Savings account: " << account.name << ": " << account.balance << ", " << account.rate << endl;
  return os;
}
