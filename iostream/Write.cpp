#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  ifstream poem{"poem.txt"};
  ofstream poem_copy{"poem_copy.txt", ios::app}; // default truncated
  if (!poem || !poem_copy)
  {
    cerr << "error opening file" << endl;
    return 1;
  }
  string line{};
  while (getline(poem, line))
  {
    poem_copy << line << endl;
  }

  // char c{};
  // while (poem.get(c))
  // {
  //   poem_copy.put(c);
  // }

  cout << "poem copied!" << endl;
  poem.close();
  poem_copy.close();

  return 0;
}