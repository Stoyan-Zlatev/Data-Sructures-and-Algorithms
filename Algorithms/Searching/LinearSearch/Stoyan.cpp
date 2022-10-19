template<class T>
int linearSearch(const T* arr, int len, const T& searched) {
    for (int i = 0; i < len; i++) {
        if (arr[i] == searched) {
            return i;
        }
    }

    return -1;
}
