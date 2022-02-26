#pragma once
#include <iostream>
using namespace std;
class rectangleType
{
public:
	void setDimension(double l, double w);
	double getLength() const;
	double getWidth() const;
	double getArea();
	double getPerimeter();
	void displayDimensions();

		//Overload the arithmetic operators
	rectangleType operator+(const rectangleType&) const;
	rectangleType operator-(const rectangleType&) const;
	rectangleType operator*(const rectangleType&) const;
	rectangleType operator/(const rectangleType&) const;

		//Overload the increment and decrement operators
	rectangleType operator++();
	rectangleType operator++(int);
	rectangleType operator--();
	rectangleType operator--(int);

		//Overload the relational operators
	bool operator==(rectangleType&) const;
	bool operator!=(rectangleType&) const;
	bool operator<=(rectangleType&) const;
	bool operator<(rectangleType&) const;
	bool operator>=(rectangleType&) const;
	bool operator>(rectangleType&) const;

		//Constructors
	rectangleType();
	rectangleType(double l, double w);

protected:
	double length;
	double width;
	double area;
	double perimeter;
};

