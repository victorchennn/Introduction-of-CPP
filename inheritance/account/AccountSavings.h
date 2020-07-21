#ifndef _ACCOUNTSAVINGS_H_
#define _ACCOUNTSAVINGS_H_
#include "Account.h"

class AccountSavings : public Account
{
  friend std::ostream &operator<<(std::ostream &os, const AccountSavings &account);

private:
  static constexpr const char *def_name = "Unnamed Savings Account";
  static constexpr double def_balance = 0.0;
  static constexpr double def_rate = 0.0;

protected:
  double rate;

public:
  AccountSavings(std::string name = def_name, double balance = def_balance, double rate = def_rate);
  bool deposit(double amount);
  // withdraw function is inherited
};

#endif