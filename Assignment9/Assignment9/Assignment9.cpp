/*
Aaron Canda
Programming Assignment 9
CISS 241


PSEUDOCODE:
START
	declare variables
		number, guess, playAgain button
		system time/seed RNG
	Do/while loop
		generate RN (1-100)
		output guess the number (1-100)
		For loop
			input guess
			validate guess #
				guess < 1 or guess > 100
				output Error message
				deincrement # of guesses
			if else if statements
				if guess is correct in < 5 guesses
					output "Either you know the secret or you got lucky!"
				else if guess is correct in 5-7 guesses
					output "You're pretty good at this!"
				else if correct in 8-10 guesses
					output "You'll do better next time!"
				else if guess 10 is not correct
					output "Sorry - You have taken too many guesses."
		output play again?
		input playAgain
	while loop playAgain == y or Y
	output terminate program		
END
*/

#include "pch.h"
#include <iostream>
#include <cstdlib>		//for rand and srand
#include <ctime>		//for time function
using namespace std;

int main() 
{
	int number,
		guess;
	char playAgain;

	unsigned seed = time(0);		// Get the system time.
	srand(seed);					// Seed the random number generator.

	do {
		// Generate random number between 1 - 100.
		number = (rand() % (100) + 1);		// y = (rand() % (maxValue - minValue + 1) + minValue;

		cout << "Guess the number between 1 and 100: ";
		for (int i = 0; i < 10; i++)
		{
			cin >> guess;
			// Validate user input
			if ((guess < 1) || (guess > 100))
			{
				cout << endl << "ERROR: Enter a value in the range 1-100:";
				i--;
			}
			// if user has less than 5 guesses
			if ((guess == number) && (i < 4))
			{
				cout << endl << "Either you know the secret or you got lucky!" << endl;
				break;
			}
			// if user has 5-7 guesses
			else if ((guess == number) && (i > 3) && (i < 7))
			{
				cout << endl << "You're pretty good at this!" << endl;
				break;
			}
			// if user has 8-10 guesses
			else if ((guess == number) && (i > 6) && (i < 10))
			{
				cout << endl << "You'll do better next time." << endl;
				break;
			}
			// if user's 10th guess is incorrect
			else if ((guess != number) && (i == 9))
			{
				cout << endl << "Sorry - You have taken too many guesses." << endl;
				break;
			}
			// Too low, try again
			else if ((guess < number) && (guess >= 1) && (guess <= 100))
			{
				cout << endl << "Too low, try again: ";
			}
			// Too high, try again
			else if ((guess > number) && (guess >= 1) && (guess <= 100))
			{
				cout << endl << "Too high, try again: ";
			}
		}
		// Play again?
		cout << endl << "Play again? Hit Y or N: ";
		cin >> playAgain;
		cout << endl;
	} while ((playAgain == 'Y') || (playAgain == 'y'));
	cout << "Terminating Program." << endl;
	
	return 0;
}