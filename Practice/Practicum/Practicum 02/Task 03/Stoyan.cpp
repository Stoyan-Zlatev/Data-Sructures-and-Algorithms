#include <iostream>
#include <vector>

size_t merge(std::vector<int> &arr, std::vector<int> &leftArr, std::vector<int> &rightArr) {
    size_t leftCount(leftArr.size()), rightCount(rightArr.size());
    size_t i(0), j(0), k(0), inv(0);

    while (i < leftCount && j < rightCount) {
        if (leftArr[i] < rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
            inv += leftCount - i;
        }
    }
    while (i < leftCount) {
        arr[k++] = leftArr[i++];
    }
    while (j < rightCount) {
        arr[k++] = rightArr[j++];
    }
    
    return inv;
}

size_t mergeSort(std::vector<int> &arr) {
    size_t n(arr.size());
    size_t mid, i, inv(0);
    if (n < 2) {
        return inv;
    }

    mid = n / 2;

    std::vector<int> leftArr(mid), rightArr(n - mid);

    for (i = 0; i < mid; i++) {
        leftArr[i] = arr[i];
    }

    for (i = mid; i < n; i++) {
        rightArr[i - mid] = arr[i];
    }

    inv += mergeSort(leftArr);
    inv += mergeSort(rightArr);
    inv += merge(arr, leftArr, rightArr);

    return inv;
}

int main() {
    size_t N;
    std::cin >> N;
    std::vector<int> buildings(N);
    for (size_t i = 0; i < N; i++) {
        std::cin >> buildings[i];
    }

    std::cout << mergeSort(buildings);

    return 0;
}
