#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

bool isPalindrome(const std::string &s)
{
  std::deque<char> d;
  for (char c : s)
  {
    if (std::isalpha(c))
    {
      d.push_back(std::tolower(c));
    }
  }
  char c1{}, c2{};
  while (d.size() > 1)
  {
    c1 = d.front();
    c2 = d.back();
    d.pop_back();
    d.pop_front();
    if (c1 != c2)
    {
      return false;
    }
  }
  return true;
}

int main()
{
  std::cout << std::boolalpha;
  std::cout << isPalindrome("abc") << std::endl;
  std::cout << isPalindrome("acbca") << std::endl;
  std::cout << isPalindrome("acbcA") << std::endl;

  return 0;
}
