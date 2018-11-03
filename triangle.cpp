#include <cmath>
#include <iostream>
#include <vector>
#include "triangle.h"
#include "sl.h"

void Triangle::draw()
{
    slLine(p1.getX(), p1.getY(), p2.getX(), p2.getY());
    slLine(p2.getX(), p2.getY(), p3.getX(), p3.getY());
    slLine(p3.getX(), p3.getY(), p1.getX(), p1.getY());
}

void Rectangle::draw()
{
    slLine(p4.getX(), p4.getY(), p5.getX(), p5.getY());
    slLine(p5.getX(), p5.getY(), p6.getX(), p6.getY());
    slLine(p6.getX(), p6.getY(), p7.getX(), p7.getY());
    slLine(p7.getX(), p7.getY(), p4.getX(), p4.getY());
}

void Circle::draw()
{
    slCircleOutline(p.getX(), p.getY(), radius, numVertex);
}

double Rectangle::area()
{

    return (fabs(p5.getX() - p4.getX())) * (fabs((p7.getY() - p4.getY())));
}

double Triangle::area()
{
    double area = fabs(p1.getX() * p2.getY() + p2.getX() * p3.getY() - p1.getX() * p3.getY() - p3.getX() * p2.getY() - p2.getX() * p1.getY());

    return area / 2;
}
double Rhombus::area()
{
    double a = fabs(p14.getX() - p13.getX());
    double h = fabs(p16.getY() - p13.getY());

    return a * h;
}
void Rhombus::draw()
{
    slLine(p13.getX(), p13.getY(), p14.getX(), p14.getY());
    slLine(p14.getX(), p14.getY(), p15.getX(), p15.getY());
    slLine(p15.getX(), p15.getY(), p16.getX(), p16.getY());
    slLine(p16.getX(), p16.getY(), p13.getX(), p13.getY());
}
bool Rhombus::hasGreaterArea(Polygon *e5)
{
    if (this->area() > e5->area())
        return true;
    else
        return false;
}
double Circle::area()
{
    return 3.14 * pow(getRadius(), 2);
}

bool Rectangle::hasGreaterArea(Polygon *e1)
{
    if (this->area() > e1->area())
        return true;
    else
        return false;
}
bool Circle::hasGreaterArea(Polygon *e3)
{
    if (this->area() > e3->area())
        return true;
    else
        return false;
}
bool Triangle::hasGreaterArea(Polygon *e3)
{
    if (this->area() > e3->area())
        return true;
    else
        return false;
}
void Polygon::addToArrRect(std::vector<Polygon *> &arr)
{

    Point p1(slGetMouseX() - 50, slGetMouseY() - 50);
    Point p2(slGetMouseX() + 50, slGetMouseY() - 50);
    Point p3(slGetMouseX() + 50, slGetMouseY() + 50);
    Point p4(slGetMouseX() - 50, slGetMouseY() + 50);

    Polygon *ptr = new Square(p1, p2, p3, p4);
    arr.push_back(ptr);
};
void Polygon::addToArrCirc(std::vector<Polygon *> &arr)
{
    Point p(slGetMouseX() - 50, slGetMouseY() - 50);

    Polygon *ptr = new Circle(p, 50, 50);
    arr.push_back(ptr);
};
