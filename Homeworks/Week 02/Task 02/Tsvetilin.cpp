#include <iostream>
#include <vector>
#include <algorithm>

typedef std::pair<int, std::string> dataType;
typedef std::vector<dataType> list;

bool cmpData(dataType &first, dataType &second)
{
    if (first.first == second.first)
        return first.second.compare(second.second) < 0;

    return first.first > second.first;
}

int partition(list &data, int left, int right)
{
    dataType pivot = data[right];

    int partitionIndex = left;

    for (size_t i = left; i < right; ++i)
    {
        if (cmpData(data[i], pivot))
        {
            std::swap(data[i], data[partitionIndex]);

            ++partitionIndex;
        }
    }
    std::swap(data[right], data[partitionIndex]);

    return partitionIndex;
}

void quickSort(list &data, int left, int right)
{
    if (left >= right)
        return;

    int pivotIndex = partition(data, left, right);

    quickSort(data, left, pivotIndex - 1);
    quickSort(data, pivotIndex + 1, right);
}

int main()
{
    list data;

    int n;
    std::cin >> n;

    std::string inputName;
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> inputName;
        data.push_back({0, inputName});
    }

    int inputMark;
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> inputMark;
        data[i].first = inputMark;
    }

    quickSort(data, 0, n);
    for (size_t i = 0; i < n; ++i)
    {
        std::cout << data[i].second << " " << data[i].first << "\n";
    }
}