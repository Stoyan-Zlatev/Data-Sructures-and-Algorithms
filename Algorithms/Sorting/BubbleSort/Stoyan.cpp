template <class T>
void swap(T* arr, int i, int j)
{
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

template <class T>
void BubbleSort(T* arr, int length)
{
    int endIndex = length - 1;

    for (int i = 0; i < length; i++)
    {
        int lastSwappedIndex = 0;

        for (int j = 0; j < endIndex; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr, j, j + 1);
                lastSwappedIndex = j;
            }
        }

        endIndex = lastSwappedIndex;
        if (lastSwappedIndex == 0)
            return;
    }
}
