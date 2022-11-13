#include <iostream>
#include <queue>

const size_t MAX_SIZE = 1e3 + 1;
bool arr[MAX_SIZE][MAX_SIZE]{};

int main()
{
    int n, m, t;
    std::cin >> n >> m >> t;
    std::queue<std::pair<int, int>> currentRotten;

    int x, y;

    while (std::cin >> x >> y)
    {
        currentRotten.push({x, y});
    }

    size_t count = 0;

    for (int i = 0; i < t + 1; ++i)
    {
        int toRot = currentRotten.size();

        for (int j = 0; j < toRot; ++j)
        {
            std::pair<int, int> current = currentRotten.front();
            currentRotten.pop();

            if (current.first < 1 || current.first > n || current.second < 1 || current.second > m)
            {
                continue;
            }

            if (arr[current.first][current.second])
            {
                continue;
            }

            arr[current.first][current.second] = true;
            ++count;

            currentRotten.push({current.first, current.second - 1});
            currentRotten.push({current.first, current.second + 1});
            currentRotten.push({current.first - 1, current.second});
            currentRotten.push({current.first + 1, current.second});
        }
    }
    
    std::cout << m * n - count;
    return 0;
}