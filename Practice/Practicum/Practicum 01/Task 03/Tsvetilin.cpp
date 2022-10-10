#include <iostream>
#include <algorithm>

const size_t MAX_SIZE = 1e5;
int walls[MAX_SIZE]{};
size_t max[MAX_SIZE]{};

int main()
{
    size_t n;
    std::cin >> n;

    size_t maxVol;

    for (size_t i = 0; i < n; i++)
    {
        std::cin >> walls[i];
        maxVol = 0;
        
        for (size_t j = 0; j < i; j++)
        {
            size_t vol = std::min(walls[j], walls[i]) * (i - j);
            if (vol > maxVol)
            {
                maxVol = vol;
            }
        }

        max[i] = maxVol;
    }

    size_t maxVol = max[0];
    for (size_t i = 0; i < n; i++)
    {
        if (maxVol < max[i])
        {
            maxVol = max[i];
        }
    }

    std::cout << maxVol;
}