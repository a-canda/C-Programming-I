/* Aaron Canda
Programming 1
Assignment 2

Write pseudocode and create a flowchart for two problems

Design a program will calculate the total of a retail sale at a store. The program should ask
the user for the retail price of the item being purchased and the sales tax rate as a decimal value.
The program should then calculate the sales taxes and the final cost of the item.  The output of the
program will display the sales tax for the purchase and the total of the sale.

Design a program that will calculate the current balance in a savings account. The program must ask the
user for the current balance, a total dollar amount of deposits made, the total dollar amount of
withdrawals made, and the monthly interest rate as a decimal. The program will then calculate the new balance
for the savings account and display the new balance.
*/

/*
Problem 1:
START
	input double retailPrice
	input double salesTax
	input double salesTaxRate
	set salesTax = (retailPrice x salesTaxRate)/100
	set total = salesTax + retailPrice
	output salesTax
	output total
STOP
*/

/*
Problem 2:
START
	input double startBalance
	input double depositAmount
	input double withdrawalAmount
	input double monthlyInterest
	set total = currentBalance + depositAmount - withdrawalAmount
	set currentBalance = total + (total x monthlyInterest)/100
	output currentBalance
STOP
*/