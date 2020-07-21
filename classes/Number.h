#ifndef _NUMBER_H_
#define _NUMBER_H_
#include <string>

class Number
{
private:
  std::string name;
  int health, xp;
  static int count;

public:
  Number(std::string name = "None");
  Number(const Number &source);
  ~Number();
  std::string get_name()
  {
    return name;
  }
  static int get_count();
};

#endif