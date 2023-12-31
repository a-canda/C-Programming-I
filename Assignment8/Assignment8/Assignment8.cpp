/*
Aaron Canda
Programming Assignment 8
CISS 241

Pseudocode
START
declare variables
	string name
	int kWh
	double untaxed,state/city, un/discou
output get customer name
input name
output get kwh
input kwh
output customer name
output kwh
if kwh < 1000
	output base value $0.052 per
	calculate untaxed	
else if kwh >= 1000 and kwh < 1300
	output base value $0.052 per first 1000 used
	output base value $0.041 per over 1000 kwh used
	calculate untaxed
else if kwh >= 1300 and kwh < 2000
	output base value $0.052 per first 1000 used
	output base value $0.041 per next 300 kwh used
	output base value $0.035 per over 1300 used
	calculate untaxed
else
	output base value $0.052 per first 1000 used
	output base value $0.041 per next 300 used
	output base value $0.035 per next 700 used
	output base value $0.03 per kwh used over 2000 kwh used
	calculate untaxed
calculate state tax
calculate city tax
calculate undiscounted
calculate discount
calculate total amount due
output undiscounted bill amount
output untaxed bill amount
output discount amount
output state utility tax amount
output city utility tax amount
output total amount due
END
*/

#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	string name;

	int kWh;

	double untaxed,
		stateUtility,
		cityUtility,
		undiscounted,
		discount,
		amountDue;

	// get customer name
	cout << "Input Name of the Customer: ";
	cin >> name;
	cout << "Input Number of kWh used: ";
	cin >> kWh;

	// display customer name and kWh used
	cout << endl;
	cout << "Customer name: " << name << endl;
	cout << "kWh used: " << kWh << " kWh" << endl;

	// calculate untaxed amount
	if (kWh < 1000)
	{
		cout << "Base value: $0.052 per kWh";
		untaxed = kWh * 0.052;
	}
	else if (kWh >= 1000 && kWh < 1300)
	{
		cout << "Base value of at least 1000 kWh, but less than 1300 kWh:\n"
			<< "\t\t$0.052 per kWh for first 1000 kWh used\n"
			<< "\t\t$0.041 per kWh over 1000 kWh used";
		untaxed = (1000 * 0.052) - ((kWh - 1000) * 0.041);
	}
	else if (kWh >= 1300 && kWh < 2000)
	{
		cout << "Base value of at least 1300 kWh, but less than 2000 kWh:\n"
			<< "\t\t$0.052 per kWh for first 1000 kWh used\n"
			<< "\t\t$0.041 per kWh for the next 300 kWh used\n"
			<< "\t\t$0.035 per kWh over 1300 kWh used";
		untaxed = (1000 * 0.052) + (300 * 0.041) + ((kWh - 1300) * 0.035);
	}
	else
	{
		cout << "Base value of at least 2000 kWh:\n"
			<< "\t\t$0.052 per kWh for first 1000 kWh used\n"
			<< "\t\t$0.041 per kWh for the next 300 kWh used\n"
			<< "\t\t$0.035 per kWh for the next 700 kWh used\n"
			<< "\t\t$0.03 per kWh over 2000 kWh used";
		untaxed = (1000 * 0.052) + (300 * 0.041) + (700 * 0.035) + ((kWh - 2000) * 0.03);
	}

	stateUtility = (0.035 * untaxed);		//state tax = 3.5%
	cityUtility = (0.015 * untaxed);		// city tax = 1.5%

	// add state & city tax to undiscounted amount
	undiscounted = untaxed + stateUtility + cityUtility;
	// calculate discount amount (undiscounted * 12% discount)
	discount = undiscounted * 0.12;
	// calculate total amount due
	amountDue = undiscounted - discount;

	//display output
	cout << endl;
	cout << "Undiscounted bill amount: $" << fixed << setprecision(2) << undiscounted << endl;
	cout << "Untaxed bill amount: $" << fixed << setprecision(2) << untaxed << endl;
	cout << "Discount amount: $" << fixed << setprecision(2) << discount << endl;
	cout << "State utility tax amount: $" << fixed << setprecision(2) << stateUtility << endl;
	cout << "City utility tax amount: $" << fixed << setprecision(2) << cityUtility << endl;
	cout << "Total amount due: $" << fixed << setprecision(2) << amountDue << endl;

	return 0;
}

