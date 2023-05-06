#include <iostream>
#include <vector>
#include <algorithm>

struct Tournament {
	size_t min, max;
	size_t counter = 0;
};

long long binarySearch(std::vector<size_t>& arr, size_t target) {
	size_t left = 0;
	size_t right = arr.size() - 1;

	while (left <= right) {
		// handles the case when the sum
		// of left + right > INT_MAX
		size_t mid = left + (right - left) / 2;

		if (arr[mid] == target)
			return mid;
		else if (arr[mid] > target)
			for (size_t i = left; i <= mid; i++)
			{
				if (arr[i] >= target)
					return i;
			}
		else
			left = mid + 1;
	}

	return -1;
}

int task2()
{
	int studentsCount;
	std::cin >> studentsCount;
	int tournametsCount;
	std::cin >> tournametsCount;

	std::vector<Tournament> tournaments;
	std::vector<size_t> studentsWeights;

	for (int i = 0; i < studentsCount; i++) {
		size_t weight;
		std::cin >> weight;
		studentsWeights.push_back(weight);
	}

	for (int i = 0; i < tournametsCount; i++) {
		Tournament t;
		std::cin >> t.min >> t.max;
		tournaments.push_back(t);
	}

	std::sort(studentsWeights.begin(), studentsWeights.end());

	for (int i = 0; i < tournametsCount; i++) {
		std::vector<size_t>::iterator lower, upper;
		lower = std::lower_bound(studentsWeights.begin(), studentsWeights.end(), tournaments[i].min);
		upper = std::upper_bound(studentsWeights.begin(), studentsWeights.end(), tournaments[i].max);

		if (tournaments[i].min <= tournaments[i].max) {
			tournaments[i].counter = upper - lower;
		}
	}

	for (int i = 0; i < tournametsCount; i++)
		std::cout << tournaments[i].counter << "\n";

	return 0;
}