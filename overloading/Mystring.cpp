#include "Mystring.h"
#include <iostream>
#include <cstring>

using namespace std;

Mystring::Mystring() : str(nullptr)
{
  str = new char[1];
  *str = '\0';
}

Mystring::Mystring(const char *s) : str{nullptr}
{
  if (s == nullptr)
  {
    str = new char[1];
    *str = '\0';
  }
  else
  {
    str = new char[strlen(s) + 1];
    strcpy(str, s);
  }
}

Mystring::Mystring(const Mystring &source) : str{nullptr}
{
  str = new char[strlen(source.str) + 1];
  strcpy(str, source.str);
}

Mystring::Mystring(Mystring &&source) : str{source.str}
{
  cout << "Move constructor" << endl;
  source.str = nullptr;
}

Mystring::~Mystring()
{
  delete[] str;
}

Mystring &Mystring::operator=(const Mystring &rhs)
{
  cout << "Copy assignment" << endl;
  if (this == &rhs)
  {
    return *this;
  }
  delete[] this->str;
  str = new char[strlen(rhs.str) + 1];
  strcpy(this->str, rhs.str);
  return *this;
}

Mystring &Mystring::operator=(Mystring &&rhs)
{
  cout << "Move assignment" << endl;
  if (this == &rhs)
  {
    return *this;
  }
  delete[] this->str;
  str = rhs.str;
  rhs.str = nullptr;
  return *this;
}

bool Mystring::operator==(const Mystring &rhs) const
{
  return (strcmp(str, rhs.str) == 0);
}

Mystring Mystring::operator-() const
{
  char *buff = new char[strlen(str) + 1];
  strcpy(buff, str);
  for (size_t i{0}; i < strlen(buff); i++)
  {
    buff[i] = tolower(buff[i]);
  }
  Mystring temp{buff};
  delete[] buff;
  return temp;
}

Mystring Mystring::operator+(const Mystring &rhs) const
{
  char *buff = new char[strlen(str) + strlen(rhs.str) + 1];
  strcpy(buff, str);
  strcat(buff, rhs.str);
  Mystring temp{buff};
  delete[] buff;
  return temp;
}

void Mystring::display() const
{
  cout << str << " : " << get_length() << endl;
}

int Mystring::get_length() const
{
  return strlen(str);
}

const char *Mystring::get_str() const
{
  return str;
}

int main()
{
  Mystring empty;
  Mystring victor{"Victor"};
  Mystring cp{victor};

  empty.display();
  victor.display();
  cp.display();

  Mystring a{"Hello"};
  Mystring b;
  b = a; // copy assignment

  Mystring c{"C"};
  c = Mystring{"C++"}; // move assignment
  c = "C++!";          // move assignment

  cout << boolalpha << endl;
  Mystring rina{"Rina"};
  Mystring chen{"Chen"};
  Mystring temp = rina;
  rina.display();
  chen.display();

  cout << (rina == chen) << endl;
  cout << (rina == temp) << endl;

  rina.display();
  Mystring rina2 = -rina;
  rina2.display();

  Mystring add = rina + "hello";
  add.display();

  // error with member func, since "hello" is not a Mystring object,
  // but with non-member func it works, @see Global.cpp
  // Mystring add = "hello" + rina;

  Mystring add2 = rina + " " + "hello";
  add2.display();

  Mystring add3 = rina + " " + victor + " " + "hello";
  add3.display();

  return 0;
}