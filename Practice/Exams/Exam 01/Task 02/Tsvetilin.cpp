#include <vector>
#include <iostream>
#include <algorithm>

// id xi yi
typedef std::pair<int, std::pair<int, int>> dataType;
typedef std::vector<dataType> list;

bool cmpData(dataType &first, dataType &second)
{
    double firstPoints = first.second.first * first.second.first / first.second.second;
    double secondPoints = second.second.first * second.second.first / second.second.second;

    return firstPoints > secondPoints || (firstPoints == secondPoints && first.second.first > second.second.first);
}

int main()
{
    int n;
    std::cin >> n;

    list data(n);
    for (int i = 0; i < n; ++i)
    {
        data[i].first = i + 1;

        std::cin >> data[i].second.first;
        std::cin >> data[i].second.second;
    }

    std::sort(data.begin(), data.end(), cmpData);

    for (int i = 0; i < n; ++i)
    {
        std::cout << data[i].first << " ";
    }
    return 0;
}
