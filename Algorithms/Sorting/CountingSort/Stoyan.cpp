void counting_sort(int* arr, size_t arrLength) {
    int arr_copy[arrLength];

    int max = arr[0];
    for (int i = 0; i < arrLength; ++i) {
        if (max < arr[i]) {
            max = arr[i];
        }
        arr_copy[i] = arr[i];
    }

    int count[max + 1];
    for (int i = 0; i < max + 1; ++i) {
        count[i] = 0;
    }

    for (int i = 0; i < arrLength; ++i) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= max; ++i) {
        count[i] += count[i - 1];
    }

    for (int i = arrLength - 1; i >= 0; --i) {
        arr[count[arr_copy[i]] - 1] = arr_copy[i];
        count[arr_copy[i]] = count[arr_copy[i]] - 1;
    }
}
