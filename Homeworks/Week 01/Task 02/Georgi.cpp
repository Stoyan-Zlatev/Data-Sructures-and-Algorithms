#include <iostream>

int task2(){
	unsigned int daysCount;
	std::cin >> daysCount;
	unsigned int* prices = new unsigned int[daysCount];

	for (size_t i = 0; i < daysCount; i++)
		std::cin >> prices[i];

	daysCount--;
	size_t profit = 0;
	for (size_t i = 0; i < daysCount; i++)
	{
		while (i < daysCount && prices[i] > prices[i + 1])
			i++;

		unsigned int min = prices[i];

		while (i < daysCount && prices[i] < prices[i + 1])
			i++;

		unsigned max = prices[i];
		profit += max - min;

		if (i == daysCount)
			break;
	}

	std::cout << profit;

	delete[] prices;

	return 0;
}