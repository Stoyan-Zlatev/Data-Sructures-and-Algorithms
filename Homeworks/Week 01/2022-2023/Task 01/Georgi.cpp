#include <iostream>
#include <cstring>

int task1()
{
	unsigned short listsCount;
	std::cin >> listsCount;

	char** lists = new char* [listsCount];

	for (size_t i = 0; i < listsCount; i++)
	{
		unsigned int currentListLength;
		std::cin >> currentListLength;
		lists[i] = new char[currentListLength + 1];

		std::cin >> lists[i];
	}

	for (size_t i = 0; i < listsCount; i++)
	{
		unsigned int length = strlen(lists[i]);
		unsigned int count = 0;
		for (size_t j = 0; j < length - 1; j++) {
			if (lists[i][j] == lists[i][j + 1])
				count++;
		}

		std::cout << count << std::endl;
	}


	for (size_t i = 0; i < listsCount; i++)
		delete[] lists[i];

	delete[] lists;

	return 0;
}