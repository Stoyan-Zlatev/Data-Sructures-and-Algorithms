#include <iostream>

void task3()
{
	std::string input;
	std::cin >> input;

	int* counter = new int[75]();

	for (size_t i = 0; i < input.size(); i++)
		counter[(int)input[i] - '0']++;

	size_t resultIndex = 0;
	int* result = new int[75]();
	for (size_t i = 0; i < input.size(); i++)
		if (counter[input[i] - '0'] == 1)
			result[resultIndex++] = i;

	for (size_t i = 0; i < resultIndex; i++)
		std::cout << result[i] << " ";
}