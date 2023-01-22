#include <bits/stdc++.h>

using namespace std;

pair<int, int> binarySearch(const int *arr, int length, const int &searched) {
    int start = 0;
    int end = length - 1;
    int depth = 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == searched) {
            return {mid, depth};
        }

        if (arr[mid] < searched) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
        depth++;
    }

    return {-1, depth - 1};
}

int main() {
    size_t N, K, query;
    cin >> N;
    int arr[N];
    for (size_t i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    cin >> K;
    int arr1[K];
    for (int i = 0; i < K; ++i) {
        cin >> query;
        auto result = binarySearch(arr, N, query);
        cout << result.first << " ";
        arr1[i] = result.second;
    }
    cout << endl;
    for (int i = 0; i < K; ++i) {
        cout << arr1[i] << " ";
    }
}
