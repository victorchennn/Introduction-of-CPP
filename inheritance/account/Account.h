#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>

class Account
{
  friend std::ostream &operator<<(std::ostream &os, const Account &account);

private:
  static constexpr const char *def_name = "Unnamed Account";
  static constexpr double def_balance = 0.0;

protected:
  double balance;
  std::string name;

public:
  Account(std::string name = def_name, double balance = def_balance);
  bool deposit(double amount);
  bool withdraw(double amount);
  double get_balance() const;
};

#endif