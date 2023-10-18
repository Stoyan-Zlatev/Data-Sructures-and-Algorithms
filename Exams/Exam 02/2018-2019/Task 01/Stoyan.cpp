#include <bits/stdc++.h>

using namespace std;

void mergeTwoSortedArrays(vector <size_t> &array, size_t left, size_t middle, size_t right) {
    vector<int> leftArray, rightArray;

    for (size_t i = left; i <= right; ++i) {
        if (i <= middle) {
            leftArray.push_back(array[i]);
        } else {
            rightArray.push_back(array[i]);
        }
    }

    size_t leftIndex = 0, rightIndex = 0;
    while (leftIndex < leftArray.size() && rightIndex < rightArray.size()) {
        if (leftArray[leftIndex] > rightArray[rightIndex]) {
            array[left++] = rightArray[rightIndex++];
        } else {
            array[left++] = leftArray[leftIndex++];
        }
    }

    while (leftIndex < leftArray.size()) {
        array[left++] = leftArray[leftIndex++];
    }

    while (rightIndex < rightArray.size()) {
        array[left++] = rightArray[rightIndex++];
    }

}

void mergeSort(vector <size_t> &array, size_t left, size_t right) {
    if (left >= right) {
        cout << array[left] << " ";
        return;
    }

    size_t middle = left + (right - left) / 2;

    mergeSort(array, left, middle);
    mergeSort(array, middle + 1, right);

    mergeTwoSortedArrays(array, left, middle, right);
    for (size_t i = left; i <= right; i++) {
        cout << array[i] << " ";
    }
}

int main() {
    size_t N, x;
    cin >> N;
    vector <size_t> arr;
    for (size_t i = 0; i < N; ++i) {
        cin >> x;
        arr.push_back(x);
    }
    mergeSort(arr, 0, arr.size() - 1);
    return 0;
}