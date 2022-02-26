#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

using namespace std;

int main()
{
	srand((unsigned)time(NULL));

	int data1 = 0;
	int data2 = 0;
	int data3 = 0;

	int quantity = 0;

	for* (int i = 0; i < 10; i++)
	{
	
	data1 = (rand() % 2);
	data2 = (rand() % 2);
	data3 = (rand() % 2);

	if (data1 == 0 && data2 == 0 && data3 == 0)
	{
		data3 = 1;
	}

	quantity = ((rand() * rand()) % 100) + 1);

	cout << endl;
	cout << "Temperature -> " << data1 << endl;
	cout << "Salinity	 -> " << data2 << endl;
	cout << "Height		 -> " << data3 << endl;
	cout << "Quantity	 -> " << quantity << endl << endl;
	
	string fileName = to_string(data1) + to_string(data2) + to_string(data3) + "." + to_string(quantity);

	cout << endl << fileName << endl << endl;

	ofstream writeBinary;
	writeBinary.open(fileName, ios::out | ios::binary);

	if (!writeBinary)
	{
		cout << endl << "Could not create/open inary file for writing." << endl;
		return(2);
	}

	writeBinary.write(reinterpret_cast<const char*>(&data1), sizeof(int));
	writeBinary.write(reinterpret_cast<const char*>(&data2), sizeof(int));
	writeBinary.write(reinterpret_cast<const char*>(&data3), sizeof(int));
	writeBinary.write(reinterpret_cast<const char*>(&quantity), sizeof(int));

	int totalData = ((data1 + data2 + data3) * quantity);

	for (int i = 0; i < totalData; i++)
	{
		int number = 0;
		number = (rand() * rand()) % 100;
		writeBinary.write(reinterpret_cast<const char*>(&number), sizeof(int));
	}
	
	writeBinary.close();
	}
return(0);
}
