#include <iostream>
#include <cmath>
#include <cstdlib> // required for rand()
#include <ctime>   // required for time()

using namespace std;

int main()
{
  double num{};
  cout << "Enter a double number: ";
  cin >> num;

  cout << "sqrt: " << sqrt(num) << endl;
  cout << "cubed root: " << cbrt(num) << endl;
  cout << "sine: " << sin(num) << endl;
  cout << "cosine: " << cos(num) << endl;
  cout << "ceil: " << ceil(num) << endl;
  cout << "floor: " << floor(num) << endl;
  cout << "round: " << round(num) << endl;
  cout << "squared: " << pow(num, 2) << endl;
  cout << "\n===================\n"
       << endl;

  const int min(1), max(10);
  cout << "RAND_MAX is: " << RAND_MAX << endl;
  srand(time(nullptr));

  for (size_t i{1}; i <= 5; i++)
  {
    cout << (rand() % max + min) << endl;
  }

  return 0;
}
