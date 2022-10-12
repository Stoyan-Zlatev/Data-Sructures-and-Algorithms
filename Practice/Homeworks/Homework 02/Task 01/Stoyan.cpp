#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
void swap(T *p1, T *p2) {
    T temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int partition(int *arr, int first, int last) {
    int pivot = arr[last];

    int i = first;

    for (int j = first; j < last; ++j) {
        if (arr[j] < pivot) {
            swap(arr + i++, arr + j);
        }
    }

    swap(arr + i, arr + last);
    return i;
}

void quickSort(int *arr, int first, int last) {
    if (first >= last)
        return;

    int pivotIndex = partition(arr, first, last);
    quickSort(arr, first, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, last);
}

int main() {
    size_t N;
    cin >> N;

    int prices[N];
    for (int i = 0; i < N; ++i) {
        cin >> prices[i];
    }

    size_t K;
    cin >> K;

    quickSort(prices, 0, N - 1);
    long sum = 0;
    for (int i = 0; i < K; ++i) {
        sum += prices[i];
    }

    cout << sum;
    return 0;
}
