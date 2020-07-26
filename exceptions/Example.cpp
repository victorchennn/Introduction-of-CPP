/**
 * @file check inheritance/account Account.cpp and main.cpp
 */

#include <iostream>
#include <string>

using namespace std;

class DivideByZeroException
{
};
class NegativeValueException
{
};

double calculate_mpg(int miles, int gallons)
{
  if (gallons == 0)
  {
    throw DivideByZeroException();
  }
  if (miles < 0 || gallons < 0)
  {
    throw NegativeValueException();
  }
  return static_cast<double>(miles) / gallons;
}

int main()
{
  int miles{}, gallons{};
  double miles_per_gallons{};

  cout << "Enter the miles: " << endl;
  cin >> miles;
  cout << "Enter the gallons: " << endl;
  cin >> gallons;

  try
  {
    miles_per_gallons = calculate_mpg(miles, gallons);
    cout << "Result: " << miles_per_gallons << endl;
  }
  catch (const DivideByZeroException &e)
  {
    cerr << "Divided by zero" << endl;
  }
  catch (const NegativeValueException &e)
  {
    cerr << "Negative value" << endl;
  }
  catch (...)
  {
    cerr << "Unknown exception" << endl;
  }

  return 0;
}