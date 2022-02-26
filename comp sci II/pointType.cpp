//implementation file for pointType class header file
#include "pointType.h"
#include <iostream>
#include <iomanip>
using namespace std;

//defined default constructor
pointType::pointType()
{
	pointX = 0;
	pointY = 0;
}
//defined constructor taking two parameters
pointType::pointType(double x, double y)
{
	pointX = x;
	pointY = y;
}
//defined function to print the coordinates of the point
void pointType::printPoint()
{
	cout << "X: " << fixed << setprecision(2) << pointX << endl;
	cout << "Y: " << fixed << setprecision(2) << pointY << endl;
}
//defined function to set the x coordinate of the point
void pointType::setX(double x)
{
	pointX = x;
}
//defined function to set the y coordinate of the point
void pointType::setY(double y)
{
	pointY = y;
}
//defined function to get the x coordinate of the point
double pointType::getX()
{
	return pointX;
}
//defined function to get the y coordinate of the point
double pointType::getY()
{
	return pointY;
}
