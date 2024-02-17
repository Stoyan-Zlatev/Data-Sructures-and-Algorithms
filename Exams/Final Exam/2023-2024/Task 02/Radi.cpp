#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    size_t N, x, Q;
    cin >> N;
    vector<size_t> arr;
    for (size_t i = 0; i < N; i++)
    {
        cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());
    cin >> Q;
    for (size_t i = 0; i < Q; i++)
    {
        cin >> x;
        auto it = upper_bound(arr.begin(), arr.end(), x);
        if (it == arr.end())
        {
            cout << -1 << '\n';
            continue;
        }

        size_t rightIndex = it - arr.begin();
        size_t leftIndex = rightIndex - 1;

        if (arr[rightIndex] - x <= x - arr[leftIndex])
        {
            cout << (arr[rightIndex + 1] == 0 ? -1 : (long long)arr[rightIndex + 1]) << '\n';
            continue;
        }
        cout << arr[leftIndex + 1] << '\n';
    }

    return 0;
}