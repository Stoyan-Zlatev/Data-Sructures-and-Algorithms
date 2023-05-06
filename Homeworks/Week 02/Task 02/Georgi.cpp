#include <iostream>
#include <string>
#include <vector>

struct Student {
	std::string name;
	unsigned points;
};

bool operator>(const Student& lhs, const Student& rhs) {
	if (lhs.points == rhs.points) {
		return lhs.name < rhs.name;
	}

	return lhs.points > rhs.points;
}

template <typename T>
void merge(T* arr, int l, int m, int r) {
	size_t arr1Size = m - l + 1;
	size_t arr2Size = r - m;
	T* arr1 = new T[arr1Size];
	T* arr2 = new T[arr2Size];

	for (size_t i = 0; i < arr1Size; i++)
		arr1[i] = arr[l + i];
	for (size_t i = 0; i < arr2Size; i++)
		arr2[i] = arr[m + 1 + i];

	int i = 0, j = 0, k = l;

	while (i < arr1Size && j < arr2Size)
	{
		if (arr1[i] > arr2[j])
		{
			arr[k] = arr1[i];
			i++;
		}
		else {
			arr[k] = arr2[j];
			j++;
		}
		k++;
	}

	while (i < arr1Size)
	{
		arr[k] = arr1[i];
		i++;
		k++;
	}

	while (j < arr2Size)
	{
		arr[k] = arr2[j];
		j++;
		k++;
	}

	delete[] arr1;
	delete[] arr2;
}

template <typename T>
void mergeSort(T* arr, int l, int r) {
	if (l >= r)
		return;

	int m = (l + r) / 2;
	mergeSort(arr, l, m);
	mergeSort(arr, m + 1, r);
	merge(arr, l, m, r);
}

int main()
{
	int n;
	std::cin >> n;
	Student* students = new Student[n]();
	for (size_t i = 0; i < n; i++)
		std::cin >> students[i].name;
	for (size_t i = 0; i < n; i++)
		std::cin >> students[i].points;

	mergeSort(students, 0, n - 1);

	for (size_t i = 0; i < n; i++)
		std::cout << students[i].name << " " << students[i].points << std::endl;
}