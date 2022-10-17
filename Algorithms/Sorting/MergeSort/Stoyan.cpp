template <class T>
void  merge(T* arr1, int length1, T* arr2, int length2)
{

    T* result = new T[length1 + length2];
    int cursor1=0;
    int cursor2=0;
    int resultCursor=0;

    while(cursor1 < length1 && cursor2 < length2) {
        if(arr1[cursor1] < arr2[cursor2])
            result[resultCursor++] = arr1[cursor1++];
        else
            result[resultCursor++] = arr2[cursor2++];
    }

    while(cursor1 < length1) {
        result[resultCursor++] = arr1[cursor1++];
    }

    while(cursor2 < length2) {
        result[resultCursor++] = arr2[cursor2++];
    }

    int resultLength = length1 + length2;
    for(int i = 0; i < resultLength; i++)
        arr1[i] = result[i];
    delete[] result;

}

template <class T>
void mergeSort(T* arr, int length)
{

    if(length <= 1)
        return;

    int mid = length / 2;

    mergeSort(arr, mid);
    mergeSort(arr + mid, length - mid);

    merge<T>(arr, mid, arr + mid, length - mid);
}
