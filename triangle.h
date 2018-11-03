#ifndef TRIANGLEH
#define TRIANGLEH

class Polygon //Abstract class
{
public:
  virtual void draw() = 0;                    //Pure virtual function
  virtual double area() = 0;                  //Pure virtual function
  virtual bool hasGreaterArea(Polygon *) = 0; //Pure virtual function

  static void addToArrRect(std::vector<Polygon *> &arr);
  static void addToArrCirc(std::vector<Polygon *> &arr);

};

class Point
{
public:
  Point(double x, double y) : x(x), y(y) { /*std::cout << "Ctor-Point" << std::endl; */}
  double getX() const { return x; }
  double getY() const { return y; }

private:
  const double x;
  const double y;
};
//class Cricle
class Circle : public Polygon
{
public:
  Circle(Point p, double radius, int numVertex) : p(p), radius(radius), numVertex(numVertex) { /*std::cout << "Ctor-Circle" << std::endl;*/ }

  Point getP() const { return p; }
  double getRadius() const { return radius; }

  void draw();
  double area();

  bool hasGreaterArea(Polygon *);

private:
  const Point p;
  const double radius;
  const int numVertex;
};
//class Rectangle
class Rectangle : public Polygon
{
public:
  Rectangle(Point p4, Point p5, Point p6, Point p7) : p4(p4), p5(p5), p6(p6), p7(p7) { /*std::cout << "Ctor-Rectangle" << std::endl;*/ }

  void draw();
  double area();

  bool hasGreaterArea(Polygon *);

private:
  const Point p4;
  const Point p5;
  const Point p6;
  const Point p7;
};
//class Triangle
class Triangle : public Polygon
{
public:
  Triangle(Point p1, Point p2, Point p3) : p1(p1), p2(p2), p3(p3) { /*std::cout << "Ctor-Triangle" << std::endl;*/ }

  void draw();
  double area();

  bool hasGreaterArea(Polygon *);

private:
  const Point p1;
  const Point p2;
  const Point p3;
};
class Rhombus : public Polygon
{
public:
  Rhombus(Point p13, Point p14, Point p15, Point p16) : p13(p13), p14(p14), p15(p15), p16(p16) { std::cout << "Ctor-Triangle" << std::endl; }

  void draw();
  double area();

   bool hasGreaterArea(Polygon *);

private:
  const Point p13;
  const Point p14;
  const Point p15;
  const Point p16;
};
//class Square
class Square : public Rectangle
{
public:
  Square(Point p9, Point p10, Point p11, Point p12)
      : Rectangle(p9, p10, p11, p12) { /*std::cout << "Ctor-Square" << std::endl;*/ }
};
#endif //TRIANGLEH