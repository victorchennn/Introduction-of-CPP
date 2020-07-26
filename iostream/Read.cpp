#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  ifstream file;
  string word;
  int num1;
  double num2;

  file.open("text.txt");
  if (!file)
  {
    cerr << "problem opening file" << endl;
    return 1;
  }
  cout << "file is good to go" << endl;
  while (file >> word >> num1 >> num2) // while(!file.eof())
  {
    cout << setw(10) << left << word;
    cout << setw(10) << num1;
    cout << num2 << endl;
  }
  cout << endl;
  file.close();

  ifstream poem{"poem.txt"};
  if (!poem)
  {
    cerr << "problem opening file" << endl;
    return 1;
  }

  string line{};
  while (getline(poem, line))
  {
    cout << line << endl;
  }

  // or:
  //
  // char c{};
  // while (poem.get(c))
  // {
  //   cout << c;
  // }

  poem.close();

  return 0;
}