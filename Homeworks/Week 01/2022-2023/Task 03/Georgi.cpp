#include <iostream>
#include <limits.h>

int task3()
{
	int length;
	std::cin >> length;
	int* numbers = new int[length];

	for (size_t i = 0; i < length; i++)
		std::cin >> numbers[i];

	int maxNumber = INT_MIN;
	int lowestNaturalNumber = INT_MAX;
	int positive = 0;
	for (size_t i = 0; i < length; i++) {
		if (numbers[i] > maxNumber)
			maxNumber = numbers[i];

		if (numbers[i] > 0)
			positive++;

		if (numbers[i] < lowestNaturalNumber && numbers[i] > 0)
			lowestNaturalNumber = numbers[i];
	}

	if (positive == 0 || lowestNaturalNumber > 1) {
		std::cout << 1 << std::endl;
		return 0;
	}

	int newArrayLength = positive > maxNumber ? maxNumber + 1 : positive + 1;
	// 50000 numbers, max number 3000 => 3001
	// 100 numbers, max number 2423523523 => 101
	int* newArray = new int[newArrayLength](); // new array for counting

	for (size_t i = 0; i < length; i++)
		if (0 < numbers[i] && numbers[i] < newArrayLength)
			newArray[numbers[i]]++;

	delete[] numbers;

	for (size_t i = 1; i < newArrayLength; i++)
	{
		if (newArray[i] == 0) {
			std::cout << i << std::endl;
			delete[] newArray;
			return 0;
		}
	}

	delete[] newArray;
	std::cout << newArrayLength << std::endl;
	return 0;
}