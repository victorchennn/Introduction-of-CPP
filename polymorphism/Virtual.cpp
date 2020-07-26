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

int main()
{
  Account *p1 = new Account();
  Account *p2 = new Checking();
  Account *p3 = new Savings();
  Account *p4 = new Trust();

  p1->withdraw(100);
  p2->withdraw(100);
  p3->withdraw(100);
  p4->withdraw(100);

  delete p1;
  delete p2; // call base destructor then
  delete p3; // call base destructor then
  delete p4; // call base destructor then

  return 0;
}