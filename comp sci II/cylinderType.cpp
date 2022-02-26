//implementation file for cylinderType class header file
#include "circleType.h"
#include "cylinderType.h"
#include <iomanip>
#include <iostream>
using namespace std;
//defined default constructor for cylinderType
cylinderType::cylinderType()
{
	height = 0;
	centerX = 0;
	centerY = 0;
	radius = 0;
	surfaceArea = 0;
	volume = 0;
}
//defined constructor that initializes parameters
cylinderType::cylinderType(double h, double x, double y, double r, double a, double v)
{
	height = h;
	centerX = x;
	centerY = y;
	radius = r;
	surfaceArea = a;
	volume = v;
}
//defined function to calculate volume
double cylinderType::getVolume()
{
	volume = 3.1416 * radius * radius * height;
	return volume;
}
//defined function to output volume
void cylinderType::printVolume()
{
	cout << "\nThe volume of the cylinder in feet is: " << volume << endl;
}
//defined function to calculate surface area
double cylinderType::getSurfaceArea()
{
	surfaceArea = 2 * 3.1416 * radius * height + 2 * 3.1416 * radius * radius;
	return surfaceArea;
}
//defined function to output surface area
void cylinderType::printSurfaceArea()
{
	cout << "\nThe surface area of the cylinder in feet is: " << surfaceArea << endl;
}
//defined function to set height of the cylinder
void cylinderType::setHeight()
{
	cout << "Enter the height of the cylinder in feet: ";
	cin >> height;
}
//defined function to input base radius
void cylinderType::setInputBaseRadius()
{
	double r;
	cout << "Enter the base radius of the circle in feet: ";
	cin >> r;
	radius = r;
}
//defined function to set the coordinates of the center point of the cylinder using the circleType class function
void cylinderType::setPoint()
{
	circle.circleType::setPoint();
}
//defined function to output the coordinates of the center point of the cylinder using the circleType class function
void cylinderType::printCirclePoint()
{
	cout << "\nThe coordinates of the base of the center of the cylinder are:";
	circle.circleType::printCirclePoint();
}