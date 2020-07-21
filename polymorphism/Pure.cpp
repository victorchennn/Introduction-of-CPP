#include <iostream>
#include <vector>

using namespace std;

class Shape // abstract base class
{
public:
  virtual ~Shape() {}
  virtual void draw() = 0;   // pure virtual function
  virtual void rotate() = 0; // pure virtual function
};

class ShapeOpen : public Shape // abstract class
{
public:
  virtual ~ShapeOpen() {}
};

class ShapeClosed : public Shape // abstract class
{
public:
  virtual ~ShapeClosed() {}
};

class Line : public ShapeOpen // Concrete class
{
public:
  virtual ~Line() {}
  virtual void draw() override
  {
    cout << "Drawing a line" << endl;
  }
  virtual void rotate() override
  {
    cout << "Rotating a line" << endl;
  }
};

class Circle : public ShapeClosed // Concrete class
{
public:
  virtual ~Circle() {}
  virtual void draw() override
  {
    cout << "Drawing a circle" << endl;
  }
  virtual void rotate() override
  {
    cout << "Rotating a circle" << endl;
  }
};

class Square : public ShapeClosed // Concrete class
{
public:
  virtual ~Square() {}
  virtual void draw() override
  {
    cout << "Drawing a square" << endl;
  }
  virtual void rotate() override
  {
    cout << "Rotating a square" << endl;
  }
};

int main()
{
  // Shape s; // error
  // Shape *p = new Shape(); // error

  Shape *s1 = new Line();
  Shape *s2 = new Circle();
  Shape *s3 = new Square();

  vector<Shape *> shapes{s1, s2, s3};
  for (const auto s : shapes)
  {
    s->draw();
    s->rotate();
  }

  delete s1;
  delete s2;
  delete s3;

  return 0;
}