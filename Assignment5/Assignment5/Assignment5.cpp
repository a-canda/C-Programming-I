// Assignment5.cpp : This file contains the 'main' function. Program execution begins and ends there.

/* Aaron Canda
Programming 1
CISS 241

Compounded Interest Earned – Assume no additional deposits are made other than the original investment. The balance in an account after one year may be calculated as:

New Balance = Principal * (1 + rate/T)T

Principal is the opening balance in the account. Rate is the interest rate, and T is the number of times the interest is compounded during a year (T is 4 if the interest is compounded quarterly). Write a program that prompts the user for the principal, the interest rate, and the number of times the interest is compounded. The output must be formatted in the following format:

Interest Rate:	4.25%
Times Compounded:	12
Principal:	$1000.00
Interest: 	$43.34
Amount in Savings:	$1043.34

Pseudocode:
START
	declare variables
	output "Enter principal value"
	input principal
	output "Enter interest rate"
	input interestRate
	output "Enter the time value"
	input times compounded
	calculate new balance
	output Interest rate
	output Times compounded
	output Principal
	output Interest
	output Amount in Savings
END

*/
#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	// declare variables
	double principal, interestRate, amount;
	int time;
	// output "Enter principal value"
	cout << "Enter principal value" << endl;
	// input principal
	cin >> principal;
	// output "Enter interest rate"
	cout << "Enter interest rate" << endl;
	// input interestRate
	cin >> interestRate;
	// output "Enter the time value"
	cout << "Enter the time value" << endl;
	// input times compounded
	cin >> time;
	// calculate new balance
	amount = principal * pow((1 + interestRate/time), time);
	// output Interest rate
	cout << "Interest rate: " << fixed << setprecision(2) << interestRate * 100 << " %" << endl;
	// output Times compounded
	cout << "Times compounded: " << time << endl;
	// output Principal
	cout << "Principal: $" << fixed << setprecision(2) << principal << endl;
	// output Interest
	cout << "Interest: $" << fixed << setprecision(2) << amount - principal << endl;
	// output Amount in Savings
	cout << "Amount in Savings: $" << fixed << setprecision(2) << amount << endl;
	return 0;
}

