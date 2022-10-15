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
