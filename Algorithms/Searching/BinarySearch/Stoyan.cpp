// Recursive
template<class T>
int binarySearch(const T *arr, int start, int end, const T &searched) {
    if (start > end) {
        return -1;
    }

    int mid = start + (end - start) / 2;
    if (arr[mid] == searched) {
        return mid;
    } else if (arr[mid] < searched) {
        binarySearch(arr, mid + 1, end, searched);
    } else {
        binarySearch(arr, start, mid - 1, searched);
    }
}

//Iterative
template<class T>
int binarySearch(const T *arr, int length, const T &searched) {
    int start = 0;
    int end = length - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == searched) {
            return mid;
        } 
        
        if (arr[mid] < searched) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
}
