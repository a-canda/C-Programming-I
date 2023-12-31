/*
Aaron Canda
Final Project
CISS 241
*/
/*
This program contains an airline seating chart that allows users to 
keep track of which seats are taken and are available. The program will have
a menu that allows the user to select of 1 of 7 options. The user can allow 
the user to reserve a seat, display the total number of seats sold, the total
number of seats empty in a row, the total number of seats empty in the plane 
and the total amount of sales. The plane will be divided into two sections;
first class and coach. The back half of the coach is priced differently than
the first. When displaying the seating chart, the # indicates an open seat
where as a * will display a seat taken. The program will validate any seat options
selected by the user to not be taken already.
*/
/*
PSEUDOCODE:
START
Function Prototypes
	void getPriceDoc()
	void allSeatsAvailable()
	void displaySeating()
	void showMenu()
	void getMenuSelect()
	void reserveTicket()
	void requestSeat()
	void validSeatCheck()
	void seatsSold()
	void seatsEmptyRow()
	void seatsEmptyPlane()
	void displayTotalSales()
Declare Arrays
	seatPrices[3]
	firstClass[5][4]
	coach1[5][6]
	coach2[5][6]
Initializing 0
	int	firstClassSold, coach1Sold, coach2Sold = 0
	int firstClassCurrent, coach1Current, coach2Current = 0
	double totalSales = 0;

int main function
	call functions
		getPriceDoc
		allAvailableSeating
		showMenu
	return 0

getPriceDoc function
	int index = 0
	ifstream inputFile
	inputFile.open(document location)
	while (index < 3 and inputFile >> seatPrices[index]
		increment index
	inputFile.close()

allSeatsAvailable() function
	for loop (first class)
		firstClass[row][col] = '#';
	for loop (coach1)
		coach1[row][col] = '#';
	for loop (coach2)
		coach2[row][col] = '#';

displaySeating() function
	output "seating chart"
	output "/t12 34"
	for loop (row)
		output "Row " (row + 1) \t
		for loop (col)
			firstClass[row][col]
			if (col == 2)
				output " "
	output "\t123456"
	for loop (row) - Coach 1
		output "row" (row+6)\t
		for loop(col)
			output coach1[row][col];
	for loop (row) - Coach 2
		output "row" (row+11)\t
		for loop (col)
			output couch2[row][col];

showMenu() function
	output "Menu selection:"
	output 1. Reserve seat(s)
	output 2. Display seating chart
	output 3. Amount of seats sold
	output 4. Total number of seats empty in a row
	output 5. Total number of empty seats in the plane
	output 6. Total amount of sales
	output 7. Exit
	output "Select an option (Enter 1-7): "
	call getMenuSelct()

getmenuselect() function
	const int
		RESERVE_TICKET = 1
		SHOW_SEATING = 2
		SEATS_SOLD = 3
		EMPTY_ROW = 4
		EMPTY_PLANE = 5
		TOTAL_SALE = 6
		EXIT = 7
	int choice
	input choice
	while(choice < RESERVE_TICKET || choice > EXIT)
		output enter a valid menu choice (1-7): 
		input choice
	switch(choice)
	case RESERVE_TICKET
		call reserveTicket() function
		break
	case SHOW_SEATING
		call displaySeating() function
		break
	case SEATS_SOLD
		call seatsSold()
		break
	case EMPTY_ROW
		call seatsEmptyRow()
		break
	case EMPTY_PLANE
		call seatsEmptyPlane()
		break
	case TOTAL_SALE
		call displayTotalSales()
		break
	case EXIT
		call exit(0)
	call showMenu();

reserveTicket() function
	double totalCurrent = 0
	int tickets
	output how many plane tickets would you like to reserve?
	input tickets
	for loop (amount tix)
		call requestSeat() function
	totalCurrent = ((firstClassCurrent*seatPrices[0]) + (coach1Current * seatPrices[1]) + (coach2Current * seatPrices[2]))
	totalSales += totalCurrent
	output "The total amount is $" totalCurrent
	totalCurrent = 0
	firstClassSold += firstClassCurrent
	coach1Sold += coach1Current
	coach2Sold += coach2Current
	firstClassCurrent = coach1Current = coach2Current = 0

requestSeat() function
	int row, col
	output Which row would you like? (Enter 1-15)
	input row
	while row <1 || row > 15
		output invalid row - enter 1-15
		input row
	output which column would you like? (Enter 1-6)
	input col
	if row >= 1 and row <= 5
		while col < 1 || col > 4
			output First class has only 4 columns
			input col
		else if row >=6 and row <= 15
			while col < 1 or > 6
				output coach seating has only 6 columns
				input col
		call validSeatCheck() function pass row and col as arguments

validSeatCheck() function
	if row >=1 and row <= 5
		if firstclass[row-1][col-1]=='*'
			output seat taken. select another.
			call requestSeat function
		if(firstClass[row-1][col-1]!='*'
			firstclass[row-1][col-1] = '*'
			firstClassCurrent++
	if row >= 6 and row <=10
		if (coach1[row - 6][col-1] == '*'
			output seat taken. select another
			call requestSeat function
		if (coach1[row -6][col-1] != '*'
			coach1[row-6][col-1] = '*'
			coach1Current++
	if row >= 11 and row <= 15
		if coach2[row-11][col-1] == '*'
			output seat taken. select another
			call requestSeat function
		if coach2[row-11][col-1] != '*'
			coach2[row-11][col-1] = '*'
			coach2Current++

seatsSold() function
	int totalSeatsSold = firstClassSold + coach1Sold + coach2Sold
	output totalSeatsSold total seats are sold on the plane
	output firstClassSold are sold in first class seating
	output (coach1Sold + coach2Sold) sold in both coach sections
	output coach1 are sold in coach 1
	output coach2 are sold in coach 2

seatsEmptyRow() function
	int checkRow
	int count = 0;
	output which row would you like to check?
	input checkRow
	while(checkRow != 0)
		while checkRow < 0 || checkRow > 15
			output There are only 15 rows. Enter 1-15
			input checkRow
		if(checkRow >= 1 && checkRow <= 5)
			for loop (col)
				if firstclass[checkRow -1][col] == '#'
					count++
		else if (checkRow >=6 and checkRow <=10
			for loop (col)
				if(coach1[checkRow - 6][col] == '#'
					count++
		else if (checkRow >= 11 and checkRow <= 15
			for loop (col)
				if coach2[checkRow -11][col] == '#'
					count++
		output there are (count) seats empty in row (checkRow)
		count = 0
		output enter in another row, or enter 0 to return to menu selection
		input checkRow
		if (checkRow == 0)
			endl
seatsEmptyPlane() function
	int totalEmpty, firstClassEmpty = 0, coach1Empty = 0, coach2Empty = 0
	for loop (first class row)
		for loop (col)
			if (firstClass[row][col] == '#')
				firstClassEmpty++
	for loop (coach1 row)
		for loop (col)
			if (coach1[row][col] == '#')
				coach1Empty++
	for loop (coach2 row)
		for loop (col)
			if (coach2[row][col] == '#')
				coach2Empty++
	totalEmpty = firstClassEmpty + coach1Empty + coach2Empty
	output There are (totalEmpty) seats on the plane
	output (firstClassEmpty) seats are empty in first class
	output (couch1Empty+coach2Empty) seats are empty in both coach sections
	output (coach1Empty) seats are empty in coach 1 seating
	output (coach2Empty) seats are empty in coach 2 seating

displayTotalSales() function
	double firstClassSales = firstClassSold * seatPrices[0]
	double coachSales = (coach1Sold * seatPrices[1]) + (coach2Sold * seatPrices[2])
	call seatsSold() function
	fixed << setprecision(2) << showpoint
	output First Class sales: $ (firstclassSales)
	output coach class sales: $ (coachSales)
	output total sale: $ (totalSales)
END
*/


#include "pch.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// function prototypes
void getPriceDoc();
void allSeatsAvailable();
void displaySeating();
void showMenu();
void getMenuSelect();
void reserveTicket();
void requestSeat();
void validSeatCheck(int, int);
void seatsSold();
void seatsEmptyRow();
void seatsEmptyPlane();
void displayTotalSales();

//arrays
double seatPrices[3];
char firstClass[5][4];
char coach1[5][6];
char coach2[5][6];

// initializers
int firstClassSold, coach1Sold, coach2Sold = 0;
int firstClassCurrent, coach1Current, coach2Current = 0;
double totalSales = 0;

int main()
{
	getPriceDoc();
	allSeatsAvailable();
	showMenu();

	return 0;
}

/*
The getPriceDoc function retrieves information from the SeatPrice.txt file in my computer
From the seatPrice.txt file, I am able to retrieve the seat prices for first class and both
coach class seats.
*/
void getPriceDoc()
{
	int index = 0;
	ifstream inputFile;
	inputFile.open("C:\\Users\\ANC\\Desktop\\C++\\FinalProject\\SeatPrices.txt");
	while (index < 3 && inputFile >> seatPrices[index])
	{
		index++;
	}
	inputFile.close();
}

/*
the allSeatsAvailable function uses a bunch of nested for loops to fill in
each array (first class, coach1 and coach2 arrays) with # chars. Because
they are two-dimentional arrays, each for loop needs to be nested atleast once
(one for row and  another for column).
*/
void allSeatsAvailable()
{
	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			firstClass[row][col] = '#';
		}
	}

	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 6; col++)
		{
			coach1[row][col] = '#';
		}
	}
	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 6; col++)
		{
			coach2[row][col] = '#';
		}
	}
}

/*
The displaySeating function, when called, will show the seating chart
with available and unavailable seats. Since first class and coach classes
were different array sizes, I adjusted the rows and columns accordingly.
To format the first class to have an aisle, I added a space using an if statement
when the for loop was equal to 1.
*/
void displaySeating()
{
	cout << "Available/Unavailable Seating Chart" << endl << endl;
	cout << "\t12 34" << endl;
	for (int row = 0; row < 5; row++)
	{
		cout << "Row " << (row + 1) << "\t";
		for (int col = 0; col < 4; col++)
		{
			cout << firstClass[row][col];
			if (col == 1)
				cout << " ";
		}
		cout << endl;
	}
	
	cout << "\t123456" << endl;
	for (int row = 0; row < 5; row++)
	{
		cout << "Row " << (row + 6) << "\t";
		for (int col = 0; col < 6; col++)
			cout << coach1[row][col];
		cout << endl;
	}
	
	
	for (int row = 0; row < 5; row++)
	{
		cout << "Row " << (row + 11) << "\t";
		for (int col = 0; col < 6; col++)
			cout << coach2[row][col];
		cout << endl;
	}
}

/*
This function displays the menu selection and asks the user
to enter in 1-7. Then calls the getMenuSelect() function
which will ask the user to give an input.
*/
void showMenu()
{
	cout << "Menu Selection:" << endl << endl;
	cout << "1. Reserve seat(s)" << endl;
	cout << "2. Display seating chart" << endl;
	cout << "3. Amount of seats sold" << endl;
	cout << "4. Total number of seats empty in a row" << endl;
	cout << "5. Total number of empty seats in the plane" << endl;
	cout << "6. Total amount of sales" << endl;
	cout << "7. Exit" << endl;

	cout << "Select an option (Enter 1-7): ";
	getMenuSelect();
	cout << endl;
}

/*
The getMenuSelect() function uses a switch. The user will make a choice
from 1-7. Selecting from 1-7 will bring the user accordingly unless
entered out of bounds. That will then have the user re-enter a valid number
choice.
*/
void getMenuSelect()
{
	const int
		RESERVE_TICKET = 1,
		SHOW_SEATING = 2,
		SEATS_SOLD = 3,
		EMPTY_ROW = 4,
		EMPTY_PLANE = 5,
		TOTAL_SALE = 6,
		EXIT = 7;
	int choice;
	
	cin >> choice;
	cout << endl;
	
	while (choice < RESERVE_TICKET || choice > EXIT)
	{
		cout << "Enter a valid menu choice (1-7): ";
		cin >> choice;
	}
	cout << endl;

	switch (choice)
	{
	case RESERVE_TICKET:
		reserveTicket();
		break;
	case SHOW_SEATING:
		displaySeating();
		break;
	case SEATS_SOLD:
		seatsSold();
		break;
	case EMPTY_ROW:
		seatsEmptyRow();
		break;
	case EMPTY_PLANE:
		seatsEmptyPlane();
		break;
	case TOTAL_SALE:
		displayTotalSales();
		break;
	case EXIT:
		exit(0);
	}
	cout << endl << endl;
	showMenu();
}

/*
the reserveTicket function will ask the user how many seats or tickets the user
will want to reserve. The function then calls the requestSeat function, which will ask
the user which row and column the user wants to reserve and will repeat until the user
has reserved the amount of seats asked. The function then displays the total sale
depending on how many the user bought and which class the user reserved. The total
is calculated by using an accumulator. totalCurrent is set to 0 and each class is counted
through the for loop, then added to total sales.
*/
void reserveTicket()
{
	double totalCurrent = 0;
	int tickets;
	cout << "How many plane tickets would you like to reserve? ";
	cin >> tickets;
	cout << endl;
	for (int index = 0; index < tickets; index++)
		requestSeat();
	
	totalCurrent = ((firstClassCurrent * seatPrices[0]) 
						+ (coach1Current * seatPrices[1]) 
						+ (coach2Current * seatPrices[2]));
	totalSales += totalCurrent;
	
	cout << endl;
	
	cout << fixed << setprecision(2) << showpoint;
	cout << "The total amount is $" << totalCurrent << endl;

	totalCurrent = 0;
	firstClassSold += firstClassCurrent;
	coach1Sold += coach1Current;
	coach2Sold += coach2Current;
	firstClassCurrent = coach1Current = coach2Current = 0;
}

/*
the requestSeat function will ask the user which seat the user wants. 
It will start by asking which row and which column the user likes.
depending how many tickets the user requested, the function will loop
until the last seat is requested. The function will also validate the
rows and columns chosen to their respective classes.
*/
void requestSeat()
{
	int row, col;
	cout << "Which row would you like to choose?" << endl
		<< "First Class (Enter 1-5), Coach Class (Enter 6-15): ";
	cin >> row;
	cout << endl;
	while (row < 1 || row > 15)
	{
		cout << endl;
		cout << "Invalid row - Enter 1-15: ";
		cin >> row;
	}

	cout << "Which column would you like to choose?" << endl
		<< "First Class (Enter 1-4), Coach Class (Enter 1-6): ";
	cin >> col;
	cout << endl;
	if (row >= 1 && row <= 5)
	{
		while (col < 1 || col > 4)
		{
			cout << endl;
			cout << "First Class section only has 4 columns." << endl
				<< "Please enter a valid column number: ";
			cin >> col;
			cout << endl;
		}
	}
	else if (row >= 6 && row <= 15)
	{
		while (col < 1 || col > 6)
		{
			cout << endl;
			cout << "Coach seating has only 6 columns." << endl
				<< "Please enter a valid column number: ";
			cin >> col;
			cout << endl;
		}
	}

	validSeatCheck(row, col);
}

/*
the validSeatCheck function finds the seats listed as '*' and will tell the user
if the seat is taken. when the user has chosen a seat that is NOT a *, the function will
change the char to a * in place of a #. This indicates a taken seat. This needs to be done
for each class array respective to their rows and columns. For every seat reserved, the function
will count each seat from each class as it loops. This accumulator will be used to get the total
seat prices back in the reserveTicket function.
*/
void validSeatCheck(int row, int col)
{
	if (row >= 1 && row <= 5)
	{
		if (firstClass[row - 1][col - 1] == '*')
		{
			cout << endl;
			cout << "That seat is taken. Please select another seat." << endl;
			requestSeat();
		}
		if (firstClass[row - 1][col - 1] != '*')
		{
			firstClass[row - 1][col - 1] = '*';
			firstClassCurrent++;
		}
	}
	if (row >= 6 && row <= 10)
	{
		if (coach1[row - 6][col - 1] == '*')
		{
			cout << endl;
			cout << "That seat is taken. Please select another seat." << endl;
			requestSeat();
		}
		if (coach1[row - 6][col - 1] != '*')
		{
			coach1[row - 6][col - 1] = '*';
			coach1Current++;
		}
	}
	if (row >= 11 && row <= 15)
	{
		if (coach2[row - 11][col - 1] == '*')
		{
			cout << endl;
			cout << "That seat is taken. Please select another seat." << endl;
			requestSeat();
		}
		if (coach2[row - 11][col - 1] != '*')
		{
			coach2[row - 11][col - 1] = '*';
			coach2Current++;
		}
	}
}

/*
The seatsSold function will display the total seats sold to the user when selected from the menu.
It will also display the number of seats sold in both first class and coach1 and coach2 classes.
*/
void seatsSold()
{
	int totalSeatsSold = firstClassSold + coach1Sold + coach2Sold;
	cout << totalSeatsSold << " total seats are sold on the plane." << endl
		<< firstClassSold << " are sold in first class seating." << endl
		<< (coach1Sold + coach2Sold) << " are sold in both coach sections." << endl
		<< coach1Sold << " are sold in the first coach section." << endl
		<< coach2Sold << " are sold in the second coach section." << endl;
	cout << endl;
}

/*
the seatsEmptyRow function will check a row that the user can enter.
As long as the user does not enter 0, the function will repeatedly ask
the user to enter a row to check. The function will display how many empty
seats there are in the row that the user entered. Entering 0 will bring the
user back to the main selection. The function uses nested for loops and if else if
statements to check the rows in each class. an accumulator is used to tally up each
# in each for loop, then displayed to the user how many empty seats are in the specific row.
*/
void seatsEmptyRow()
{
	int checkRow;
	int count = 0;
	
	cout << "Which row would you like to check? (Enter 1-15): ";
	cin >> checkRow;
	cout << endl;
	while (checkRow != 0)
	{
		while (checkRow < 0 || checkRow > 15)
		{
			cout << "There are only 15 rows. Enter 1-15: ";
			cin >> checkRow;
		}
		if (checkRow >= 1 && checkRow <= 5)
		{
			for (int col = 0; col < 4; col++)
			{
				if (firstClass[checkRow - 1][col] == '#')
					count++;
			}
		}
		else if (checkRow >= 6 && checkRow <= 10)
		{
			for (int col = 0; col < 6; col++)
			{
				if (coach1[checkRow - 6][col] == '#')
					count++;
			}
		}
		else if (checkRow >= 11 && checkRow <= 15)
		{
			for (int col = 0; col < 6; col++)
			{
				if (coach2[checkRow - 11][col] == '#')
					count++;
			}
		}
		cout << "There are " << count << " seats empty in row " << checkRow << endl;
		cout << endl;

		count = 0;
		cout << "Enter in another row, or enter 0 to return to menu selection: ";
		cin >> checkRow;
		cout << endl;
	}
	if (checkRow == 0)
		cout << endl;
}

/*
This function calculates the total seats for each class, using nested for loops
and accumulators. Similar to the previous function, this function finds every
# char in each boarding class. Each # is counted and then added to the total.
The amount of empty seats are also displayed for first class and both coach classes.
*/
void seatsEmptyPlane()
{
	int totalEmpty, firstClassEmpty = 0, coach1Empty = 0, coach2Empty = 0;
	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 4; col++)
		{
			if (firstClass[row][col] == '#')
				firstClassEmpty++;
		}
	}
	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 6; col++)
		{
			if (coach1[row][col] == '#')
				coach1Empty++;
		}
	}
	for (int row = 0; row < 5; row++)
	{
		for (int col = 0; col < 6; col++)
		{
			if (coach2[row][col] == '#')
				coach2Empty++;
		}
	}
	totalEmpty = firstClassEmpty + coach1Empty + coach2Empty;
	cout << "There are " << totalEmpty << " empty seats on the plane." << endl
		<< firstClassEmpty << " seats are empty in First Class." << endl
		<< (coach1Empty + coach2Empty) << " seats are empty in both coach sections." << endl
		<< coach1Empty << " seats are empty in the first coach section." << endl
		<< coach2Empty << " seats are empty in the second coach section." << endl;
	cout << endl;
}

/*
the displayTotalSales function calculates the first class sales and the coach sales.
the function then displays the first class sales, coach class sales, and total sales in
dollar form.
*/
void displayTotalSales()
{
	double firstClassSales = firstClassSold * seatPrices[0];
	double coachSales = (coach1Sold * seatPrices[1]) + (coach2Sold * seatPrices[2]);
	seatsSold();

	cout << fixed << setprecision(2) << showpoint;
	cout << "First Class sales: $" << firstClassSales << endl;
	cout << "Coach Class sales: $" << coachSales << endl << endl;
	cout << "Total sales: $" << totalSales << endl;
	cout << endl;
}