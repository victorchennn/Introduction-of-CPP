#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Player
{
public:
  string name{"Player"};
  int health, xp;

  void talk(string text)
  {
    cout << name << " says " << text << endl;
  };
  bool is_dead();
};

class Account
{
public:
  string name;
  double balance;

  void deposit(double bal)
  {
    balance += bal;
    cout << "balance: " << balance << endl;
  }
  void withdraw(double bal)
  {
    balance -= bal;
    cout << "balance: " << balance << endl;
  }
};

int main()
{
  Player p1;
  Player p2;

  Player players[]{p1, p2};
  vector<Player> vec{p1};
  vec.push_back(p2);

  p1.name = "Victor";
  p1.health = 100;
  p1.xp = 16;
  p1.talk("Hi there");

  Player *enemy = new Player();
  (*enemy).name = "Enemy";
  (*enemy).health = 100;
  enemy->xp = 15;
  enemy->talk("I will destroy you!!");
  delete enemy;

  Account ac;
  ac.name = "Victor's account";
  ac.balance = 100.0;
  ac.deposit(100.5);
  ac.withdraw(50.5);

  return 0;
}