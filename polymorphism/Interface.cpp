#include <iostream>

using namespace std;

class I_Printable
{
  friend ostream &operator<<(ostream &os, const I_Printable &obj);

public:
  virtual void print(ostream &os) const = 0;
};

ostream &operator<<(ostream &os, const I_Printable &obj)
{
  obj.print(os);
  return os;
}

class Account : public I_Printable
{
public:
  virtual ~Account() {}
  virtual void withdraw(double amount)
  {
    cout << "In Account::withdraw" << endl;
  }
  virtual void print(ostream &os) const override
  {
    os << "Account display";
  }
};

class Checking : public Account
{
public:
  virtual ~Checking() {}
  virtual void withdraw(double amount) override
  {
    cout << "In Checking::withdraw" << endl;
  }
  virtual void print(ostream &os) const override
  {
    os << "Checking display";
  }
};

int main()
{
  Account *p1 = new Account();
  cout << *p1 << endl;

  Account *p2 = new Checking();
  cout << *p2 << endl;

  return 0;
}