#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <iostream>

using namespace std;

class Mystring
{
  friend bool operator==(const Mystring &lhs, const Mystring &rhs);
  friend Mystring operator-(const Mystring &obj);
  friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);

  friend ostream &operator<<(ostream &os, const Mystring &rhs);
  friend istream &operator>>(istream &in, Mystring &rhs);

private:
  char *str;

public:
  Mystring();
  Mystring(const char *s);
  Mystring(const Mystring &source); // copy constructor
  Mystring(Mystring &&source);      // move constructor
  ~Mystring();

  Mystring &operator=(const Mystring &rhs); // copy assignment
  Mystring &operator=(Mystring &&rhs);      // move assignment

  void display() const;
  int get_length() const;
  const char *get_str() const;
};

#endif