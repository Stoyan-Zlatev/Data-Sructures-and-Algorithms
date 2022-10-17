template<typename T>
void swap(T *p1, T *p2) {
    T temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

template<typename T>
int partition(T *arr, int first, int last) {
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

template<typename T>
void quickSort(T *arr, int first, int last) {
    if (first >= last)
        return;

    int pivotIndex = partition(arr, first, last);
    quickSort(arr, first, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, last);
}
