template<class T>
int ternarySearch(const T *arr, int start, int end, const T &searched) {
    if (start > end) {
        return -1;
    }

    int mid1 = start + (end - start) / 3;
    int mid2 = end - (end - start) / 3;

    if (arr[mid1] == searched) {
        return mid1;
    } else if (arr[mid2] == searched) {
        return  mid2;
    }

    if (arr[mid1] > searched) {
        return ternarySearch(arr, start, mid1 - 1, searched);
    } else if (arr[mid2] < searched) {
        return ternarySearch(arr, mid2 + 1, end, searched);
    }

    return ternarySearch(arr, mid1 +1, mid2 - 1, searched);
}
