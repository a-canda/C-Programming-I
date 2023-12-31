/*
Aaron Canda
Programming Assignment 10
CISS 241

PSEUDOCODE:
START
	Declare variables
		int readNumber, lowest, highest, count =0, total=0
		double average
	read file - ifstream (location of file)
	if randomNumberFile
		output file opened
		read first number from file
		while loop to read each number
			if statement to assign high/low num
			if else if to find high/low
			accumulator total+= readNumber
			increment count
		calculate average
		close file
	Display outputs
		numbers read from file: count
		lowest value: lowestNum
		highest value: highestNum
		average: average
		sum of all numbers: total
	else
		output error opening file
		output terminating program
END
*/

#include "pch.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	int readNumber,
		lowestNum,
		highestNum,
		count = 0,
		total = 0;
	double average;

	// Read file
	ifstream randomNumberFile("C:\\Users\\ANC\\Desktop\\C++\\Random.txt");

	if (randomNumberFile)					// if/else statement to validate file opening
	{
		// validate that the file was opened before reading from the file.
		cout << "File successfully opened!" << endl;

		randomNumberFile >> readNumber;		// Reads number 1 from the file

		// loop & accumulator for each line
		while (randomNumberFile >> readNumber)
		{
			// find & assign highest/lowest num
			if (count == 0)
			{
				highestNum = readNumber;
				lowestNum = readNumber;
			}
			if (readNumber < lowestNum)
			{
				lowestNum = readNumber;
			}
			else if (readNumber > highestNum)
			{
				highestNum = readNumber;
			}
			total += readNumber;			// Accumulator
			count++;						// Increment count
		}

		// Average  must be casted because readNumber is an integer
		average = static_cast<double>(total) / count;

		randomNumberFile.close();			// Close the file

		if (!randomNumberFile)
		{
			cout << "File closed successfully." << endl << endl;
		}
		
		// read numbers from file, display outputs
		cout << "Numbers read from the file: "		<< right << setw(10) << count << endl
			<< "Lowest value in file: "				<< right << setw(14) << lowestNum << endl
			<< "Highest value in file: "			<< right << setw(16) << highestNum << endl
			<< "Average of all numbers in file: "	<< right << setw(10) << average << endl
			<< "Sum of all numbers in file: "		<< right << setw(13) << total << endl;
	}	// end of beginning if statement
	else
	{
		cout << "ERROR OPENING FILE." << endl
			<< "Terminating program." << endl;
	}

	return 0;
}
