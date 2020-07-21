#include "Global.h"
#include <cstring>

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

bool operator==(const Mystring &lhs, const Mystring &rhs)
{
  return (strcmp(lhs.str, rhs.str) == 0);
}

Mystring operator-(const Mystring &obj)
{
  char *buff = new char[strlen(obj.str) + 1];
  strcpy(buff, obj.str);
  for (size_t i{0}; i < strlen(buff); i++)
  {
    buff[i] = tolower(buff[i]);
  }
  Mystring temp{buff};
  delete[] buff;
  return temp;
}

Mystring operator+(const Mystring &lhs, const Mystring &rhs)
{
  char *buff = new char[strlen(lhs.str) + strlen(rhs.str) + 1];
  strcpy(buff, lhs.str);
  strcat(buff, rhs.str);
  Mystring temp{buff};
  delete[] buff;
  return temp;
}

ostream &operator<<(ostream &os, const Mystring &rhs)
{
  os << rhs.str;
  return os;
}

istream &operator>>(istream &in, Mystring &rhs)
{
  char *buff = new char[1000];
  in >> buff;
  rhs = Mystring{buff};
  delete[] buff;
  return in;
}

int main()
{
  cout << boolalpha << endl;
  Mystring victor{"Victor"};
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
  // but with non-member func it works.
  add = "hello" + rina;

  Mystring add2 = rina + " " + "hello";
  add2.display();

  Mystring add3 = rina + " " + victor + " " + "hello";
  add3.display();

  Mystring name;
  cout << "Enter the first name: ";
  cin >> name;
  cout << "The name is: " << name << endl;

  return 0;
}