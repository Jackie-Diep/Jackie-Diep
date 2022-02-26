/*
File: Swimming Pool.cpp
Name: Jackie Diep
Date: 10/2/2019
Course: CSC 102
Description: A program using classes to define a swimming pool and using the class to complete different methods of filling and draining the swimming pool.
*/
#include <iostream>
#include <iomanip>
using namespace std;

class SwimmingPool
{
private:
	//Initialize user inputted basic dimensions
	int length;
	int width;
	int depth;
	int currentHeight;
	double fillRate;
	double drainRate;

	//initialize calculated dimensions
	int area;
	int emptyArea;
	int filledArea;
	double fillTime;
	double drainTime;
	double fillAmount;
	double drainAmount;

	//initialize dimensions made for percentage fill/drain depth
	double percDepth;
	double fPercentage;
	double dPercentage;
	int percEmptyArea;
	int percFilledArea;
	double percFillTime;
	double percDrainTime;
	double percFillAmount;
	double percDrainAmount;

	//initialize dimensions made for selected fill/drain depth
	int desiredEmptyArea;
	int desiredFilledArea;
	int fillFeet;
	int desiredFillDepth;
	int desiredDrainDepth;
	int adjArea;
	double desiredFillAmount;
	double desiredDrainAmount;
	double desiredFillTime;
	double desiredDrainTime;

public:
	/*
Troubleshooting display basic dimensions function
void listDimensions()
{
	cout << "length: " << length << endl;
	cout << "width: " << width << endl;
	cout << "depth: " << depth << endl;
	cout << "current height of water: " << currentHeight << endl;
	cout << "area: " << area << endl;
	cout << "filled area: " << filledArea << endl;
	cout << "empty area: " << emptyArea << endl;
}
*/
	/*
Alternate fill/drain method using a timer
int selectedTime;
double calcTimedFill(double timedFillAmount)
{
	timedFillAmount = selectedTime * fillRate;
	return timedFillAmount;
}
double calcTimedDrain(double timedDrainAmount)
{
	timedDrainAmount = selectedTime * drainRate;
	return timedDrainAmount;
}
*/

	//initialize method selector characters and selector functions
	char fmethod;
	char dmethod;
	void fillMethod()
	{
		cout << "\nHow much water would you like to add to the pool?" << endl;
		cout << "1. Fill the pool\n2. Enter a percentage to fill the pool to\n3. Enter the number of feet of water to remain in the pool" << endl;
		cin >> fmethod;
	}
	void drainMethod()
	{
		cout << "\nHow much water would you like to remove from the pool?" << endl;
		cout << "1. Empty the pool\n2. Enter a percentage to empty the pool to\n3. Enter the number of feet of water to remain in the pool" << endl;
		cin >> dmethod;
	}

	//functions for setting and obtaining basic dimensions
	void setLength()
	{
		cout << "The length of the pool (in feet) is: ";
		cin >> length;
	}
	void setWidth()
	{
		cout << "The width of the pool (in feet) is: ";
		cin >> width;
	}
	void setDepth()
	{
		cout << "The depth of the pool (in feet) is: ";
		cin >> depth;
	}
	void setCurrent()
	{
		cout << "The height of the water currently in the pool (in feet) is: ";
		cin >> currentHeight;
		while (currentHeight > depth)
		{
			cout << "The height of the water currently in the pool cannot be larger than the depth of the pool. Try again." << endl;
			cout << "The height of the water currently in the pool (in feet) is: ";
			cin >> currentHeight;
		}
	}	
	void setFillRate()
	{
		cout << "\nThe fill rate of the pool in gallons per minute is: ";
		cin >> fillRate;
	}
	void setDrainRate()
	{
		cout << "\nThe drain rate of the pool in gallons per minute is: ";
		cin >> drainRate;
	}
	int getLength()
	{
		return length;
	}
	int getWidth()
	{
		return width;
	}
	int getDepth()
	{
		return depth;
	}	
	double getFillRate()
	{
		return fillRate;
	}
	double getDrainRate()
	{
		return drainRate;
	}

	//functions for calculating dimensions
	int calcArea()
	{
		area = length * width * depth;
		return area;
	}
	int calcEmpty()
	{
		emptyArea = length * width * (depth - currentHeight);
		return emptyArea;
	}
	int calcFilled()
	{
		filledArea = length * width * currentHeight;
		return filledArea;
	}
	double calcFillTime()
	{
		double adjFillRate;
		adjFillRate = fillRate * .13;
		fillTime = emptyArea / adjFillRate;
		return fillTime;
	}
	double calcDrainTime()
	{
		double adjDrainRate;
		adjDrainRate = drainRate * .13;
		adjArea = area - emptyArea;
		drainTime = adjArea / adjDrainRate;
		return drainTime;
	}
	double calcFillAmount()
	{
		fillAmount = fillTime * fillRate;
		return fillAmount;
	}
	double calcDrainAmount()
	{
		drainAmount = drainTime * drainRate;
		return drainAmount;
	}

	//functions for percentage fill/drain depth
	int calcPercEmpty()
	{
		emptyArea = length * width * (percDepth - currentHeight);
		return emptyArea;
	}
	double calcPercFillTime()
	{
		double adjFillRate;
		adjFillRate = fillRate * .13;
		percFillTime = percEmptyArea / adjFillRate;
		return percFillTime;
	}
	double calcPercDrainTime()
	{
		double adjDrainRate;
		adjDrainRate = drainRate * .13;
		percDrainTime = percFilledArea / adjDrainRate;
		return percDrainTime;
	}
	double calcPercFillAmount()
	{
		percFillAmount = percFillTime * fillRate;
		return percFillAmount;
	}
	double calcPercDrainAmount()
	{
		percDrainAmount = percDrainTime * drainRate;
		return percDrainAmount;
	}
	double fillPercentage()
	{
		cout << "\nPercentage pool will be filled to: ";
		cin >> fPercentage;
		percDepth = depth * (fPercentage / 100);
		percEmptyArea = length * width * (percDepth - currentHeight);
		return percEmptyArea;
	}
	double drainPercentage()
	{
		cout << "\nPercentage pool will be drained to: ";
		cin >> dPercentage;
		percDepth = depth * (dPercentage / 100);
		percFilledArea = length * width * (currentHeight - percDepth);
		return percEmptyArea;
	}	
	double getFillPercentage()
	{
		return percDepth;
	}
	double getDrainPercentage()
	{
		return percDepth;
	}

	//functions for selected fill/drain depth
	int desiredFill()
	{
		cout << "\nDesired depth of the pool in feet: ";
		cin >> desiredFillDepth;
		desiredEmptyArea = length * width * (desiredFillDepth + currentHeight);
		return desiredFillDepth;
	}
	int desiredDrain()
	{
		cout << "\nDesired depth of the pool in feet: ";
		cin >> desiredDrainDepth;
		desiredFilledArea = length * width * (currentHeight - desiredDrainDepth);
		return desiredDrainDepth;
	}
	int getDesiredFillDepth()
	{
		return desiredFillDepth;
	}
	int getDesiredDrainDepth()
	{
		return desiredDrainDepth;
	}
	int desiredEmpty()
	{
		emptyArea = length * width * (desiredFillDepth - currentHeight);
		return emptyArea;
	}
	double desiredFillT()
	{
		double adjFillRate;
		adjFillRate = fillRate * .13;
		desiredFillTime = desiredEmptyArea / adjFillRate;
		return desiredFillTime;
	}
	double desiredDrainT()
	{
		double adjDrainRate;
		adjDrainRate = drainRate * .13;
		desiredDrainTime = desiredFilledArea / adjDrainRate;
		return desiredDrainTime;
	}
	double desiredFillA()
	{
		desiredFillAmount = desiredFillTime * fillRate;
		return desiredFillAmount;
	}
	double desiredDrainA()
	{
		desiredDrainAmount = desiredDrainTime * drainRate;
		return desiredDrainAmount;
	}
};

int main()
{
	//creating object "pool" of class "SwimmingPool"
	SwimmingPool pool;

	cout << "Pool Tool" << endl;
	cout << "\nPlease set the dimensions of the pool." << endl;
	//initializing, setting, and getting basic dimensions
	int length;
	int width;
	int depth;
	pool.setLength();
	pool.setWidth();
	pool.setDepth();
	pool.setCurrent();
	length = pool.getLength();
	width = pool.getWidth();
	depth = pool.getDepth();
	//pool.listDimensions();

	//initializing basic dimensions obtained later
	double drainRate;
	double fillRate;

	//calling functions to calculate common dimensions
	pool.calcArea();
	pool.calcEmpty();
	pool.calcFilled();

	//initializing calculated dimensions obtained later
	double fillAmount;
	double drainAmount;
	double fillTime;
	double drainTime;

	//initialize variables used in percentage fill/drain depth
	double percDepth;
	double percFillTime;
	double percDrainTime;
	double percDrainAmount;
	double percFillAmount;

	//initialize variables used in selected fill/drain depth
	int desiredFillDepth;
	int desiredDrainDepth;
	double desiredFillAmount;
	double desiredDrainAmount;
	double desiredFillTime;
	double desiredDrainTime;

	//initialize char "answer" then ask for input to begin program
	char answer;
	cout << "\nWould you like to adjust the amount of water in the pool?\nSelect 'y' or 'n': ";
	cin >> answer;

	//if answer == 'y' begin adjusting pool depth
	if (answer == 'y')
	{

		//initialize char "method" then ask for input to decide between 'fill' and 'drain'
		char method;
		cout << "\n1. Fill\n2. Drain\nSelect '1' or '2': ";
		cin >> method;
		if (method == '1')
		{

			//set and get fill rate
			pool.setFillRate();
			fillRate = pool.getFillRate();

			//decide which method will be used to fill the pool
			pool.fillMethod();

			if (pool.fmethod == '1')
			{

				//call on basic fill functions to calculate dimensions and output fill method 1
				fillTime = pool.calcFillTime();
				fillAmount = pool.calcFillAmount();
				cout << "\nFilling your " << length << " x " << width << " x " << depth << " pool to a depth of " << depth << " feet will require " << fillAmount << " gallons of water \nand will take about " << fixed << setprecision(0) << fillTime << " minutes at a rate of " << fillRate << " gallons per minute.\n";
			}

			else if (pool.fmethod == '2')
			{

				//call on fillPercentage function to set and then get fill percentage depth for fill method 2
				pool.fillPercentage();
				percDepth = pool.getFillPercentage();

				//call on percentage fill functions to calculate dimensions and output fill method 2
				percFillTime = pool.calcPercFillTime();
				percFillAmount = pool.calcPercFillAmount();
				cout << "\nFilling your " << length << " x " << width << " x " << depth << " pool to a depth of " << percDepth << " feet will require " << percFillAmount << " gallons of water \nand will take about " << fixed << setprecision(0) << percFillTime << " minutes at a rate of " << fillRate << " gallons per minute.\n";
			}

			else if (pool.fmethod == '3')
			{

				//call on desiredFill function to set and then get selected depth for fill method 3
				pool.desiredFill();
				desiredFillDepth = pool.getDesiredFillDepth();

				//call on selected fill functions to calculate dimensions and output fill method 3
				desiredFillTime = pool.desiredFillT();
				desiredFillAmount = pool.desiredFillA();
				cout << "\nFilling your " << length << " x " << width << " x " << depth << " pool to a depth of " << desiredFillDepth << " feet will require " << desiredFillAmount << " gallons of water \nand will take about " << fixed << setprecision(0) << desiredFillTime << " minutes at a rate of " << fillRate << " gallons per minute.\n";
			}
			else
			{

				//note that the selected fill option is invalid and end program
				cout << "That is not a valid option.";
			}
		}

		else if (method == '2')
		{

			//set and get drain rate
			pool.setDrainRate();
			drainRate = pool.getDrainRate();

			//decide which method will be used to drain the pool
			pool.drainMethod();

			if (pool.dmethod == '1')
			{

				//call on basic drain functions to calculate dimensions and output drain method 1
				drainTime = pool.calcDrainTime();
				drainAmount = pool.calcDrainAmount();
				cout << "\nEmptying your " << length << " x " << width << " x " << depth << " pool to a depth of 0 feet will remove " << drainAmount << " gallons of water \nand will take about " << fixed << setprecision(0) << drainTime << " minutes at a rate of " << drainRate << " gallons per minute.\n";
			}
			else if (pool.dmethod == '2')
			{

				//call on drainPercentage function to set and then get drain percentage for drain method 2
				pool.drainPercentage();
				percDepth = pool.getDrainPercentage();

				//call on percentage drain functions to calculate dimensions and output drain method 2
				percDrainTime = pool.calcPercDrainTime();
				percDrainAmount = pool.calcPercDrainAmount();
				cout << "\nEmptying your " << length << " x " << width << " x " << depth << " pool to a depth of " << percDepth << " feet will remove " << percDrainAmount << " gallons of water \nand will take about " << fixed << setprecision(0) << percDrainTime << " minutes at a rate of " << drainRate << " gallons per minute.\n";
			}

			else if (pool.dmethod == '3')
			{

				//call on desiredDrain function to set and then get selected depth for drain method 3
				pool.desiredDrain();
				desiredDrainDepth = pool.getDesiredDrainDepth();

				//call on selected drain functions to calculate dimensions and output drain method 3
				desiredDrainTime = pool.desiredDrainT();
				desiredDrainAmount = pool.desiredDrainA();
				cout << "\nEmptying your " << length << " x " << width << " x " << depth << " pool to a depth of " << desiredDrainDepth << " feet will remove " << desiredDrainAmount << " gallons of water \nand will take about " << fixed << setprecision(0) << desiredDrainTime << " minutes at a rate of " << drainRate << " gallons per minute.\n";
			}
			else
			{

				//note that the selected drain option is invalid and end program
				cout << "That is not a valid option.";
			}
		}
		else
		{

			//note that the selected method to adjust pool depth is invalid and end program
			cout << "\nThat is not a valid option." << endl;
		}
	}

	//if answer == 'n' end program
	else if (answer == 'n')
	{
		cout << "Ending program.";
	}

	//if answer is neither 'y' or 'n', note that the input is invalid and end program
	else
	{
		cout << "That is not a valid option. Ending program.";
	}
}