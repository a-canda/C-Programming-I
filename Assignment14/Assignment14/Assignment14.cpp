/*
Aaron Canda
CISS 241
Assignment 14

PSEUDOCODE
START
Declare global constants
	row/cols, total = 0, average, low, high, sales array
	function prototypes (6)
MAIN FUNCTION
	const vars NUM_DIVS, NUM_QTRS
	double rowtot/coltotal
	int row/col

	string div/qtr arrays (N, S, E, W, Qtr total) (Qtr 1->4, div total)
	output enter sales info
	for loop
		if div count == col-1
		for loop
		call calculate row total funct
		break
		Nested for loop
			if qtr count == row - 1
			call calculate col total funct
			break
			output div[index] & qtr[index]:
			input sales information
	format col
	format rows
	call and display functions total, average, rowtotal, columntotal
calculateTotal function
	for loop row
		for loop col
			total += num[row][col]
	return total
calculateAverage function
	avgtotal = 0, index= 0
	for loop row
		nested for loop col
			avgtotal += num[row][col]
			index++
	calculate average
	return average
calculateRowTotal function
	rowtotal = 0
	for loop col
		rowtotal += num[row][col]
	return rowtotal
calculateColTotal function
	coltotal = 0
	for loop row
		coltotal += num[row][col]
	return coltotal
findhighest function
	highest= 0
	for loop row
		nested for loop col
			if num [x][y] > highest
					row = x
					col = y
					highest = num[row][col]
	return highest
find lowest function
	lowest = num[0][0]
	for loop row
		nested for loop col
			if num [x][y] <= lowest
				row = x
				col = y
				lowest = num[row][col]
	return lowest
END
*/

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// global constants
const int ROWS = 5;
const int COLS = 5;

double total = 0;
double average;
double lowest;
double highest;

double sales[ROWS][COLS];
 
// function prototypes
double calculateTotal(double[][COLS]);
double calculateAverage(double[][COLS]);
double calculateRowTotal(double[][COLS], int);
double calculateColumnTotal(double[][COLS], int);
double findHighest(double[][COLS], int&, int&);
double findLowest(double[][COLS], int&, int&);

int main()
{
	const int NUM_DIVS = 5, NUM_QTRS = 5;
	double rowTotal, columnTotal;
	int row, col;
	 
	string div[NUM_DIVS] = { "North", "South", "East", "West", "Quarter Total" };
	string qtr[NUM_QTRS] = { "Quarter 1", "Quarter 2", "Quarter 3", "Quarter 4", "Division Total" };
	
	// have user enter in company sales
	cout << "Please enter all sales information:" << endl << endl;
	for (int divIndex = 0; divIndex < COLS; divIndex++)
	{
		if (divIndex == (COLS - 1))
		{
			for (int row = 0; row < COLS; row++)
			{			
				rowTotal = calculateRowTotal(sales, row);
				sales[row][divIndex] = rowTotal;
	 		}
	 		break;
	 	}
	 	for (int qtrIndex = 0; qtrIndex < ROWS; qtrIndex++)		// nested loop
		{		
	 		if (qtrIndex == (ROWS - 1))
			{
	 			for (int col = 0; col < COLS; col++)
				{					
	 				columnTotal = calculateColumnTotal(sales, col);	
	 				sales[qtrIndex][col] = columnTotal;
	 			}
	 			break;
	 		}
	 		cout << div[divIndex] << " -> " << qtr[qtrIndex] << ": ";	// nested loop statements
	 		cin >> sales[divIndex][qtrIndex];
	 	}															
	 	cout << endl;
 	}							// end for loop
	
	cout << setprecision(2) << fixed << showpoint;

	// format columns
	cout << "\t\t";
	for (int index = 0; index < NUM_DIVS; index++)
	{
		if (index < (NUM_DIVS - 1))
		{
			cout << setw(12) << qtr[index];
		}
		else 
			cout << setw(15) << qtr[index];
	} 
	cout << endl; 

	// format rows
	for (int row = 0; row < ROWS; row++)
	{
		cout << div[row];
		if (row < (ROWS - 1))
		{
			cout << "\t\t";
		}
		else 
			cout << "\t";
		for (int col = 0; col < COLS; col++)
		{
			if (col < (COLS - 1))
			{
				cout << setw(12) << sales[row][col];
			}
			else			
				cout << setw(15) << sales[row][col];			
		}
		cout << endl;
	}
	
	// call and display total function
	total = calculateTotal(sales);
	cout << endl << "Acme Electronic's total sales for this year: " << total << endl;
	
	// call and display average function
	average = calculateAverage(sales);
	cout << "Average sales: " << average << endl;
	
	// call and display highest division sale
	highest = findHighest(sales, row, col);
	cout << div[row] << " Division has the highest sales at " << highest
		<< " in " << qtr[col] << endl;
	// call and display lowest division sale
	lowest = findLowest(sales, row, col);
	cout << div[row] << " Division has the lowest sales at " << lowest 
		<< " in " << qtr[col] << endl << endl;

	return 0;
}

// calculate total function returns the total of the complete array except for totals in last col/row
double calculateTotal(double numbers[][COLS])
{
	for (int row = 0; row < (ROWS - 1); row++)
	{
		for (int col = 0; col < (COLS - 1); col++)
			total += numbers[row][col];
		
	}
	return total;
}

// calculate average function returns the average amount except col/row w/ totals
double calculateAverage(double numbers[][COLS])
{
	double index = 0;
	double averageTotal = 0;
	for (int row = 0; row < (ROWS - 1); row++)
	{
		for (int col = 0; col < (COLS - 1); col++)
		{
			averageTotal += numbers[row][col];
			index++;
		}
	}
	average = averageTotal / index;
	return average;
}

// calculate row total function  calculates the total for row that is specified by second parameter
double calculateRowTotal(double numbers[][COLS], int row)
{
	double rowTotal = 0;
	for (int col = 0; col < (COLS - 1); col++)
		rowTotal += numbers[row][col];
	
	return rowTotal;
}

// columntotal function calculates total for a column that is specified by the second parameter
double calculateColumnTotal(double numbers[][COLS], int col)
{
	double colTotal = 0;
	for (int row = 0; row < (ROWS - 1); row++)
		colTotal += numbers[row][col];

	return colTotal;
}

// findHighest function finds the highest sales in array
double findHighest(double numbers[][COLS], int &row, int &col)
{
	double highest = 0;
	for (int x = 0; x < (ROWS - 1); x++) 
	{
		for (int y = 0; y < (COLS - 1); y++) 
		{
			if ((numbers[x][y]) > highest)
			{
				row = x;
				col = y;
				highest = numbers[row][col];
			}
		}
	}
	return highest;
}

// findLowest function finds lowest sales in array
double findLowest(double numbers[][COLS], int &row, int &col)
{
	double lowest = numbers[0][0];
	for (int x = 0; x < (ROWS - 1); x++)
	{
		for (int y = 0; y < (COLS - 1); y++)
		{
			if ((numbers[x][y]) <= lowest)
			{
				row = x;
				col = y;
				lowest = numbers[row][col];
			}
		}
	}
	return lowest;
}