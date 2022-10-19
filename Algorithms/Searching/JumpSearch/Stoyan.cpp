template<class T>
int jumpSearch(const T *arr, int length, const T &searched) {
    int step = sqrt(length);

    int prev = 0;
    while (arr[min(step, length) - 1] < searched) {
        if (step >= length) {
            return -1;
        }

        prev = step;
        step += sqrt(length);
    }

    while (arr[prev] < searched) {
        prev++;
        if (prev == min(step, length)){
            return -1;
        }
    }

    if (arr[prev] == searched) {
        return prev;
    }

    return -1;
}
