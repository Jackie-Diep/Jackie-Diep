#ifndef CIRCLETYPE_H
#define CIRCLETYPE_H
//include pointType.h
#include "pointType.h"

//circleType class header file

//Defined by textbook
//private inheritance so that the protected variables may be inherited
class circleType : private pointType
{
	//protected so that class cylinderType may inherit them as private variables
protected:
	double radius;
	pointType point;
public:
	void setRadius(double r);
	//Function to set the radius.
	//Postcondition: if (r >= 0)  radius = r;
	//					otherwise radius = 0;

	double getRadius();
	//Function to return the radius.
	//Postcondition: The value of radius is returned.

	double getArea();
	//Function to return the area of a circle.
	//Postcondition: Area is calculated and returned.

	double getCircumference();
	//Function to return the circumference of a circle.
	//Postcondition: Circumference is calculated and retruned.

	circleType(double r = 0);
	//Constructor with a default parameter.
	//Radius is set according to the parameter.
	//The default value of the radius is 0.0;
	//Postcondition: radius = r;

	//function to request the user to input the radius of the circle
	void setInputRadius();

	//function to set the coordinates of the center of the circle
	void setPoint();

	//functions to obtain the coordinates of the center of the circle individually
	double getPointX();
	double getPointY();

	//function to output the center coordinates of the circle
	void printCirclePoint();
};
#endif