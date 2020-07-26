#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <limits>

using namespace std;

int main()
{
  int num1{};
  double num2{};
  string name{};

  string info{"Victor 100 1.23"};
  istringstream iss{info};
  iss >> name >> num1 >> num2;
  cout << setw(10) << left << name
       << setw(5) << num1
       << setw(10) << num2 << endl;

  ostringstream oss{};
  oss << setw(10) << left << name
      << setw(5) << num1
      << setw(10) << num2 << endl;
  cout << oss.str() << endl;

  int value{};
  string entry{};
  bool done{false};
  do
  {
    cout << "enter an integer: ";
    cin >> entry;
    istringstream validator{entry};
    if (validator >> value)
    {
      done = true;
    }
    else
    {
      cout << "not an integer" << endl;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard the input buffer
  } while (!done);

  return 0;
}