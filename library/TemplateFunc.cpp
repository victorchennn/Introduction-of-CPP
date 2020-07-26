#include <iostream>
#include <string>

template <typename T>
T min(T a, T b)
{
  return (a < b) ? a : b;
}

template <class T1, class T2>
void display(T1 a, T2 b)
{
  std::cout << a << " " << b << std::endl;
}

template <typename T>
void swap(T &a, T &b)
{
  T temp = a;
  a = b;
  b = temp;
}

struct Person
{
  std::string name;
  int age;
  bool operator<(const Person &rhs) const
  {
    return this->age < rhs.age;
  }
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
  os << p.name;
  return os;
}

int main()
{
  std::cout << min<int>(2, 3) << std::endl;
  std::cout << min(2, 3) << std::endl;
  std::cout << min('A', 'B') << std::endl;
  std::cout << min(12.5, 1.25) << std::endl;
  std::cout << min(5 + 2 * 2, 7 + 40) << std::endl;
  Person p1{"Victor", 12}, p2{"Rina", 8};
  Person p3 = min(p1, p2);
  std::cout << p3.name << std::endl;

  std::cout << std::endl;
  display<int, int>(10, 20);
  display(10, 20);
  display<char, double>('A', 12.5);
  display('A', 12.5);
  display(100, "Testing");
  display(1000, std::string{"Victor"});
  display(p1, p2);

  int x{1}, y{2};
  char a{'a'}, b{'b'};
  std::cout << x << ", " << y << std::endl;
  swap(x, y);
  std::cout << x << ", " << y << std::endl;
  std::cout << a << ", " << b << std::endl;
  swap(a, b);
  std::cout << a << ", " << b << std::endl;

  return 0;
}
