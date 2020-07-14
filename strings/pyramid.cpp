#include <iostream>
#include <string>

using namespace std;

int main()
{
  string letters{};
  cout << "Input: " << endl;
  getline(cin, letters);

  const size_t len = letters.length();
  int pos{0};

  for (char c : letters)
  {
    size_t spaces = len - pos;
    while (spaces > 0)
    {
      cout << " ";
      spaces--;
    }
    size_t i{0};
    while (i < pos)
    {
      cout << letters.at(i++);
    }
    cout << c;
    while (i > 0)
    {
      cout << letters.at(--i);
    }
    cout << endl;
    pos++;
  }

  return 0;
}