#include <iostream>

using namespace std;

// function prototypes
double calc_area_circle(double);
void area_circle();
double calc_volume_cylinder(double radius, double height);
void volume_cylinder();

const double pi{3.1415926};

int main()
{
  area_circle();
  volume_cylinder();
  return 0;
}

double calc_area_circle(double radius)
{
  return pi * radius * radius;
}

void area_circle()
{
  double radius{};
  cout << "Enter the radius of the circle: ";
  cin >> radius;
  cout << "The area of a circle with radius " << radius << " is " << calc_area_circle(radius) << endl;
}

double calc_volume_cylinder(double radius, double height)
{
  return calc_area_circle(radius) * height;
}

void volume_cylinder()
{
  double radius{}, height{};
  cout << "Enter the radius and the height: " << endl;
  cin >> radius >> height;
  cout << "The volume of a cylinder with radius" << radius << " and height " << height << " is " << calc_volume_cylinder(radius, height) << endl;
}