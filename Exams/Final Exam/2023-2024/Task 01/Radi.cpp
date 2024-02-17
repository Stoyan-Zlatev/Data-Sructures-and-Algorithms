#include <bits/stdc++.h>
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    size_t N;
    cin >> N;
    string s;
    for (size_t i = 0; i < N; i++)
    {
        cin >> s;
        unordered_map<char, size_t> um1;
        unordered_map<size_t, size_t> um2;
        for (size_t j = 0; j < s.size(); j++)
        {
            um1[s[j]]++;
        }
        for (auto &iter : um1)
        {
            um2[iter.second]++;
        }
        if (um2.size() >= 3)
        {
            cout << 0 << endl;
        }
        else if (um2.size() == 1)
        {
            vector<pair<size_t, size_t>> counters;
            for (auto &iter : um2)
            {
                counters.push_back(iter);
            }
            if (counters[0].second != 1)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << (counters[0].first > 0) << endl;
            }
        }
        else
        {
            vector<pair<size_t, size_t>> counters;
            for (auto &iter : um2)
            {
                counters.push_back(iter);
            }
            if (counters[0].second == 1 && counters[1].second == 1)
            {
                if (counters[0].first == 1 || counters[1].first == 1)
                {
                    cout << 1 << endl;
                }
                else
                {
                    // cout<<"love for ceci"<<endl;
                    cout << (max(counters[0].first, counters[1].first) - min(counters[0].first, counters[1].first) == 1) << endl;
                }
            }
            else if (counters[0].second == 1)
            {
                cout << (counters[0].first == counters[1].first + 1) << endl;
            }
            else if (counters[1].second == 1)
            {
                cout << (counters[1].first == counters[0].first + 1) << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
    }

    return 0;
}