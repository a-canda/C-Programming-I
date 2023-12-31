/*
Aaron Canda
Programming 1
Assignment 11

PSEUDOCODE:
START
list function prototypes
	getScore
	calcAverage
	findLowest
main function
	declare variables
	for statement (get 6 test scores)
		if else if statements
			call getScore functions for each test score
	call calcAverage function
getScore function
	declare validScore variable
	output "what is the score"
	input validScore
	validate score with while loop
		validScore between 0 and 100
			output "score must be between 0 and 100"
			output "please reenter"
	score = validScore
calcAverage function
	variable dropLowestScore = call findLowest function
	calculate sum = sum of all test scores - dropLowestScore
	calculate average = sum / 5.0
	display average with precision of 2 decimal places
	output "the average score is" average
findLowest function
	declare variable lowestScore
	if score 1 =< score 2
		score 1 = lowestScore
	else
		score2 = lowestScore
	if score3 < lowestScore
		lowestScore = score3
	if score 4 < lowestScore
		lowestScore = score4
	if score5 < lowestScore
		lowestScore = 5
	if score6 < lowestScore
		lowestScore = 6
	return lowestScore
END
*/

#include "pch.h"
#include <iostream>
#include <iomanip>
using namespace std;

// function prototypes
void getScore(double &);
void calcAverage(double, double, double, double, double, double);
double findLowest(double, double, double, double, double, double);

int main()			// main funtion
{
	double score1,
		score2,
		score3,
		score4,
		score5,
		score6;

	// Get the 6 test scores
	for (int i = 0; i < 6; i++)
	{
		if (i == 0)
		{
			getScore(score1);	// call getScore function
		}
		else if (i == 1)
		{
			getScore(score2);
		}
		else if (i == 2)
		{
			getScore(score3);
		}
		else if (i == 3)
		{
			getScore(score4);
		}
		else if (i == 4)
		{
			getScore(score5);
		}
		else if (i == 5)
		{
			getScore(score6);
		}
	} // <-- End for loop

	calcAverage(score1, score2, score3, score4, score5, score6);	// call calcAverage function

	return 0;
}

void getScore(double &score)		//getScore function
{
	int validScore;
	cout << "Enter the score of the test: ";
	cin >> validScore;

	// validate the score
	while ((validScore < 0) || (validScore > 100))
	{
		cout << "Test scores must be between 0 and 100." << endl
			<< "Please reenter score: ";
		cin >> validScore;
	} // <-- end while loop
	score = validScore;
}

// calcAverage function
// Must drop the lowest test score by calling the findLowest function
void calcAverage(double score1,	double score2, double score3, double score4, double score5, double score6)
{
	double dropLowestScore = findLowest(score1, score2, score3, score4, score5, score6);	// call findLowest function
	double sum = score1 + score2 + score3 + score4 + score5 + score6 - dropLowestScore;
	double average = sum / 5.0;

	cout << setprecision(2) << fixed << showpoint;
	cout << "The average score of your tests is: " << average << endl;
}	

// findLowest function
double findLowest(double score1, double score2, double score3, double score4, double score5, double score6)
{
	// find the lowest score of the 6 tests
	double lowestScore;
	if (score1 <= score2)
		lowestScore = score1;
	else
		lowestScore = score2;
	if (score3 < lowestScore)
		lowestScore = score3;
	if (score4 < lowestScore)
		lowestScore = score4;
	if (score5 < lowestScore)
		lowestScore = score5;
	if (score6 < lowestScore)
		lowestScore = score6;

	return lowestScore;
}
	   