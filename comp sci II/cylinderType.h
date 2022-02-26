#ifndef CYLINDERTYPE_H
#define CYLINDERTYPE_H

#include "circleType.h"
//private inheritance so that the protected variables may be inherited
class cylinderType : private circleType
{
private: 
	double height;
	double centerX;
	double centerY;
	double surfaceArea;
	double volume;
	circleType circle;
public:

	//default constructor of cylinderType
	cylinderType();

	//constructor of cylinderType that takes parameters
	cylinderType(double height, double centerX, double centerY, double baseRadius, double surfaceArea, double volume);

	//function to calculate Volume of the cylinder
	double getVolume();

	//function to output the volume of the cylinder
	void printVolume();

	//function to calculate surface area of the cylinder
	double getSurfaceArea();
	
	//function to output the volume of the cylinder
	void printSurfaceArea();

	//function to set the height of the cylinder
	void setHeight();

	//function to ask the user to input the radius of the base of the cylinder
	void setInputBaseRadius();

	//function to set the coordinates of the center point of the cylinder
	void setPoint();

	//function to output the coordinates of the center point of the cylinder
	void printCirclePoint();
};
#endif