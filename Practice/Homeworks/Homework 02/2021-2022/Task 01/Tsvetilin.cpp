#include <iostream>
#include <vector>

typedef int dataType;
typedef std::vector<dataType> list;

void merge(list &data, int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    list first(leftSize);
    list second(rightSize);

    for (size_t i = 0; i < leftSize; i++)
    {
        first[i] = data[left + i];
    }

    for (size_t i = 0; i < rightSize; i++)
    {
        second[i] = data[mid + 1 + i];
    }

    int firstIndex = 0;
    int secondIndex = 0;
    int i = left;

    while (firstIndex < leftSize && secondIndex < rightSize)
    {
        if (first[firstIndex] <= second[secondIndex])
        {
            data[i++] = first[firstIndex++];
        }
        else
        {
            data[i++] = second[secondIndex++];
        }
    }

    while (firstIndex < leftSize)
    {
        data[i++] = first[firstIndex++];
    }

    while (secondIndex < rightSize)
    {
        data[i++] = second[secondIndex++];
    }
}

void mergeSort(list &data, int left, int right)
{
    int mid = (left + right) / 2;

    if (left >= right)
        return;

    mergeSort(data, left, mid);
    mergeSort(data, mid + 1, right);
    merge(data, left, mid, right);
}

int main()
{
    int n;
    std::cin >> n;

    list data(n);
    dataType input;

    for (size_t i = 0; i < n; i++)
    {
        std::cin >> input;
        data[i] = input;
    }

    int k;
    std::cin >> k;

    mergeSort(data, 0, n - 1);

    int sum = 0;

    for (size_t i = 0; i < k; i++)
    {
        sum += data[i];
    }

    std::cout << sum << std::endl;
}
