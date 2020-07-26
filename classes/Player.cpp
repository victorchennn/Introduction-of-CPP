#include <iostream>
#include <string>

using namespace std;

class Player
{
private:
  string name{"Player"};
  int health, xp;

public:
  void set_name(string n)
  {
    name = n;
  }
  string get_name() const
  {
    return name;
  }
  int get_health() const
  {
    return health;
  }
  int get_xp() const
  {
    return xp;
  }

  Player(string name = "None", int health = 0, int xp = 0); // default
  Player(const Player &source);
  ~Player()
  {
    cout << "destructor called!" << endl;
  }
};

Player::Player(string name, int health, int xp) : name{name}, health{health}, xp{xp}
{
  cout << "constructor called!" << endl;
  cout << name << "," << health << "," << xp << endl;
}

Player::Player(const Player &source) : Player{source.name, source.health, source.xp}
{
  cout << "copy constructor called!" << endl;
}

void display_player(Player p)
{
  cout << "Name: " << p.get_name() << endl;
  cout << "Health: " << p.get_health() << endl;
  cout << "XP: " << p.get_xp() << endl;
}

// since variable const Player cp{"cp"} is const, so parameter should also be const
// if not using &p, function will call copy constructor
void display_player_name(const Player &p)
{
  cout << p.get_name() << endl;
}

int main()
{
  {
    Player p0;          // None, 0, 0
    display_player(p0); // copy constructor called

    Player p1("p1");          // p1, 0, 0
    Player p2("p2", 100, 16); // p2, 100, 16
    Player p2_1{p2};          // copy constructor called
  }

  Player *enemy = new Player;                   // None, 0, 0
  Player *boss = new Player("boss", 1000, 100); // boss, 1000, 100
  delete enemy;
  delete boss;

  const Player cp{"cp"};
  display_player_name(cp); // automatically called destructor
  const Player *cpp = new Player("cpp");
  display_player_name(*cpp);
  delete cpp; // self called destructor

  return 0;
}