//implementation file for circleType class header file
#include "circleType.h"
#include "pointType.h"
#include <iostream>
#include <iomanip>
using namespace std;

//defined constructor that also calls the setRadius function
circleType::circleType(double r)
{
	setRadius(r);
}

//defined function that sets the radius using parameters passed by the defined circleType constructor
void circleType::setRadius(double r)
{
	if (r >= 0)
	{
		radius = r;
	}
	else
	{
		radius = 0;
	}
}

//defined function to output the radius of the circle
double circleType::getRadius()
{
	return radius;
}

//defined function to calculate the area of the circle
double circleType::getArea()
{
	return 3.1416 * radius * radius;
}

//defined function to calculate the circumference of the circle
double circleType::getCircumference()
{
	return 2 * 3.1416 * radius;
}

//defined function to request the user to input the radius of the circle
void circleType::setInputRadius()
{
	double r;
	cout << "Enter the radius of the circle: ";
	cin >> r;
	radius = r;
}

//defined function to request the user to input the coordinates of the circle
void circleType::setPoint()
{
	cout << "Enter the value of the X coordinate of the point: ";
	cin >> pointX;
	cout << "Enter the value of the Y coordinate of the point: ";
	cin >> pointY;
}

//defined function to obtain the X coordinate of the circle
double circleType::getPointX()
{
	return pointX;
}

//defined function to obtain the Y coordinate of the circle
double circleType::getPointY()
{
	return pointY;
}

//defined function to output the coordinates of the circle using the individual get functions of each
void circleType::printCirclePoint()
{
	cout << "   X: " << circleType::getPointX() << "   Y: " << circleType::getPointY() << endl;
}
