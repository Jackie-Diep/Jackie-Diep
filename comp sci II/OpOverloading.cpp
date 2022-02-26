// OpOverloading.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Jackie Diep
CSC 102 November 2019
A program that overloads operators within the rectangleType class and displays the capabilities of them.
*/
#include "rectangleType.h"
#include <iostream>
using namespace std;

int main()
{
		//Construct objects rectangle and rectangleTwo using the default constructor and the constructor that takes parameters respectively
	rectangleType rectangle;	
	rectangle.setDimension(12, 5);
	rectangleType rectangleTwo(6, 4);

		//Display dimensions of both rectangles for comparison purposes
	cout << "Original dimensions: " << endl;
	rectangle.displayDimensions();
	cout << "\nDimensions of rectangle two: " << endl;
	rectangleTwo.displayDimensions();

		//Display the capabilities of the overloaded addition operator
	rectangle.setDimension(12, 5);
	rectangle = rectangle + rectangleTwo;
	cout << "\nAdding the second rectangle to the first: " << endl;
	rectangle.displayDimensions();

		//Display the capabilities of the overloaded subtraction operator
	rectangle.setDimension(12, 5);
	rectangle = rectangle - rectangleTwo;
	cout << "\nSubtracting the second rectangle from the first: " << endl;
	rectangle.displayDimensions();

		//Example of invalid subtraction
	rectangle.setDimension(1, 1);
	cout << "\nExample of a subtraction with negative results: " << endl;
	cout << "Rectangle with length: 1 and width: 1 subtracted by rectangle two: " << endl;
	rectangle = rectangle - rectangleTwo;

		//Display the capabilities of the overloaded multiplication operator
	rectangle.setDimension(12, 5);
	rectangle = rectangle * rectangleTwo;
	cout << "\nMultiplying rectangle one by rectangle two: " << endl;
	rectangle.displayDimensions();

		//Display the capabilities of the overloaded division operator
	rectangle.setDimension(12, 5);
	rectangle = rectangle / rectangleTwo;
	cout << "\nDividing rectangle one by rectangle two: " << endl;
	rectangle.displayDimensions();

		//Display the capabilities of the overloaded increment operator
	rectangle.setDimension(12, 5);
	++rectangle;
	cout << "\nIncremented dimensions: " << endl;
	rectangle.displayDimensions();
	
		//Display the capabilities of the overloaded decrement operator
	rectangle.setDimension(12, 5);
	--rectangle;
	cout << "\nDecremented dimensions: " << endl;
	rectangle.displayDimensions();

		//Display the capabilities of the overloaded equality operator
	rectangle.setDimension(12, 5);
	cout << "\nChecking for equality: ";
	if (rectangle == rectangleTwo)
	{
		cout << "\nThe rectangles are equal." << endl;
	}
	else
	{
		cout << "\nThe rectangles are not equal." << endl;
	}
	
		//Display the capabilities of the overloaded inequality operator
	rectangle.setDimension(12, 5);
	cout << "\nChecking for inequality: ";
	if (rectangle != rectangleTwo)
	{
		cout << "\nThe rectangles are inequal." << endl;
	}
	else
	{
		cout << "\nThe rectangles are equal." << endl;
	}

		//Display the capabilities of the overloaded greater than operator
	rectangle.setDimension(12, 5);
	cout << "\nChecking if rectangle one is greater than rectangle two: ";
	if (rectangle > rectangleTwo)
	{
		cout << "\nRectangle one is greater than rectangle two." << endl;
	}
	else
	{
		cout << "\nRectangle one is not greater than rectangle two." << endl;
	}

	//Display the capabilities of the overloaded less than operator
	rectangle.setDimension(12, 5);
	cout << "\nChecking if rectangle one is greater than rectangle two: ";
	if (rectangle < rectangleTwo)
	{
		cout << "\nRectangle one is less than rectangle two." << endl;
	}
	else
	{
		cout << "\nRectangle one is not less than rectangle two." << endl;
	}
}

