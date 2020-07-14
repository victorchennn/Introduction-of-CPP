#include <iostream>

using namespace std;

int main()
{
  char grade{};
  cout << "Enter the letter grade: " << endl;
  cin >> grade;

  switch (grade)
  {
  case 'a':
  case 'A':
    cout << "A!" << endl;
    break;
  case 'b':
  case 'B':
    cout << "B!!" << endl;
    break;
  case 'c':
  case 'C':
    cout << "C!!!" << endl;
    break;
  case 'f':
  case 'F':
  {
    char confirm{};
    cout << "Are you sure (Y/N)" << endl;
    cin >> confirm;
    if (confirm == 'y' || confirm == 'Y')
    {
      cout << "F..." << endl;
    }
    else if (confirm == 'n' || confirm == 'N')
    {
      cout << "F???" << endl;
    }
    else
    {
      cout << "invalid" << endl;
    }
    break;
  }
  default:
    cout << "impossible" << endl;
  }

  enum Color
  {
    green,
    red,
    yellow
  };
  Color col{green};
  switch (col)
  {
  case green:
    cout << "green" << endl;
    break;
  case red:
    cout << "red" << endl;
    break;
  default:
    cout << "yellow" << endl;
    break;
  }

  return 0;
}