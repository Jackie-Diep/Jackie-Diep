#ifndef POINTTYPE_H
#define POINTTYPE_H
//pointType class header file
class pointType
{
	//protected so they will be inherited by circleType as private variables
protected:

	//initialize pointX and pointY to set the point of the center circle for cylinderType
	double pointX;
	double pointY;

public:
	//default constructor
	pointType();

	//constructor with two parameters
	pointType(double pointX, double pointY);

	//functions to print the coordinates of the point
	void printPoint();

	//functions to set the coordinates of the point
	void setX(double);
	void setY(double);

	//functions to get the coordinates of the point
	double getX();
	double getY();
};
#endif