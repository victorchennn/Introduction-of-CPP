#include <iostream>
#include <vector>

using namespace std;

int main()
{
  // vector<char> vowels;    // empty
  // vector<char> vowels(5); // initialized
  vector<char> vowels{'a', 'e', 'i', 'o', 'u'};

  cout << "index 0 is: " << vowels[0] << endl;
  cout << "index 4 is: " << vowels[4] << endl;

  // vector<int> scores(3); // initialized to 0
  // vector<int> scores(3, 100); // initialized to 100
  vector<int> scores{100, 90, 80};
  cout << "the first score is: " << scores[0] << endl;    // array syntax
  cout << "the first score is: " << scores.at(0) << endl; // vector syntax
  cout << "size of the vector: " << scores.size() << endl;

  cout << "Enter 3 scores: " << endl;
  cin >> scores.at(0);
  cin >> scores.at(1);
  cin >> scores.at(2);

  cout << "updated scores: " << endl;
  cout << "index 0: " << scores.at(0) << endl;
  cout << "index 1: " << scores.at(1) << endl;
  cout << "index 2: " << scores.at(2) << endl;

  cout << "Enter a new score: " << endl;
  int new_score{0};
  cin >> new_score;
  scores.push_back(new_score);

  cout << "Enter a new score: " << endl;
  cin >> new_score;
  scores.push_back(new_score);

  cout << "scores: " << endl;
  cout << "index 0: " << scores.at(0) << endl;
  cout << "index 1: " << scores.at(1) << endl;
  cout << "index 2: " << scores.at(2) << endl;
  cout << "index 3: " << scores.at(3) << endl;
  cout << "index 4: " << scores.at(4) << endl;
  cout << "size of the vector: " << scores.size() << endl;

  vector<vector<int>> movies{{1, 2, 3, 4}, {4, 5, 2, 1}, {6, 7, 8, 9}};
  cout << "(2,3): " << movies[2][3] << endl;       // array syntax
  cout << "(2,3): " << movies.at(2).at(3) << endl; // vector syntax

  return 0;
}