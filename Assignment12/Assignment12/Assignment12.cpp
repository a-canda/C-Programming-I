/*
Aaron Canda
Programming 1
Assignment 12


PSEUDOCODE
START
Function prototypes
	getUserChoice
	getComputerChoice
	determineWinner
	displaychoice
	showmenu
	declare const variables (menu)
Main function
	declare local variables
	output title
	user choice = call getUserChoice function
	computer choice = call getComputerChoice function
	call determineWinner function
getUserChoice function
	declare local variable
	output choose number 1-5
	call showmenu function
	input choice
	validation while loop 
		output choose 1 - 5
		input choice
	return choice
getComputerChoice function
	unsigned seed = time(0)
	srand(seed)
	int choice = (rand() % 5) + 1
	return choice
determineWinner function (bool)
	bool winner = true
	output Your choice
	call displayChoice function (user guess)
	output computers choice
	call displayChoice function (computer guess)
	validate to determine tie (while loop)
		winner = false if userChoice = compChoice
	if else statements listing winning/losing scenarios
	return winner;
displaychoice function
	if else if statements
		if choice = ROCK
			output rock
		etc. etc.
showmenu function
	output menu choices	
END
*/

#include "pch.h"
#include <iostream>
#include <ctime>
using namespace std;

// function prototypes
int getUserChoice();
int getComputerChoice();
bool determineWinner(int, int);
void displayChoice(int);
void showMenu();

// global constant variables
const int ROCK = 1,
			PAPER = 2,
			SCISSORS = 3,
			LIZARD = 4,
			SPOCK = 5;

int main()
{
	int	userChoice,
		compChoice;

	cout << "------------------------------------\n";
	cout << "ROCK, PAPER, SCISSORS, LIZARD, SPOCK\n";
	cout << "------------------------------------\n";

	userChoice = getUserChoice();
	compChoice = getComputerChoice();
	determineWinner(userChoice, compChoice);		// call determineWinner function	
													// user's choice and comp choice in parameters
	return 0;										
}

// getUserChoice function
int getUserChoice()
{
	int choice;
	
	cout << "Select a choice (1-5)" << endl;
	showMenu();
	cin >> choice;

	// Choice selection validation
	while ((choice < 1) || (choice > 5))
	{
		cout << "Invalid choice. Please choose 1 - 5" << endl << endl
			<< "Guess again: ";
		cin >> choice;
		cout << endl;
	}
	return choice;
}

// getComputerChoice function -> select choice by random
int getComputerChoice()
{
	unsigned seed = time(0);
	srand(seed);
	int choice = (rand() % (5)) + 1;
	return choice;
}

// determineWinner function
bool determineWinner(int userChoice, int compChoice)
{
	bool winner;

	cout << endl << "Your choice: ";
	displayChoice(userChoice);
	cout << "Computer choice: ";
	displayChoice(compChoice);
	cout << endl;

	while (userChoice == compChoice)
	{
		winner = false;
		
		cout << "Its a tie. Guess again!" << endl << endl;

		userChoice = getUserChoice();
		compChoice = getComputerChoice();
	} // <-- end of while loop
	
	if (userChoice != compChoice)
	{
		winner = true;

		// winning and losing scenarios
		if (userChoice == ROCK)
		{
			if (compChoice == SCISSORS)
				cout << "Rock breaks scissors. YOU WIN!" << endl;
			else if (compChoice == PAPER)
				cout << "Paper covers rock. YOU LOSE!" << endl;
			else if (compChoice == LIZARD)
				cout << "Rock crushes lizard. YOU WIN!" << endl;
			else if (compChoice == SPOCK)
				cout << "Spock vaporizes rock. YOU LOSE!" << endl;
		}
		else if (userChoice == PAPER)
		{
			if (compChoice == SCISSORS)
				cout << "Scissors cut paper. YOU LOSE!" << endl;
			else if (compChoice == ROCK)
				cout << "Paper covers rock. YOU WIN!" << endl;
			else if (compChoice == LIZARD)
				cout << "Lizard eats paper. YOU LOSE!" << endl;
			else if (compChoice == SPOCK)
				cout << "Paper disproves Spock. YOU WIN!" << endl;
		}
		else if (userChoice == SCISSORS)
		{
			if (compChoice == ROCK)
				cout << "Rock breaks scissors. YOU LOSE!" << endl;
			else if (compChoice == PAPER)
				cout << "Scissors cut paper. YOU WIN!" << endl;
			else if (compChoice == LIZARD)
				cout << "Scissors decapitate lizard. YOU WIN!" << endl;
			else if (compChoice == SPOCK)
				cout << "Spock smashes (or melts) lizard. YOU LOSE!" << endl;
		}
		else if (userChoice == LIZARD)
		{
			if (compChoice == SCISSORS)
				cout << "Scissors decapitates lizard. YOU LOSE!" << endl;
			else if (compChoice == PAPER)
				cout << "Lizard eats Paper. YOU WIN!" << endl;
			else if (compChoice == ROCK)
				cout << "Rock crushes lizard. YOU LOSE!" << endl;
			else if (compChoice == SPOCK)
				cout << "Lizard poisons Spock. YOU WIN!" << endl;
		}
		else if (userChoice == SPOCK)
		{
			if (compChoice == SCISSORS)
				cout << "Spock smashes (or melts) scissors. YOU WIN!" << endl;
			else if (compChoice == PAPER)
				cout << "Paper disproves Spock. YOU LOSE!" << endl;
			else if (compChoice == LIZARD)
				cout << "Lizard poisons Spock. YOU LOSE!" << endl;
			else if (compChoice == ROCK)
				cout << "Spock vaporizes rock. YOU WIN!" << endl;
		}
	} 

	return winner;

}
// displayChoice function - turn choice number to return one word
void displayChoice(int choice)
{
	if (choice == ROCK)
		cout << "Rock" << endl;
	else if (choice == PAPER)
		cout << "Paper" << endl;
	else if (choice == SCISSORS)
		cout << "Scissors" << endl;
	else if (choice == LIZARD)
		cout << "Lizard" << endl;
	else if (choice == SPOCK)
		cout << "Spock" << endl;
}
// showMenu function displays menu
void showMenu()
{
	cout << "1. Rock" << endl
		<< "2. Paper" << endl
		<< "3. Scissors" << endl
		<< "4. Lizard" << endl
		<< "5. Spock" << endl << endl
		<< "Enter your choice: ";
}