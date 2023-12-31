/*
Aaron Canda
Assignment 13
CISS 241

PSEUDOCODE
START
Function prototypes
	collectraindata()
	calculatetotalrainfall()
	calculate average()
	findlowest()
	findhighest()
	month array size
	string month array = {jan -> dec}
main funct
	declare variables
	call collectraindata funct
	declare variables
		int lowestmonth
			highestmonth
		double low
			   high
	output "total rainfall" -> call calculatetotalrainfall
	output "average rainfall" -> call calculateaverage
	low = call findlowest
	high = call findhighest
	output month array [lowest] -> "has lowest rainfall" -> low
	output month array [highest] -> "has highest rainfall" -> high
collectraindata funct
	output "enter rainfall for month:"
	for statement (int index = 0, index < 12, index++)
		output month array[index]
		input rainfall[index]
calculatetotalrainfall funct
	double total = 0
	for (int index = 0; index < size; index++)
		total += rainfall[index]
	return total
calculate average function
	double average = calculatetotalrainfall(rainfall, months) / months
	return average
calculatelowest function
	double lowest = rainfall[0]
	for (int index = 1; index < size; index++)
		if (rainfall[index] < lowest)
		lowest = rainfall[index]
	return lowest
calculatehighest function
	double highest = rainfall[0]
	for (int index = 1; index > size; index++)
		if (rainfall[index] > highest)
		highest = rainfall[index]
	return highest
END
*/
