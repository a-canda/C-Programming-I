// Assignment6.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
Aaron Canda
Programming 1
Assignment 6

A restaurant called Tony’s Pizza Palace needs a program to help calculate the number of slices a pizza
of any size can be divided into, and how many pizzas should be ordered for a party. The program will assume
each person at the party will eat 3 slices of pizza each.

The program should prompt the user for the diameter of the pizzas they wish to order. It will also ask the user
for the number of people who will be at the party. The program will then calculate and display the number of slices
per pizza and the number of pizzas needed for the party (must be full pizzas). Facts you need to know:

A slice must have an area of 14.125 inches
Number of slices per pizza is the area of the pizza divided by the area of a slice
Area of a pizza is calculated with Area = PI * r2
PI = 3.14159
r is the radius of the pizza
The number of slices should be a fixed point and rounded to one decimal place
PI must be a named constant
Pseudocode must be provided in the comment block at the top of the file.
*/

/*
Pseudocode:
START
	declare variables
		const double PI = 3.14159,
			SLICE_AREA = 14.125;

		double radius,
			totalArea,
			diameter,
			slices;

		int slicesPerPerson = 3,
			partySize,
			pizzaAmount;
	output "A slice must have an area of "..." square inches per slice"
	output "Enter the diameter of the pizza: "
	input diameter
	output "Enter the number of people in party: "
	input partySize
	calculations
		radius = diameter / 2;
		totalArea = PI * pow(radius, 2);
		slices = totalArea / SLICE_AREA;
		pizzaAmount = ((partySize * slicesPerPerson) / slices) + 1;
	output "Number of slices per pizza: " slices
	output "Number of full pizzas needed: " pizzaAmount
END
*/

#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//declare variables
	const double PI = 3.14159,
		SLICE_AREA = 14.125;

	double radius,
		totalArea,
		diameter,
		slices;

	int slicesPerPerson = 3,
		partySize,
		pizzaAmount;

	//output "A slice must have an area of "..." square inches per slice"
	cout << "A slice must have an area of " << SLICE_AREA;
	cout << " square inches per slice" << endl;
	//output "Enter the diameter of the pizza: "
	cout << "Enter the diameter of the pizza: " << endl;
	//input diameter
	cin >> diameter;
	//output "Enter the number of people in party: " 
	cout << "Enter the number of people in party: " << endl;
	//input partySize
	cin >> partySize;

	// calculations
	radius = diameter / 2;
	totalArea = PI * pow(radius, 2);
	slices = totalArea / SLICE_AREA;
	pizzaAmount = ((partySize * slicesPerPerson) / slices) + 1;

	//new line
	cout << endl;
	// output "Number of slices per pizza: " slices
	cout << "Number of slices per pizza: " << setw(10) << setprecision(1) << fixed << slices << endl;
	// output "Number of full pizzas needed: " pizzaAmount
	cout << "Number of full pizzas needed: " << setw(5) << pizzaAmount << endl;

	return 0;

}

