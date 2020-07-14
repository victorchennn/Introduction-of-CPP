#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
  for (int i{1}, j{5}; i <= 5; i++, j++)
  {
    cout << i << " * " << j << " = " << (i * j) << endl;
  }

  vector<int> nums{10, 20, 30, 40, 50};
  for (unsigned i{0}; i < nums.size(); i++)
  {
    cout << nums[i] << endl;
  }

  int scores[]{10, 20, 30};
  for (auto score : scores)
  {
    cout << "score: " << score << endl;
  }

  vector<double> temps{87.9, 77.9, 80.0, 72.5};
  double avg{}, total{};

  for (auto temp : temps)
  {
    total += temp;
  }
  if (temps.size() != 0)
  {
    avg = total / temps.size();
  }
  cout << fixed << setprecision(1);
  cout << "Average temp: " << avg << endl;

  for (auto c : "this is the test")
  {
    if (c == ' ')
    {
      cout << "\t";
    }
    else
    {
      cout << c;
    }
  }

  bool done{false};
  int num{0};
  while (!done)
  {
    cout << "\n-1Enter an integer between 1 and 5: " << endl;
    cin >> num;
    if (num <= 1 || num >= 5)
    {
      cout << "Out of range" << endl;
    }
    else
    {
      cout << "great!" << endl;
      done = true;
    }
  }

  return 0;
}