/*
	This program will use command line arguments to accept a filename and process the binary data.
	It will first read in meta data that will determine the presence of the three types of data temperature, salinity, and height along with the amount 
	of data present. Then, it will use dynamic arrays and the fstream library to create binary files of each type of data present with a formatted name.
	The formatted name will be "Type of Data".size

	February 17, 2020

	Jackie Diep
	University of Southern Mississippi
	307 Data Structures Homework Assignment 1
*/

//Header Files for output, file operation, and string usage
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Int function to read meta data that accepts an ifstream reader, an int array of 3 spaces, and an int of size which will be returned
int getMetaData(ifstream& readBinary, int metaData[3], int &size);

//Void function that will read data from the binary files into dynamic arrays that accepts and ifstream reader, an int array pointer, and an int of size
void readInData(ifstream&, int*, int size);

//Void function that will write data from the dynamic arrays into files created during the function with names formatted of "Type of Data".size
//that accepts an int array pointer, a string containing the name of the type of data, and an int of size
void writeData(int* dataType, string dataName, int size);

//Main begins accepting a command line prompt of the binary filename
int main(int argc, char* argv[])
{
	cout << "**********************************" << endl;

	//An if statement to determine whether or not the file was passed in
	if (argc != 2)
	{
		cout << "Invalid file name passed in." << endl;
		cout << "**********************************" << endl;
		return (1);
	}

	//Assigning the file name to a string variable and outputting it to console
	string name = argv[1];
	cout << "Name:\t\t" << name << endl;

	//Creating a binary stream reader
	ifstream readBinary;

	//Opening the file to be read
	readBinary.open(name, ios::in | ios::binary);
	
	//An if statement to determine whether or not the file was opened
	if (!readBinary)
	{
		cout << "\nCould not open text file for reading.\n" << endl;
		cout << "**********************************" << endl;
		return (2);
	}

	//An array of 3 values to hold the meta data of the binary file with all values initialized to 0
	int metaData[3] = { 0,0,0 };

	//A variable to hold the size of the types of data within the array initialized to 0
	int size = 0;
	
	//Call the getMetaData function to process the meta data into the created int array and int variable
	getMetaData(readBinary, metaData, size);

	//For loop and switch statement to output the presence of each type of data
	for (int i = 0; i < 3; i++)
	{
		string dataType;
		switch(i)
		{
		case 0: dataType = "Temperature:\t";
			break;
		case 1: dataType = "Salinity:\t";
			break;
		case 2: dataType = "Height:\t\t";
			break;
		default: cout << "Invalid Type";
		}
		cout << dataType << metaData[i] << endl;
	}

	//cout statement to output the size of each type of data
	cout << "Size:\t\t" << size << endl << endl;

	//if statements that process the presence of each type of data available
	//For each type of data available, create a name for the file to be created and a dynamic int array to hold the data read in from the file
	//Then call the readInData function to read the data from the file into the created dynamic int array
	//Then call the writeData function to create the file using the string named after the type of data to create a file of format "Type of Data".size
	//	and write data from the dynamic arrays into the created file and then delete the dynamic array

		//if statement to process Temperature
	if (metaData[0] == 1)
	{
		//String to hold the file name
		string Temperature = "Temperature";

		//Creation of a dynamic array for the type of data
		int* temperature = new int[size];
		cout << "**********************************" << endl;
		cout << "Temperature: ";

		//readInData call to read the data from the file into the dynamic array
		readInData(readBinary, temperature, size);

		//writeData call to read data from the dynamic array into the file with name formatted as "Type of Data".size
		writeData(temperature, Temperature, size);

		//Delete the dynamic array
		delete[]temperature;
	}

		//if statement to process Salinity
	if (metaData[1] == 1)
	{
		string Salinity = "Salinity";
		int* salinity = new int[size];
		cout << "**********************************" << endl;
		cout << "Salinity: ";
		readInData(readBinary, salinity, size);
		writeData(salinity, Salinity, size);
		delete[]salinity;
	}

		//if statement to process Height
	if (metaData[2] == 1)
	{
		string Height = "Height";
		int* height = new int[size];
		cout << "**********************************" << endl;
		cout << "Height: ";
		readInData(readBinary, height, size);
		writeData(height, Height, size);
		delete[]height;
	}

	//Close the binary stream reader
	readBinary.close();
}
 
//getMetaData function definition
int getMetaData(ifstream& readBinary, int metaData[3], int &size)
{
	//A for loop that reads the meta data containing the types of data into the metaData[3] array
	for (int i = 0; i < 3; i++)
	{
		readBinary.read((char*)&metaData[i], sizeof(int));
	}

	//A read statement that reads the size of the types of data into the int size variable
	readBinary.read((char*)&size, sizeof(int));

	//Return int size to main
	return size;
}


//readInData function definition
void readInData(ifstream& readBinary, int*dataType, int size)
{
	//Output to console the amount of data to be read in
	cout << size << " pieces of data will be read in." << endl;

	//A for loop that reads the data from the file into the respective dynamic arrays
	for (int i = 0; i < size; i++)
	{
		readBinary.read((char*)&dataType[i], sizeof(int));

		//cout and if statements to format and output the data read into the dynamic arrays to console
		cout << dataType[i] << "\t";
		if ((i+1) % 5 == 0)
		{
			cout << endl;
		}
	}
	cout << endl << endl;
}

void writeData(int*dataType, string dataName, int size)
{
	//Create a stream writer
	ofstream writeBinary;

	//Create and format the file name to "Type of Data".size
	string fileName = dataName + "." + to_string(size);

	//Open the file to be written into
	writeBinary.open(fileName, ios::out | ios::binary);

	//if statement to determine whether or not the file was opened
	if (!writeBinary)
	{
		cout << "\nCould not open text file for writing.\n" << endl;
		cout << "**********************************" << endl;
	}

	//If the file was opened, 
	else
	{
		//Output to console that writing into the file has begun
		cout << "----------Writing into the file begins" << endl << endl;

		//A for loop limited by the amount of data present for the type of data and write into the file
		for (int i = 0; i < size; i++)
		{
			writeBinary.write(reinterpret_cast<const char*>(&dataType[i]), sizeof(int));
		}
	}

	//Close the stream writer
	writeBinary.close();
}
