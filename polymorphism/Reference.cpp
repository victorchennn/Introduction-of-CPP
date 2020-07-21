#include <iostream>

using namespace std;

class Account
{
public:
  virtual ~Account()
  {
    cout << "Account::destructor" << endl;
  }
  virtual void withdraw(double amount)
  {
    cout << "In Account::withdraw" << endl;
  }
};

class Checking : public Account
{
public:
  virtual ~Checking() // unnecessary but recommended
  {
    cout << "Checking::destructor" << endl;
  }
  virtual void withdraw(double amount) // unnecessary but recommended
  {
    cout << "In Checking::withdraw" << endl;
  }
};

class Savings : public Account
{
public:
  virtual ~Savings()
  {
    cout << "Savings::destructor" << endl;
  }
  virtual void withdraw(double amount)
  {
    cout << "In Savings::withdraw" << endl;
  }
};

class Trust : public Account
{
public:
  virtual ~Trust()
  {
    cout << "Trust::destructor" << endl;
  }
  virtual void withdraw(double amount)
  {
    cout << "In Trust::withdraw" << endl;
  }
};

void doWithdraw(Account &account, double amount)
{
  account.withdraw(amount);
}

int main()
{
  Account a;
  Account &ref1 = a;
  ref1.withdraw(100);

  Trust t;
  Account &ref2 = t;
  ref2.withdraw(100);

  Account a1;
  Savings a2;
  Checking a3;
  Trust a4;

  doWithdraw(a1, 100);
  doWithdraw(a2, 100);
  doWithdraw(a3, 100);
  doWithdraw(a4, 100);

  return 0;
}