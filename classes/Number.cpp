#include "Number.h"
#include <iostream>

using namespace std;

int Number::count{0};

Number::Number(std::string name) : name{name}
{
  count++;
}

Number::Number(const Number &source) : Number{source.name} {}

Number::~Number()
{
  count--;
}

int Number::get_count()
{
  return count;
}

void display_number()
{
  cout << Number::get_count() << endl;
}

int main()
{
  display_number();
  Number n0{"0"};
  display_number();

  {
    Number n1{"1"};
    display_number();
  }
  display_number();

  return 0;
}