#include "rectangleType.h"

	//Default constructor
rectangleType::rectangleType()
{
	length = 0;
	width = 0;
	area = 0;
	perimeter = 0;
}

	//Constructor that takes parameters
rectangleType::rectangleType(double l, double w)
{
	length = l;
	width = w;
	area = 0;
	perimeter = 0;
}

	//Function to set the length and width of the rectangleType objects
void rectangleType::setDimension(double l, double w)
{
	length = l;
	width = w;
}

	//Function to display length
double rectangleType::getLength() const
{
	return length;
}

	//Function to display width
double rectangleType::getWidth() const
{
	return width;
}

	//Function to calculate area
double rectangleType::getArea()
{
	area = length * width;
	return area;
}

	//Function to calculate the perimeter
double rectangleType::getPerimeter()
{
	perimeter = length * 2 + width * 2;
	return perimeter;
}

	//Function to call the getLength() and getWidth() functions to display dimensions
void rectangleType::displayDimensions()
{
	rectangleType temp;
	temp.length = length;
	temp.width = width;
	cout << "Length: ";
	cout << temp.getLength() << endl;
	cout << "Width: ";
	cout << temp.getWidth() << endl;
}

	//Function to overload the addition operator
rectangleType rectangleType::operator+(const rectangleType& passedRectangle) const
{
	rectangleType temp;
	temp.length = length + passedRectangle.length;
	temp.width = width + passedRectangle.width;
	return temp;
}

	//Function to overload the subtraction operator along with a notice of invalid subtraction
rectangleType rectangleType::operator-(const rectangleType& passedRectangle) const
{
	rectangleType temp;
	if ((length - passedRectangle.length) <= 0 || (width - passedRectangle.width) <= 0)
	{
		cout << "Invalid operation, dimensions 0 or negative." << endl;
		temp.length = length;
		temp.width = width;
	}
	else 
	{
		temp.length = length - passedRectangle.length;
		temp.width = width - passedRectangle.width;
	}
	return temp;
	
}

	//Function to overload the multiplication operator
rectangleType rectangleType::operator*(const rectangleType& passedRectangle) const
{
	rectangleType temp;
	temp.length = length * passedRectangle.length;
	temp.width = width * passedRectangle.width;
	return temp;
}

	//Function to overload the division operator
rectangleType rectangleType::operator/(const rectangleType& passedRectangle) const
{
	rectangleType temp;
	temp.length = length / passedRectangle.length;
	temp.width = width / passedRectangle.width;
	return temp;
}

	//Function to overload the increment operator
rectangleType rectangleType::operator++()
{
	rectangleType temp;
	temp.length = length++;
	temp.width = width++;
	return (temp);
}

	//Function to overload the increment operator and take parameters
rectangleType rectangleType::operator++(int plus)
{
	rectangleType temp;
	temp.length = length + plus;
	temp.width = width + plus;
	return (temp);
}

	//Function to overload the decrement operator along with a notice of invalid subtraction
rectangleType rectangleType::operator--()
{
	rectangleType temp;
	if (length-- <= 0 || width-- <= 0)
	{
		cout << "Invalid operation, dimensions 0 or negative." << endl;
		temp.length = length;
		temp.width = width;
	}
	else
	{
		temp.length = length - 1;
		temp.width = length - 1;
	}
	return (temp);

}

	//Function to overload the decrement operator and take parameters along with a notice of invalid subtraction
rectangleType rectangleType::operator--(int minus)
{
	rectangleType temp;
	if (length - minus <= 0 || width - minus <= 0)
	{
		cout << "Invalid operation, dimensions 0 or negative." << endl;
		temp.length = length;
		temp.width = width;
	}
	else
	{
		temp.length = length - minus;
		temp.width = width - minus;
	}
	return (temp);
}

	//Function to overload the equality operator
bool rectangleType::operator==(rectangleType& passedRectangle) const
{
	rectangleType temp;
	temp.length = length;
	temp.width = width;
	if (temp.getArea() == passedRectangle.getArea())
	{
		return true;
	}
	else
	{
		return false;
	}
}

	//Function to overload the inequality operator
bool rectangleType::operator!=(rectangleType& passedRectangle) const
{
	rectangleType temp;
	temp.length = length;
	temp.width = width;
	if (temp.getArea() == passedRectangle.getArea())
	{
		return false;
	}
	else
	{
		return true;
	}
}

	//Function to overload the less than or equal to operator
bool rectangleType::operator<=(rectangleType& passedRectangle) const
{
	rectangleType temp;
	temp.length = length;
	temp.width = width;
	if (temp.getArea() <= passedRectangle.getArea())
	{
		return true;
	}
	else
	{
		return false;
	}
}

	//Function to overload the less than operator
bool rectangleType::operator<(rectangleType& passedRectangle) const
{
	rectangleType temp;
	temp.length = length;
	temp.width = width;
	if (temp.getArea() < passedRectangle.getArea())
	{
		return true;
	}
	else
	{
		return false;
	}
}

	//Function to overload the greater than or equal to operator
bool rectangleType::operator>=(rectangleType& passedRectangle) const
{
	rectangleType temp;
	temp.length = length;
	temp.width = width;
	if (temp.getArea() >= passedRectangle.getArea())
	{
		return true;
	}
	else
	{
		return false;
	}
}

	//Function to overload the greater than operator
bool rectangleType::operator>(rectangleType& passedRectangle) const
{
	rectangleType temp;
	temp.length = length;
	temp.width = width;
	if (temp.getArea() > passedRectangle.getArea())
	{
		return true;
	}
	else
	{
		return false;
	}
}