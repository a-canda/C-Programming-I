/*
Aaron Canda
Programming 1
CISS 241

The theme of this assignment is performing stock market calculations.
Cathy bought 600 shares of a stock at a price of $33.77 per share.
For the purchase of the stocks, she must pay the stockbroker a 2% commission
for the transaction. Design and create a program that calculates and displays
the following:

The amount paid for the stock alone (without the commission)
The amount of the commission
The total amount paid (for the stock plus the commission)

Pseudocode must be provided in the comment block at the top of the file

Pseudocode:

START
	Declare variables
		int shares = 600
		double sharePrice = 33.77
		double stockPaid
		double commission
		double totalStockPaid
	calculate amount paid for stock alone
		stockPaid = shares * sharePrice
	output "Amount paid for the stock alone (without the commission): "
	output stockPaid
	calculate amount of the comission
		commission = (stockPaid * 2) / 100
	output "Amount of the commission: "
	output commission
	calculate total amount paid
		totalStockPaid = stockPaid + commission
	output "Total amount paid: "
	output totalStockPaid	
END
*/

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	//declare variables
	int shares = 600;
	double sharePrice = 33.77;
	double stockPaid;
	double commission;
	double totalStockPaid;
	//calculate amount paid for stock alone
	stockPaid = shares * sharePrice;
	//output "Amount paid for the stock alone (without the commission): "
	//output stockPaid
	cout << "Amount paid for the stock alone: " << stockPaid << endl;
	//calculate amount of the commission
	commission = (stockPaid * 2) / 100;
	//output "Amount of the commission: "
	//output commission
	cout << "Amount of the commission: " << commission << endl;
	//calculate total amount paid
	totalStockPaid = stockPaid + commission;
	//output "Total amount paid: "
	//output totalStockPaid
	cout << "Total amount paid: " << totalStockPaid << endl;
	return 0;
}

