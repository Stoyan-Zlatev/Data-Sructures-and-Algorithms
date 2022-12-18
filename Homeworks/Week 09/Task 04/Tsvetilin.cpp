#include <iostream>
#include <unordered_map>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    size_t n, m;
    std::cin >> n >> m;

    std::vector<size_t> nums(n);
    std::unordered_map<size_t, size_t> occurrences;
    std::unordered_map<size_t, std::unordered_map<size_t, size_t>> triplets;

    size_t x;
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> x;
        nums[i] = x;
    }

    size_t count = 0;

    for (long long i = n - 1; i >= 0; i--)
    {
        count += triplets[nums[i] * m][nums[i] * m * m];
        triplets[nums[i]][nums[i] * m] += occurrences[nums[i] * m];
        occurrences[nums[i]]++;
    }

    std::cout << count;

    return 0;
}