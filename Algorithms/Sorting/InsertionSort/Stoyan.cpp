template<class T>
void swap(T *arr, int i, int j) {
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

template<class T>
void insertionSort(T *arr, int length) {
    for (int i = 1; i < length; i++) {
        T element = arr[i];
        int index = i - 1;
        while (index >= 0 && arr[index] > element) {
            arr[index + 1] = arr[index];
            index--;
        }
        
        arr[index + 1] = element;
    }
}
