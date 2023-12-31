/* 
Aaron Canda
Programming Assignment 7
CISS 241

Pseudocode:
START
	declare int variables
		menu choices
		values to calculate area

	declare double variables
		shape areas

	declare constant variables
		PI
		Menu choices

	output display menu

	input menu option (1-6)

	if case 1 circle
		output get radius
		input radius
		if radius > 0 
			calculate area of circle
			output area of circle
		else
			output invalid radius input

	if case 2 rectangle
		output get length
		input length
		if length > 0
			output get width
			input width
		else
			output invalid length input
		if width > 0
			calculate rectangle area
			output rectangle area
		else 
			output invalid width input

	if case 3 triangle
		output get height
		input height
		if height > 0
			output get base
			input base
		else
			output invalid height input
		if base > 0
			calculate triangle area
			output triangle area
		else
			output invalid base input
	if case 4 trapezoid
		output get height
		input height
		if height > 0 
			output get base1
			input base1
		else
			output invalid height input
		if base1 > 0
			output get base2
			input base2
		else
			output invalid base1 input
		if base2 > 0
			calculate trapezoid area
			output trapezoid area
		else
			output invalid base2 input
	if case 5 sphere
		output get radius
		input radius
		if radius > 0
			calculate sphere
			output sphere area
		else
			output invalid radius input
	if case 6 exit
		output program ending
	else (default)
		output invalid menu choices
END
*/

#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int choice,				// To hold a menu choice
		radius,				
		length,				
		width,				
		base,				
		height,				
		baseOne,
		baseTwo;

	double circleArea,		// To hold the areas of each shape
		rectangleArea,
		triangleArea,
		trapezoidArea,
		sphereArea;

	// Constant named PI
	const double PI = 3.14;

	// Constants for menu choices
	const int CIRCLE_CHOICE = 1,
		RECTANGLE_CHOICE = 2,
		TRIANGLE_CHOICE = 3,
		TRAPEZOID_CHOICE = 4,
		SPHERE_CHOICE = 5,
		EXIT_CHOICE = 6;

	// Display the menu and get a choice.
	cout << "\t\tCalculator Options:\n\n"
		<< "1. Calculate the area of a circle\n"
		<< "2. Calculate the area of a rectangle\n"
		<< "3. Calculate the area of a triangle\n"
		<< "4. Calculate the area of a trapezoid\n"
		<< "5. Calculate the area of a sphere\n"
		<< "6. Exit\n\n"
		<< "Enter your choice (1-6): ";
	cin >> choice;

	// Respond to the user's menu selection.
	switch (choice)
	{
	case CIRCLE_CHOICE:
		cout << "Enter the radius of the circle: ";
		cin >> radius;

		// Validate the input of radius
		if (radius > 0)
		{
			circleArea = PI * pow(radius, 2.0);			// Circle area calculation
			cout << "The area of the circle is: " << circleArea;
		}
		else
			cout << "Value entered for the radius is invalid.\n";	
		break;

	case RECTANGLE_CHOICE:
		cout << "Enter length of the rectangle: ";
		cin >> length;

		// Validate the input of length
		if (length > 0)
		{
			cout << "Enter width of the rectangle: ";
			cin >> width;

			// Validate the input of width
			if (width > 0)
			{
				rectangleArea = length * width;
				cout << "The area of the rectangle is: " << rectangleArea;
			}
			else
				cout << "Value entered for the width is invalid.\n";
		}
		else
			cout << "Value entered for the length is invalid.\n";
		break;

	case TRIANGLE_CHOICE:
		cout << "Enter length of the triangle's base: ";
		cin >> base;

		// Validate the input of triangle base
		if (base > 0)
		{
			cout << "Enter length of the triangle's height: ";
			cin >> height;

			// Validate the input of triangle height
			if (height > 0)
			{
				triangleArea = base * height * 0.5;
				cout << "The area of the triangle is: " << triangleArea;
			}
			else
				cout << "Value entered for the height is invalid.";
		}
		else
			cout << "Value entered for the base is invalid.";	
		break;

	case TRAPEZOID_CHOICE:
		cout << "Enter height of the trapezoid: ";
		cin >> height;

		// Validate the input of trapezoid height
		if (height > 0)
		{
			cout << "Enter the first base length: ";
			cin >> baseOne;

			//Validate the input of trapezoid base one
			if (baseOne > 0)
			{
				cout << "Enter the second base length: ";
				cin >> baseTwo;

				//Validate the input of trapezoid base two
				if (baseTwo > 0)
				{
					trapezoidArea = height / 2 * (baseOne + baseTwo);
					cout << "The area of the trapezoid is: " << trapezoidArea;
				}
				else
					cout << "Value entered for the second base length is invalid.";
			}
			else
				cout << "Value entered for the first base length is invalid.";
		}
		else
			cout << "Value entered for the height is invalid.";
		break;

	case SPHERE_CHOICE:
		cout << "Enter the radius of the sphere: ";
		cin >> radius;

		// Validate the radius
		if (radius > 0)
		{
			sphereArea = 4 * PI * pow(radius, 2.0);
			cout << "The area of the sphere is: " << sphereArea;
		}
		else
			cout << "Value entered for the radius is invalid.";
		break;

	case EXIT_CHOICE:
		cout << "Program ending.\n";
		break;

	default:
		cout << "The valid choices are 1 through 6. Run the\n"
			<< "program again and select one of those.\n";
			   		 
	}

		return 0;
			
}
