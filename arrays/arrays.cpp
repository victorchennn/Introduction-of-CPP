#include <iostream>

using namespace std;

int main()
{
  char vowels[]{'a', 'e', 'i', 'o', 'u'};
  cout << "The first vowel is: " << vowels[0] << endl;
  cout << "The last vowel is: " << vowels[4] << endl;
  cout << vowels[5] << endl;

  double temps[]{90.1, 89.8, 77.5, 81.6};
  cout << "The first temp is: " << temps[0] << endl;
  temps[0] = 100.7;
  cout << "The first temp is: " << temps[0] << endl;

  int scores[5]; // junk data
  // int scores[5]{}; // initialized 0
  // int scores[5]{100}; // first index is 100, left are 0
  cout << "index 0: " << scores[0] << endl;
  cout << "index 1: " << scores[1] << endl;
  cout << "index 2: " << scores[2] << endl;
  cout << "index 3: " << scores[3] << endl;
  cout << "index 4: " << scores[4] << endl;

  cout << "Enter 5 scores: " << endl;
  cin >> scores[0];
  cin >> scores[1];
  cin >> scores[2];
  cin >> scores[3];
  cin >> scores[4];

  cout << "updated scores: " << endl;
  cout << "index 0: " << scores[0] << endl;
  cout << "index 1: " << scores[1] << endl;
  cout << "index 2: " << scores[2] << endl;
  cout << "index 3: " << scores[3] << endl;
  cout << "index 4: " << scores[4] << endl;

  int movies[3][4]{{0, 4, 3, 5}, {2, 3, 42, 5}, {1, 4, 4, 5}};
  cout << "Row 1 Col 2 is: " << movies[1][2] << endl;

  return 0;
}