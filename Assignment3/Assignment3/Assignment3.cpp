/* Aaron Canda
Programming 1
CISS 241
Write a program that calculates and displays the miles per gallon for one tankful of
gas when driven in town and when driven on the  highway.

Pseudocode

START
	Declare variables
		double gallons
		double milesInTown
		double milesOnHighway
		double milesPerGallon
	calculate town milesPerGallon = milesInTown/gallons
	output "MPG in town: " milesPerGallon
	calculate highway milesPerGallon = milesOnHighway/gallons
	output "MPG on Highway:" milesPerGallon
END
*/

#include "pch.h"
#include <iostream>
using namespace std;

int main() 
{
	double gallons = 16.0;
	double milesInTown = 345.0;
	double milesOnHighway = 460.0;
	double milesPerGallon;

	//calculate milesPerGallon = milesInTown / gallons
	milesPerGallon = milesInTown / gallons;
	//output "MPG in town: "
	cout << "MPG in town: " << milesPerGallon << endl;
	//calculate milesPerGallon = milesOnHighway / gallons
	milesPerGallon = milesOnHighway / gallons;
	//output "MPG on Highway: "
	cout << "MPG on Highway: " << milesPerGallon << endl;
	return 0;
}