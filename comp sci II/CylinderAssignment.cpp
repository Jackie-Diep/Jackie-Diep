#include <iostream>
#include "circleType.h"
#include "pointType.h"
#include "cylinderType.h"
using namespace std;

int main()
{
	//create object cylinder of class cylinderType
	cylinderType cylinder;
	//functions to test the capabilities of the cylinderType class
	cylinder.setInputBaseRadius();
	cylinder.setHeight();
	cylinder.setPoint();
	cylinder.printCirclePoint();
	cylinder.getVolume();
	cylinder.printVolume();
	cylinder.getSurfaceArea();
	cylinder.printSurfaceArea();
}
