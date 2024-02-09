#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
const size_t MAX_KEYS = 1e5 + 2;

struct Cache
{
    size_t key;
    size_t value;
};

int main()
{
    size_t N, Q, K;
    cin >> N >> Q >> K;
    list<Cache> data;
    list<Cache>::iterator keys[MAX_KEYS]{};
    bool isPresent[MAX_KEYS]{};

    size_t countReq =0;
    char cmd[4];
    for (size_t i = 0; i < Q; i++)
    {
        countReq++;
        cin >> cmd;
        
        if (cmd[0] == 'p')
        {
            size_t x, y;
            cin >> x >> y;
            if (isPresent[x])
            {
                data.erase(keys[x]);
            }
            if (data.size() == N)
            {
                isPresent[data.front().key] = false;
                data.pop_front();
            }
            data.push_back({x, y});
            keys[x] = prev(data.end());
            isPresent[x] = true;
        }
        else
        {
            size_t x;
            cin >> x;
            if (!isPresent[x])
            {
                cout << -1 << '\n';
            }
            else
            {
                Cache cache = *keys[x];
                cout << cache.value << '\n';
                data.erase(keys[x]);
                data.push_back(cache);
                keys[x] = prev(data.end());
            }
        }
        if (countReq == K)
        {
            isPresent[data.front().key] = false;
            data.pop_front();
            countReq = 0;
        }
    }

    return 0;
}
